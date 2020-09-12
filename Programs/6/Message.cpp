#include <string>
#include <sstream>
#include <vector>
#include "Message.h"
#include <iostream>

using namespace std;

Message::Message(){
    author = "default";
    subject = "default";
    body = "default";
    id = 0;
}

Message::Message(const string & author, const string & subject, 
                 const string & body, unsigned id){
    this->author = author;
    this->subject = subject;
    this->body = body;
    this->id = id;
}

Message::~Message(){
}

void Message::print(unsigned ind) const {
    cout << "---------------------------------------------------------" << endl;
    cout << "Message #" << id << ": " << subject << endl;
    cout << "from " << author << ": " << body;
    for (unsigned i = 0; i < childList.size(); i++) {
        cout << endl;
        childList.at(i)->helper(ind + 1);
    }
    cout << endl;
}
    
const string & Message::getSubject() const{
    return subject;
}
    
unsigned Message::getID() const{
    return id;
}

void Message::addChild(Message * msg){
    childList.push_back(msg);
}

void Message::helper(unsigned ind) const {
    cout << endl;
    for (unsigned j = 0; j < ind; j++) {
        cout << "  ";
    }
    cout << "Message #" << id << ": " << subject << endl;
    for (unsigned j = 0; j < ind; j++) {
        cout << "  ";
    }
    cout << "from " << author << ": ";
    for (unsigned j = 0; j < body.size(); j++) {
        cout << body.at(j);
        if (body.at(j) == '\n') {
            for (unsigned k = 0; k < ind; k++) {
                cout << "  ";
            }
        }
    }

    for (unsigned i = 0; i < childList.size(); i++) {
        cout << endl;
        childList.at(i)->helper(ind + 1);
    }
}