#include <sstream>
#include <string>
#include "Reply.h"

using namespace std;

Reply::Reply()
    :Message(){}

Reply::Reply(const string & a, 
             const string & s, 
             const string & b, 
             unsigned i)
    :Message(a, s, b, i){}

bool Reply::isReply() const{
    return 1;
}

string Reply::toFormattedString() const{
    string output;
    stringstream oSS;
    oSS << "<begin_reply>\n";
    oSS << ":id: " << id << "\n:subject: " << subject << "\n:from: " << author;
    if (childList.size() > 0){
        oSS << "\n:children: ";
        for (unsigned int i = 0; i < childList.size(); ++i){
            oSS << childList.at(i)->getID();
            if(i != childList.size() - 1){
                oSS << " ";
            }
        }
    }
    oSS << "\n:body: " << body << "\n<end>\n";
    output = oSS.str();
    return output;
}