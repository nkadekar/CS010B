#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "BBoard.h"

using namespace std;

BBoard::BBoard(){
    title = "default";
    current_user = nullptr;
}

BBoard::BBoard(const string &t){
    title = t;
    current_user = nullptr;
}

BBoard::~BBoard(){
    for (unsigned i = 0; i < message_list.size(); i++) {
        delete message_list.at(i);
    }
}

bool BBoard::loadUsers(const string &filename){
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open()){
        return false;
    }
    string usern;
    string passw;
    fin >> usern;
    while (usern != "end"){
        fin >> passw;
        User temp(usern, passw);
        user_list.push_back(temp);
        fin >> usern;
    }
    fin.close();
    return true;
}

bool BBoard::loadMessages(const string & filename){
    vector<int> ids;
    vector<string> children;
    unsigned numMessages = 0;
    string line;
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open()){
        return false;
    }
    fin >> numMessages;
    if(numMessages == 0){
        return true;
    }
    fin.ignore();
    for(unsigned int i = 0; i < numMessages; ++i){
        getline(fin, line);
        if(line == "<begin_topic>"){
            unsigned id = 0;
            string subject;
            string author;
            string child;
            string tempBody;
            string body;
            string temp;
            fin >> temp;
            if(temp == ":id:"){
                fin >> id;
            }
            fin >> subject;
            if (subject == ":subject:"){
                getline(fin, subject);
                subject = subject.substr(1);
            }
            fin >> author;
            if(author == ":from:"){
                getline(fin, author);
                author = author.substr(1);
            }
            fin >> temp;
            if(temp == ":children:"){
                getline(fin, child);
                ids.push_back(id);
                children.push_back(child);
                fin >> temp;
            }
            if(temp == ":body:"){
                fin.ignore();
                getline(fin, tempBody);
                ostringstream oSS;
                while(tempBody != "<end>"){
                    tempBody += "\n";
                    oSS << tempBody;
                    getline(fin, tempBody);
                }
                body = oSS.str();
                body = body.substr(0, body.size() - 1);
            }
            Topic * newTopic = new Topic(author, subject, body, id);
            message_list.push_back(newTopic);
        }
        else if (line == "<begin_reply>") {
            unsigned id = 0;
            string subject;
            string author;
            string child;
            string tempBody;
            string body;
            string temp;
            fin >> temp;
            if(temp == ":id:"){
                fin >> id;
            }
            fin >> subject;
            if (subject == ":subject:"){
                fin.ignore();
                getline(fin, subject);
            }
            fin >> author;
            if(author == ":from:"){
                fin.ignore();
                getline(fin, author);
            }
            fin >> temp;
            if(temp == ":children:"){
                getline(fin, child);
                ids.push_back(id);
                children.push_back(child);
                fin >> temp;
            }
            if(temp == ":body:"){
                fin.ignore();
                getline(fin, tempBody);
                ostringstream oSS;
                while(tempBody != "<end>"){
                    tempBody += "\n";
                    oSS << tempBody;
                    getline(fin, tempBody);
                }
                body = oSS.str();
                body = body.substr(0, body.size() - 1);
            }
            Reply * newReply = new Reply(author, subject, body, id);
            message_list.push_back(newReply);
        }
        else{
            cout << "Error with message format" << endl;
            return false;
        }
    }
    parseChildren(ids, children); 
    return true;
}

bool BBoard::saveMessages(const string & outputFile){
    ofstream fout;
    fout.open(outputFile);
    if (!fout.is_open()){
        cout << "Error opening file: " << outputFile << endl;
        return false;
    }
    string formatted;
    fout << message_list.size() << endl;
    for (unsigned int i = 0; i < message_list.size(); ++i){
        formatted = message_list.at(i)->toFormattedString();
        fout << formatted;
    }
    fout.close();
    return true;
}

