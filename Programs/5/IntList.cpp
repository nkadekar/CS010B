#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList(){
    head = 0;
    tail = 0;
}

IntList::IntList(const IntList &cpy){
    head = 0;
    tail = 0;
    IntNode *curr = cpy.head;
    while (curr != 0){
        push_back(curr->data);
        curr = curr->next;
    }
}

IntList::~IntList(){
    clear();
}

void IntList::push_front(int value){
    if (empty()){
        head = new IntNode(value);
        tail = head;
    }
    else{
        IntNode *temp = new IntNode(value);
        temp->next = head;
        head = temp;
    }
}

void IntList::push_back(int value){
    if (tail == 0){
        tail = new IntNode(value);
        head = tail;
    }
    else{
        IntNode *temp = new IntNode(value);
        tail->next = temp;
        tail = temp;
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
    if (head == 0 && tail == 0){
        return true;
    }
    else{
        return false;
    }
}

void IntList::clear(){
    while(!empty()){
        pop_front();
    }
}

const int & IntList::front() const{
        return head->data;
}

const int & IntList::back() const{
        return tail->data;
}

void IntList::selection_sort(){
    for (IntNode *i = head; i != nullptr; i = i->next){
        IntNode *minLoc = i;
        for (IntNode *j = (i->next); j != nullptr; j = (j->next)){
            if((j->data) < (minLoc->data)){
                minLoc = j;
            }
        }
        int temp = minLoc->data;
        minLoc->data = i->data;
        i->data = temp;
    }
}

void IntList::insert_ordered(int value){
    if (empty()){
        push_front(value);
    }
    else if (value <= (head->data)){
        push_front(value);
    }
    else if (value >= (tail->data)){
        push_back(value);
    }
    else{
        IntNode *curr = head->next;
        IntNode *prev = head;
        while (curr != 0){
            if ((value <= (curr->data)) /*&& (value > (prev->data))*/){
                IntNode *temp = new IntNode(value);
                temp->next = curr;
                prev->next = temp;
                return;
            }
            prev = prev->next;
            curr = curr->next;
        }
    }
}

void IntList::remove_duplicates(){
    if ((!empty()) && (head != tail)){
        for (IntNode* i = head; i != 0; i = i->next){
            IntNode *prev = i;
            for (IntNode *j = (i->next); j != 0; j = (j->next)){
                if((j->data) == (i->data)){
                    if (j == tail){
                        delete j;
                        tail = prev;
                        tail->next = 0;
                        j = prev;
                    }
                    else{
                        prev->next = j->next;
                        delete j;
                        j = prev;
                    }
                }
                else{
                    prev = prev->next;
                }
            }
        }
    }
}

IntList & IntList::operator=(const IntList &rhs){
    if (this != &rhs){
        clear();
        IntNode *curr = rhs.head;
        while (curr != 0){
            push_back(curr->data);
            curr = curr->next;
        }
    }
    return *this;
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