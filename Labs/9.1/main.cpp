#include <iostream>
#include <string>

using namespace std;

void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//OPTION 1
// void flipString(string &s){
//     if (s.size() == 0){
//         return;
//     }
//     else{
//         string temp = s.substr(0, s.size() - 1);
//         flipString(temp);
//         s = s.back() + temp;
//     }
// } 

//OPTION 2
void flipString(string &s){
    if (s.size() <= 1){
        return;
    }
    else{
        string temp = s.substr(1, s.size() - 2);
        flipString(temp);
        s = s.back() + temp + s.front();
    }
}