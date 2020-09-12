#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



//FUNCTION DECLARATIONS
void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);
double findMinVal(const vector<double> &);
double findMaxVal(const vector<double> &);
int getMinLoc(const vector<double> &);
int getMaxLoc(const vector<double> &);
bool doesValExist(const vector<double> &, double);
void run(double, const vector<double> &, const vector<double> &);
void createMinVecAC(double value, const vector<double> & angles, const vector<double> & coefs, vector<double> & minVecA, vector<double> & minVecC);
void createMaxVecAC(double, const vector<double> &, const vector<double> &, vector<double> &, vector<double> &);



//MAIN

int main(int argc, char* argv[]){
    
    string filename;
    vector<double> angles;
    vector<double> coefs;
    double inputValue;
    string inputString;
    
    filename = argv[1];
    
    readData(filename, angles, coefs);
    
    if (!(isOrdered(angles))){
        reorder(angles, coefs);
    }
    
    cout << "Enter a flight angle: " << endl;
    cin >> inputValue;
    
    if ((inputValue >= findMinVal(angles)) && (inputValue <= findMaxVal(angles))){
        //run(inputValue, angles, coefs);
        cout << interpolation(inputValue, angles, coefs) << endl;
    }
    else {
        cout << "Out of bounds" << endl;
    }
    
    cout << "Would you like to enter another flight angle?" << endl;
    cin >> inputString;
    
    while ((inputString == "Yes") || (inputString == "yes")){
        
        cout << "Enter a flight angle: " << endl;
        cin >> inputValue;
    
        if ((inputValue >= findMinVal(angles)) && (inputValue <= findMaxVal(angles))){
            //run(inputValue, angles, coefs);
            cout << interpolation(inputValue, angles, coefs) << endl;
        }
        else {
            cout << "Out of bounds" << endl;
        }
        cout << "Would you like to enter another flight angle?" << endl;
        cin >> inputString;
        
    }
    
    return 0;
}



//FUNCTIONS
double findMinVal(const vector<double> & v1){
    
    double min;
    min = v1.at(0);
    for (unsigned int i = 0; i < v1.size(); ++i){
        if (v1.at(i) < min){
            min = v1.at(i);
        }
    }
    
    return min; 
}

double findMaxVal(const vector<double> & v1){
    
    double max;
    max = v1.at(0);
    for (unsigned int i = 0; i < v1.size(); ++i){
        if (v1.at(i) > max){
            max = v1.at(i);
        }
    }
    
    return max; 
}

int getMinLoc(const vector<double> & v1, int start){
    
    double min;
    int loc = start;
    min = v1.at(start);
    for (unsigned int i = start + 1; i < v1.size(); ++i){
        if (v1.at(i) < min){
            min = v1.at(i);
            loc = i;
        }
    }
    
    return loc;
}

int getMaxLoc(const vector<double> & v1, int start){
    
    double max;
    int loc = start;
    max = v1.at(start);
    for (unsigned int i = start + 1; i < v1.size(); ++i){
        if (v1.at(i) > max){
            max = v1.at(i);
            loc = i;
        }
    }
    
    return loc;
}

void readData(const string & filename, vector<double> & angles, vector<double> & coefs){
    
    ifstream fin;
    fin.open(filename);
    double angleInput;
    double coefInput;
    
    if(!fin.is_open()){
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    
    while (fin >> angleInput >> coefInput){
        angles.push_back(angleInput);
        coefs.push_back(coefInput);
    }
    
    fin.close();
}

bool isOrdered(const vector<double> & v1){
    
    for (unsigned int i = 1; i < v1.size(); ++i){
        if (v1.at(i) < v1.at(i - 1)){
            return false;
        }
    }
    
    return true;
}

void reorder(vector<double> & v1, vector<double> & v2){
    
    int minLoc;
    for (unsigned int i = 0; i < v1.size(); ++i){

        minLoc = getMinLoc(v1, i);
        swap(v1.at(i), v1.at(minLoc));
        swap(v2.at(i), v2.at(minLoc));

    }
 
}

bool doesValExist(const vector<double> & v1, double value){
    
    for (unsigned int i = 0; i < v1.size(); ++i){
        if (value == v1.at(i)){
            return true;
        }
    }
    
    return false;
}

//LINEAR INTERPOLATION
// f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))

double interpolation(double value, const vector<double> & angles, const vector<double> & coefs){
    
    vector<double> minVecA;
    vector<double> maxVecA;
    vector<double> minVecC;
    vector<double> maxVecC;
    double a;
    double c;
    double fa;
    double fb;
    double fc;
    double output;
    if (doesValExist(angles, value)){
            for (unsigned int i = 0; i < angles.size(); ++i){
                if (angles.at(i) == value){
                    output = coefs.at(i);
                }
            }
    }
    else {
        createMinVecAC(value, angles, coefs, minVecA, minVecC);   
        a = findMaxVal(minVecA);
        fa = minVecC.at(getMaxLoc(minVecA, 0));
        createMaxVecAC(value, angles, coefs, maxVecA, maxVecC);
        c = findMinVal(maxVecA);
        fc = maxVecC.at(getMinLoc(maxVecA, 0));
        fb = fa + ((value - a)/(c - a))*(fc - fa);
        output = fb;
    }
    
    return output;
}

void createMinVecAC(double value, const vector<double> & angles, const vector<double> & coefs, vector<double> & minVecA, vector<double> & minVecC){
    
        //For finding numbers below inputed value
        for (unsigned int i = 0; i < angles.size(); ++i){
            if (value > angles.at(i)){
                minVecA.push_back(angles.at(i));
                minVecC.push_back(coefs.at(i));
            }
        }
    
}

void createMaxVecAC(double value, const vector<double> & angles, const vector<double> & coefs, vector<double> & maxVecA, vector<double> & maxVecC){
    
        for (unsigned int i = 0; i < angles.size(); ++i){
            if (value < angles.at(i)){
                maxVecA.push_back(angles.at(i));
                maxVecC.push_back(coefs.at(i));
            }
        }
    
}