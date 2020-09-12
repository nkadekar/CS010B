#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

  //tests constructor, destructor, push_front, pop_front, display
   {
      cout << "\nlist1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
       cout << "pop" << endl;
       list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pushfront 100" << endl;
      list1.push_front(100);
      cout << "pushfront 200" << endl;
      list1.push_front(200);
      cout << "pushfront 300" << endl;
      list1.push_front(300);
      cout << "list1: " << list1 << endl;
      cout << endl;
      cout << "Calling list1 destructor..." << endl;
   }
   cout << "list1 destructor returned" << endl;
   
   //Test destructor on empty IntList
   {
      IntList list2;
      cout << "Calling list2 destructor..." << endl;
   }
   cout << "list2 destructor returned" << endl;
    
    //SECOND ROUND TESTING
    cout << "\nlist1 constructor called" << endl;
    IntList list1;
    cout << "pushfront 10" << endl;
    list1.push_front(10);
    cout << "pushback 150" << endl;
    list1.push_back(150);
    cout << "list1: " << list1 << endl;
    cout << "copy constructor into new list5" << endl;
    IntList list5(list1);
    cout << "list5: " << list5 << endl;
    cout << "pushback 220 into list5" << endl;
    list5.push_back(220);
    cout << "list5: " << list5 << endl;
    cout << "clear list5" << endl;
    list5.clear();
    cout << "list5: " << list5 << endl;
    cout << "assigning list1 to list5 (assignment operator)" << endl;
    list5 = list1;
    cout << "list5: " << list5 << endl;
    cout << "assignment operator special case:empty list(should display nothing) " << endl;
    list1.clear();
    list5 = list1;
    cout << "list5: " << list5 << endl;
    cout << "pushback 250" << endl;
    list1.push_back(250);
    cout << "list1: " << list1 << endl;
    cout << "pushback 250" << endl;
    list1.push_back(250);
    cout << "list1: " << list1 << endl;
    cout << "pushback 100" << endl;
    list1.push_back(100);
    cout << "list1: " << list1 << endl;
    cout << "pushback 20" << endl;
    list1.push_back(20);
    cout << "list1: " << list1 << endl;
    cout << "pushback 70" << endl;
    list1.push_back(70);
    cout << "list1: " << list1 << endl;
    cout << "pushback 20" << endl;
    list1.push_back(20);
    cout << "list1: " << list1 << endl;
    cout << "selection sort" << endl;
    list1.selection_sort();
    cout << "list1: " << list1 << endl;
    cout << "inserting 100 into ordered list" << endl;
    list1.insert_ordered(100);
    cout << "list1: " << list1 << endl;
    cout << "inserting 5 into ordered list" << endl;
    list1.insert_ordered(5);
    cout << "list1: " << list1 << endl;
    cout << "inserting 250 into ordered list" << endl;
    list1.insert_ordered(250);
    cout << "list1: " << list1 << endl;
    cout << "inserting 250 into ordered list" << endl;
    list1.insert_ordered(250);
    cout << "list1: " << list1 << endl;
    cout << "inserting 300 into ordered list" << endl;
    list1.insert_ordered(300);
    cout << "list1: " << list1 << endl;
    cout << "inserting 5 into ordered list" << endl;
    list1.insert_ordered(5);
    cout << "list1: " << list1 << endl;
    cout << "inserting 5 into ordered list" << endl;
    list1.insert_ordered(5);
    cout << "list1: " << list1 << endl;
    cout << "removing duplicates from list1" << endl;
    list1.remove_duplicates();
    cout << "list1: " << list1 << endl;
    
   return 0;
}