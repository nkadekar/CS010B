//User.cpp

#include <string>
#include "User.h"

using namespace std;

User::User(){
    username = "";
    password = "";
}

User::User(const string& uname, const string& pass){
    username = uname;
    password = pass;
}

string User::getUsername() const{
    return username;
}

// //ONLY FOR TESTING PURPOSES
// string User::getPassword() const{
//     return password;
}

bool User::check(const string &uname, const string &pass) const{
    if(uname == ""){
        return false;
    }
    else if(username == uname && password == pass){
        return true;
    }
    else {
        return false;
    }
}

bool User::setPassword(const string &oldpass, const string &newpass){
    if (username == ""){
        return false;
    }
    else if (password == oldpass){
        password = newpass;
        return true;
    }
    else{
        return false;
    }
}