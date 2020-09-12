#include "IntVector.h"
#include <iostream>

using namespace std;

int main(){
    
    IntVector test1;
    IntVector test2(5, 0);
    IntVector test3(3);
    
    //testing default constructor (also testing size, capacity, and empty)
    cout << "test1:" << endl;
    cout << "size: " << test1.size() << endl;
    cout << "capacity: " << test1.capacity() << endl;
    cout << "empty(1 means yes and 0 means no): " << test1.empty() << endl;
    
    //testing other contructor (also testing size, capacity, and empty)
    cout << "test2:" << endl;
    cout << "size: " << test2.size() << endl;
    cout << "capacity: " << test2.capacity() << endl;
    cout << "empty(1 means yes and 0 means no): " << test2.empty() << endl;
    
    cout << "test3:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    cout << "empty(1 means yes and 0 means no): " << test3.empty() << endl;
    
    //testing at function
    cout << "test1: ";
    for (unsigned int i = 0; i < test1.size(); i++){
        cout << test1.at(i);
    }
    cout << endl;
    
    cout << "test2: ";
    for (unsigned int i = 0; i < test2.size(); i++){
        cout << test2.at(i);
    }
    cout << endl;
    
    cout << "test3: ";
    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i);
    }
    cout << endl;
    
    //testing front and back functions
    //cout << test1.front() << endl; //should give error(comment out to test others)
    //cout << test1.back() << endl; //should give error(comment out to test others)
    cout << "test2 front: " << test2.front() << endl;
    cout << "test2 back: " << test2.back() << endl;
    cout << "test3 front: " << test3.front() << endl;
    cout << "test3 back: " << test3.back() << endl;
    
    return 0;
}