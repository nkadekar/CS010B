#include <string>
#include <iostream>
#include "Message.h"

using namespace std;

Message::Message(){
    author = "";
    subject = "";
    body = "";
}

Message::Message(const string &athr, const string &sbjct, const string &body){
    author = athr;
    subject = sbjct;
    this->body = body;
}

void Message::display() const{
    cout << subject << endl << "from " << author << ": " << body << endl;
}