void BBoard::login(){
    string inputu;
    string inputp;
    cout << "Welcome to " << title << endl;
    cout << "Enter your username ('Q' or 'q' to quit): ";
    cin >> inputu;
    //cout << endl;
    if (inputu == "Q" || inputu == "q"){
        cout << "Bye!" << endl;
        return;// false;
    }
    cout << "Enter your password: ";
    cin >> inputp;
    const User* checkUser = getUser(inputu, inputp);
    while (checkUser == nullptr){
        cout << "Invalid Username or Password!";
        cout << endl;
        cout << endl;
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> inputu;
        if (inputu == "Q" || inputu == "q"){
            cout << "Bye!" << endl;
            return;
        }
        cout << "Enter your password: ";
        cin >> inputp;
        checkUser = getUser(inputu, inputp);
    }
    cout << endl;
    cout << "Welcome back " << inputu << "!" << endl;
    current_user = checkUser;
}

void BBoard::displayMenu() const{
    cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Add New Topic ('N' or 'n')" << endl;
    cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
}

void BBoard::run(){
    if(current_user == nullptr){
        return;
    }
    else{
        string input;
        bool notQ = true;
        cout << endl;
        displayMenu();
        cin >> input;
        while(notQ){
            if (input == "Q" || input == "q"){
                cout << "Bye!" << endl;
                return;
            }
            else if (input == "D" || input == "d"){
                if (message_list.size() == 0){
                    cout << endl;
                    cout << "Nothing to Display." << endl;
                    cout << endl;
                }
                else{
                    display();
                }
            }
            else if (input == "N" || input == "n"){
                addTopic();
                cout << endl;
            }
            else if (input == "R" || input == "r"){
                addReply();
                cout << endl;
            }
            displayMenu();
            cin >> input;
        }
    }
}

void BBoard::addTopic(){
    cin.ignore();
    string subject;
    string tempBody;
    string body;
    unsigned id = message_list.size() + 1;
    cout << "Enter Subject: ";
    getline(cin, subject);
    cout << "Enter Body: ";
    getline(cin, tempBody);
    ostringstream oSS;
    while(tempBody != ""){
        tempBody += "\n";
        oSS << tempBody;
        getline(cin, tempBody);
    }
    body = oSS.str();
    body = body.substr(0, body.size() - 1);
    Topic * newTopic = new Topic(current_user->getUsername(), subject, body, id);
    message_list.push_back(newTopic);
}

void BBoard::addReply(){
    cin.ignore();
    string subject;
    string tempBody;
    string body;
    int topicId = 0;
    unsigned id = message_list.size() + 1;
    cout << "Enter Message ID (-1 for Menu): ";
    cin >> topicId;
    if (topicId == -1){
        return;
    }
    while (topicId < -1 || topicId == 0 || topicId > static_cast<int>(id)){
        cout << "Invalid Message ID!!" << endl;
        cout << endl;
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> topicId;
    }
    cout << endl;
    cin.ignore();
    cin.clear();
    cout << "Enter Body: ";
    getline(cin, tempBody);
    ostringstream oSS;
    while(tempBody != ""){
        tempBody += "\n";
        oSS << tempBody;
        getline(cin, tempBody);
    }
    body = oSS.str();
    body = body.substr(0, body.size() - 1);
    subject = "Re: " + message_list.at(topicId - 1)->getSubject();
    Reply * newReply = new Reply(current_user->getUsername(), subject, body, id);
    message_list.push_back(newReply);
    message_list.at(topicId - 1)->addChild(newReply);
}

const User * BBoard::getUser(const string &user, const string &pw) const{
    for (unsigned int i = 0; i < user_list.size(); ++i){
            if (user_list.at(i).check(user, pw)){
                const User * ptr = &user_list.at(i);
                return ptr;
            }
    }
    return nullptr;
}

void BBoard::display() const{
    cout << endl;
    for (unsigned int i = 0; i < message_list.size(); ++i){
        if (message_list.at(i)->isReply() != true){
            message_list.at(i)->print(0);
        }
    }
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

void BBoard::parseChildren(vector<int> & ids, vector<string> & children){
    istringstream inSS;
    for (unsigned int i = 0; i < ids.size(); ++i){
        int childID = 0;
        unsigned id = ids.at(i);

        inSS.str(children.at(i));
        while (inSS >> childID){
            this->message_list.at(id - 1)->addChild(this->message_list.at(childID - 1));
        }
        inSS.clear();
    }
}