#include <string>
#include <vector>
#include "BBoard.h"
#include <fstream>
#include <iostream>

using namespace std;

BBoard::BBoard(){
    title = "default";
}

BBoard::BBoard(const string &t){
    title = t;
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
        userList.push_back(temp);
        fin >> usern;
    }
    fin.close();
    return true;
}

bool BBoard::login(){
    string inputu;
    string inputp;
    bool isValid = false;
    cout << "Welcome to " << title << endl;
    cout << "Enter your username ('Q' or 'q' to quit): " ;
    cin >> inputu;
    cout <<  endl;
    if (inputu == "Q" || inputu == "q"){
        cout << "Bye!" << endl;
        return false;
    }
    cout << "Enter your password: ";
    cin >> inputp;
    cout << endl;
    for (unsigned int i = 0; i < userList.size(); ++i){
        if (userList.at(i).check(inputu, inputp)){
            currentUser = userList.at(i);
            cout << "Welcome back " << inputu << "!" << endl;
            return true;
        }
    }
    
    cout << "Invalid Username or Password!" << endl;
    cout << endl;
    
    while (isValid == false){
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> inputu;
        cout << endl;
        if (inputu == "Q" || inputu == "q"){
            cout << "Bye!" << endl;
            return false;
        }
        cout << "Enter your password: ";
        cin >> inputp;
        cout << endl;
        for (unsigned int i = 0; i < userList.size(); ++i){
            if (userList.at(i).check(inputu, inputp)){
                currentUser = userList.at(i);
                cout << "Welcome back " << inputu << "!" << endl;
                return true;
                isValid = true;
            }
        }
        cout << "Invalid Username or Password!" << endl;
    }
    return false;
}

void BBoard::display() const{
    cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Add New Message ('N' or 'n')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl << "Choose an action: " << endl;
}

bool BBoard::userExists(const string &usern, const string &passw) const{
    if(currentUser.check(usern, passw)){
        return false;
    }
    return true;
}

void BBoard::run(){
    string input;
    bool notQ = true;
    if(!userExists("","")){
        exit(1);
    }
    cout << endl;
    display();
    cin >> input;
    //cout << endl;
    while(notQ){
        if (input == "Q" || input == "q"){
            cout << "Bye!" << endl;
            exit(1);
            notQ = false;
        }
        else if (input == "D" || input == "d"){
            if (messageList.size() == 0){
                cout << "Nothing to Display." << endl;
                cout << endl;
            }
            else{
                for (unsigned i = 0; i < messageList.size(); ++i){
                    cout << "---------------------------------------------------------" << endl;
                    cout << "Message #" << i + 1 << ": ";
                    messageList.at(i).display();
                }
                cout << "---------------------------------------------------------" << endl;
                cout << endl;
            }
        }
        else if (input == "N" || input == "n"){
            string subject;
            string body;
            cout << "Enter Subject: ";
            cin.ignore();
            getline(cin, subject);
            cout << endl;
            cout << "Enter Body: ";
            getline(cin, body);
            cout << endl;
            messageList.push_back(Message(currentUser.getUsername(), subject, body));
            cout << "Message Recorded!" << endl << endl;
        }
        display();
        cin >> input;
    }
}