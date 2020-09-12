#include <iostream>

using namespace std;

#include "Distance.h"

int main(){
    Distance test = Distance(5, 7.01);
    Distance test2 = Distance(2, 7.8);
    Distance test3;
    
    test3 = test + test2;
    cout << test3 << endl;
    
    return 0;
}