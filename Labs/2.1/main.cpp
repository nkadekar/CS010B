#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

//fileSum prototype (declaration)
int fileSum(const string &);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

//fileSum implementation
int fileSum(const string& filename){
    
    fstream fin;
    fin.open(filename);
    int sum = 0;
    int input;
    if (!fin.is_open()){
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    else{
        while(fin >> input){
            sum += input;
        }
    }
    fin.close();
    return sum;
}