#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    while(head != nullptr){
        pop_front();
    }
}

void IntList::push_front(int value){
    if (head == nullptr){
        head = new IntNode(value);
        tail = head;
    }
    else{
        IntNode *temp = new IntNode(value);
        temp->next = head;
        head = temp;
    }
}

void IntList::pop_front(){
    if (!empty()){
        if (head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else{
            IntNode *temp = head->next;
            delete head;
            head = temp;
        }
    }
}

bool IntList::empty() const{
    if (head == nullptr){
        return true;
    }
    else{
        return false;
    }
}

const int & IntList::front() const{
    //if (head != nullptr){
        return head->data;
    //}
}

const int & IntList::back() const{
    //if (tail != nullptr){
        return tail->data;
    //}
}

ostream & operator<<(ostream & out, const IntList & value){
    if (!value.empty()){
        out << value.front();
        IntNode *curr = value.head->next;
        if (curr != nullptr){
            out << " ";
        }
        while (curr != nullptr){
            out << curr->data;
            if (curr->next != nullptr){
                out << " ";
            }
            curr = curr->next;
        }
    }
    
    return out;
}