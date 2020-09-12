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

IntVector::~IntVector(){
    delete[] data;
}

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

int & IntVector::at(unsigned index){
    if (index >= sz){
        throw out_of_range("IntVector::at_range_check"); 
    }
    else {
        return data[index];
    }
}

const int & IntVector::front() const{
    if (empty()){
        throw out_of_range("IntVector::front_range_check");
    }
    return data[0];
}

int & IntVector::front(){
    if (empty()){
        throw out_of_range("IntVector::front_range_check");
    }
    return data[0];
}

const int & IntVector::back() const{
    if (empty()){
        throw out_of_range("IntVector::back_range_check");
    }
    return data[sz - 1];
}

int & IntVector::back(){
    if (empty()){
        throw out_of_range("IntVector::back_range_check");
    }
    return data[sz - 1];
}

void IntVector::insert(unsigned index, int value){
    if (index > sz){
         throw out_of_range("IntVector::insert_range_check");
    }
    if (sz == cap){
        expand();
    }
    sz++;
    if (index == sz - 1){
        data[sz - 1] = value;
    }
    else {
        for (unsigned int i = sz - 1; i > index; --i){
            data[i] = data[i - 1];
        }
        data[index] = value;
    }
}

void IntVector::erase(unsigned index){
    if (index >= sz){
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned int i = index; i < sz - 1; ++i){
        data[i] = data[i + 1];
    }
    sz--;
}

void IntVector::assign(unsigned n, int value){
    if (n <= sz){
        sz = n;
        for (unsigned int i = 0; i < sz; ++i){
            data[i] = value;
        }
    }
    else if (n > sz && n <= cap){
        sz = n;
        for (unsigned int i = 0; i < sz; ++i){
            data[i] = value;
        }
    }
    else {
        if (n > (sz * 2)){
            expand(n - cap);
            sz = n;
            for (unsigned int i = 0; i < sz; ++i){
                data[i] = value;
            }
        }
        else{
            expand();
            sz = n;
            for (unsigned int i = 0; i < sz; ++i){
                data[i] = value;
            }
        }
    }
}

void IntVector::push_back(int value){
    if (sz == cap){
        expand();
    }
    sz++;
    data[sz - 1] = value;
}

void IntVector::pop_back(){
    sz--;
}

void IntVector::clear(){
    sz = 0;
}

void IntVector::resize(unsigned size, int value){
    if (size <= sz){
        sz = size;
    }
    else if (size > sz && size <= cap){
        for (unsigned int i = sz; i < size; ++i){
            data[i] = value;
        }
        sz = size;
    }
    else {
        if (size > (sz * 2)){
            expand(size - cap);
            for (unsigned int i = sz; i < size; ++i){
                data[i] = value;
            }
            sz = size;
        }
        else{
            expand();
            for (unsigned int i = sz; i < size; ++i){
                data[i] = value;
            }
            sz = size;
        }
    }
}

void IntVector::reserve(unsigned n){
    if (n > cap){
        expand(n - cap);
    }
}

void IntVector::expand(){
    if (cap == 0){
        data = new int[1];
        cap = 1;
    }
    else{
        int *tptr = new int[cap * 2];
        for (unsigned int i = 0; i < sz; ++i){
            tptr[i] = data[i];
        }
        delete[] data;
        data = tptr;
        cap *= 2;
    }
}

void IntVector::expand(unsigned amount){
    int *tptr = new int[cap + amount];
    for (unsigned int i = 0; i < sz; ++i){
        tptr[i] = data[i];
    }
    delete[] data;
    data = tptr;
    cap += amount;
}

// //FOR TESTING EXPAND ONLY
// void IntVector::test(){
//     expand(2);
// }