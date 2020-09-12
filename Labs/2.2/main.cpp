#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

//charCnt prototype (declaration)
int charCnt(const string&, char);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

//charCnt implementation
int charCnt(const string& filename, char input){
    char x;
    int counter = 0;
    fstream fin;
    fin.open(filename);
    if (!fin.is_open()){
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    else{
        while(fin.get(x)){
            if (input == x){
                counter++;
            }
        }
    }
    return counter;
}