#include "IntVector.h"
#include <stdexcept>
#include <iostream>

using namespace std;

IntVector::IntVector(){
    sz = 0;
    cap = 0;
    data = nullptr;
}

IntVector::IntVector(unsigned size, int value){
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned int i = 0; i < size; i++){
        data[i] = value;
    }
}

IntVector::~IntVector(){}

unsigned IntVector::size() const{
    return sz;
}

unsigned IntVector::capacity() const{
    return cap;
}

bool IntVector::empty() const{
    return (sz == 0);
}

const int & IntVector::at(unsigned index) const{
    if (index >= sz){
        throw out_of_range("IntVector::at_range_check"); 
    }
    else {
        return data[index];
    }
}

const int & IntVector::front() const{
    if (empty()){
        throw out_of_range("IntVector::at_range_check");
    }
    return data[0];
}

const int & IntVector::back() const{
    if (empty()){
        throw out_of_range("IntVector::at_range_check");
    }
    return data[sz - 1];
}