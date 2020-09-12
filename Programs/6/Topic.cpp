#include <sstream>
#include <string>
#include "Topic.h"

using namespace std;

Topic::Topic()
    :Message(){}

Topic::Topic(const string & a, 
             const string & s, 
             const string & b, 
             unsigned i)
    :Message(a, s, b, i){}

bool Topic::isReply() const{
    return 0;
}

string Topic::toFormattedString() const{
    string output;
    stringstream oSS;
    oSS << "<begin_topic>\n";
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