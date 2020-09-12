#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
   
   string inputFile;
   string outputFile;
   string input;
   vector<int> inputInts;
   
    //Assigning to inputFile value of 2nd command line argument
    inputFile  = argv[1];

    // Assigning to outputFile value of 3rd command line argument
    outputFile = argv[2];
    
   // Creating input stream and open input csv file.
    ifstream fin;
    fin.open(inputFile);
   
   // Verifying file opened correctly.
   // Outputing error message and returning 1 if file stream did not open correctly.
     if(!fin.is_open()){
         cout << "Error: File didn't open." << endl;
         return 1;
     }
   
   // Reading in integers from input file to vector.
    
    while(getline(fin, input)){
       
    }    
    
    for (unsigned int i = 0; i < input.size(); ++i){
        if(input.at(i) == ','){
            input.at(i) = ' ';
        }
    }
    
    istringstream inSS(input);
    int stringInt;
    
    while(inSS >> stringInt){
        inputInts.push_back(stringInt);
    }
    
   // Closing input stream.
    fin.close();
   
   // Getting integer average of all values read in.
    int sum = 0;
    int avg;
    
    for (unsigned int i = 0; i < inputInts.size(); ++i){
        sum += inputInts.at(i);
    }
    
    avg = sum/inputInts.size();
   
   // Converting each value within vector to be the difference between the original value and the average.
    for (unsigned int i = 0; i < inputInts.size(); ++i){
        inputInts.at(i) = inputInts.at(i) - avg;
    }
   
   // Create output stream and open/create output csv file.
    
    ofstream fout;
    fout.open(outputFile);
    
    ostringstream outSS;
    
   // Verifying file opened or was created correctly.
   // Outputing error message and returning 1 if file stream did not open correctly.
    if(!fout.is_open()){
         cout << "Error: File didn't open." << endl;
         return 1;
     }

    // Writing converted values into output csv file, each integer separated by a comma.
    string output;
    for (unsigned int i = 0; i < inputInts.size()-1; ++i){
        outSS << inputInts.at(i) << ',';
    }
    
    outSS << inputInts.at(inputInts.size()-1);
    
    output = outSS.str();
    
    cout << output << endl;
    
    fout << output;
   
    //Closing output stream.
    fout.close();
    
   return 0;
}