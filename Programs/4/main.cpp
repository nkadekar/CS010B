#include "IntVector.h"
#include <iostream>

using namespace std;

int main(){
    
    IntVector test1;
    IntVector test2(5, 0);
    IntVector test3(20);
    
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
    
    //testing front and back functions(tested both of each by commenting out the other)
    cout << test1.front() << endl; //should give error(comment out to test others)
    cout << test1.back() << endl; //should give error(comment out to test others)
    cout << "test2 front: " << test2.front() << endl;
    cout << "test2 back: " << test2.back() << endl;
    cout << "test3 front: " << test3.front() << endl;
    cout << "test3 back: " << test3.back() << endl;
    
    //testing changing the vector(testing new at function)
    cout << "After Changing Vector" << endl << "test2:";
    for (unsigned int i = 0; i < test2.size(); i++){
        test2.at(i) = i;
    }
    for (unsigned int i = 0; i < test2.size(); i++){
        cout << test2.at(i);
    }
    cout << endl;
    cout << "test3:";
    for (unsigned int i = 0; i < test3.size(); i++){
        test3.at(i) = i;
        cout << test3.at(i);
    }
    cout << endl;
    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i);
    }
    cout << endl;
    
    //testing both expand functions through test function
    cout << "Before Expand" << endl;
    cout << "sz:" << test3.size() << endl;
    cout << "cap:" << test3.capacity() << endl;
    /* test3.test(); //commented out in cpp and h files */
    cout << endl << "After Expand" << endl;
    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i);
    }
    cout << endl;
    cout << "test3: " << endl;
    cout << "sz:" << test3.size() << endl;
    cout << "cap:" << test3.capacity() << endl;
       
    //testing insert function
    test3.insert(-1, 9);
    cout << "after insert:";
    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i);
    }
    cout << endl;
     
    //testing pushback function
    test3.push_back(9);
    cout << "after pushback:";
    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i);
    }
    cout << endl;
    
    //testing popback
    cout << "before popback:" << endl;
    cout << "test3:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    test3.pop_back();
    cout << "after:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    
    //testing clear
    cout << "before clear:" << endl;
    cout << "test3:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    test3.clear();
    cout << "after:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    
    
    //testing resize function
    cout << "before resize:" << endl;
    cout << "test3:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    cout << "test3:";
    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i);
    }
    cout << endl;
    test3.resize(25);//tested different values for this
    cout << "after:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    cout << "test3:";
    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i);
    }
    cout << endl;
    
    //testing reserve
    cout << "before reserve:" << endl;
    cout << "test3:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    test3.reserve(50);
    cout << "after:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    
    //testing assign function
    cout << "before assign:" << endl;
    cout << "test3:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    cout << "test3:";
    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i);
    }
    cout << endl;
    test3.assign(25, 3); //tested different values for this
    cout << "after:" << endl;
    cout << "size: " << test3.size() << endl;
    cout << "capacity: " << test3.capacity() << endl;
    cout << "test3:";
    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i);
    }
    cout << endl;
    
    return 0;
}