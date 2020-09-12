#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

Date::Date(){
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
};

Date::Date(unsigned m, unsigned d, unsigned y){
    bool isCorrected = false;
    year = y;
    
    if ((m > 0) && (m <= 12)){
        month = m;
        monthName = name(month);
    }
    else if (m < 1){
        isCorrected = true;
        month = 1;
        monthName = name(month);
    }
    else if (m > 12){
        isCorrected = true;
        month = 12;
        monthName = name(month);
    }
    
    if ((d > 0) && (d <= daysPerMonth(month, year))){
        day = d;
    }
    else if (d < 1){
        isCorrected = true;
        day = 1;
    }
    else if (d > daysPerMonth(month, year)){
        isCorrected = true;
        day = daysPerMonth(month, year);
    }
    
    if (isCorrected){
        cout << "Invalid date values: Date corrected to ";
        printNumeric();
        cout << "." << endl;
    }
};

Date::Date(const string & mn, unsigned d, unsigned y){
    int theMonth;
    theMonth = number(mn);
    if (theMonth == -1){
        cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
        month = 1;
        day = 1;
        year = 2000;
        monthName = name(month);
    }
    else {
        monthName = mn;
        month = theMonth;
        year = y;
        if ((d > 0) && (d <= daysPerMonth(month, year))){
            day = d;
        }
        else if (d < 1){
            day = 1;
            cout << "Invalid date values: Date corrected to ";
            printNumeric();
            cout << "." << endl;
        }
        else if (d > daysPerMonth(month, year)){
            day = daysPerMonth(month, year);
            cout << "Invalid date values: Date corrected to ";
            printNumeric();
            cout << "." << endl;
        }
    }
};

void Date::printNumeric() const{
    cout << month << "/" << day << "/" << year;
};

void Date::printAlpha() const{
    cout << name(month) << " " << day << ", " << year;
};

bool Date::isLeap(unsigned y) const{
    bool isTrue = false;
    if (y % 4 == 0){
        isTrue = true;
        if (y % 100 == 0){
            if (y % 400 == 0){
                isTrue = true;
            }
            else{
                isTrue = false;
            }
        }
    }
    
    return isTrue;
};

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
    int days;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        days = 31;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11){
        days = 30;
    }
    else if (m == 2){
        if (isLeap(y)){
            days = 29;
        }
        else {
            days = 28;
        }
    }
    else {
        cout << "Input out of Bounds" << endl;
    }
    
    return days;
};

string Date::name(unsigned m) const{
    string mName;
    if (m == 1){
        mName = "January";
    }
    else if (m == 2){
        mName = "February";
    }
    else if (m == 3){
        mName = "March";
    }
    else if (m == 4){
        mName = "April";
    }
    else if (m == 5){
        mName = "May";
    }
    else if (m == 6){
        mName = "June";
    }
    else if (m == 7){
        mName = "July";
    }
    else if (m == 8){
        mName = "August";
    }
    else if (m == 9){
        mName = "September";
    }
    else if (m == 10){
        mName = "October";
    }
    else if (m == 11){
        mName = "November";
    }
    else if (m == 12){
        mName = "December";
    }
    else{
        return "Error";
    }
    
    return mName;
};

unsigned Date::number(const string& mn) const{
    int mNum;
    if ((mn == "January") || (mn == "january")){
        mNum = 1;
    }
    else if ((mn == "February") || (mn == "february")){
        mNum = 2;
    }
    else if ((mn == "March") || (mn == "march")){
        mNum = 3;
    }
    else if ((mn == "April") || (mn == "april")){
        mNum = 4;
    }
    else if ((mn == "May") || (mn == "may")){
        mNum = 5;
    }
    else if ((mn == "June") || (mn == "june")){
        mNum = 6;
    }
    else if ((mn == "July") || (mn == "july")){
        mNum = 7;
    }
    else if ((mn == "August") || (mn == "august")){
        mNum = 8;
    }
    else if ((mn == "September") || (mn == "september")){
        mNum = 9;
    }
    else if ((mn == "October") || (mn == "october")){
        mNum = 10;
    }
    else if ((mn == "November") || (mn == "november")){
        mNum = 11;
    }
    else if ((mn == "December") || (mn == "december")){
        mNum = 12;
    }
    else{
        return -1;
    }
    
    return mNum;
};

//main
Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } 
   else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } 
   else {
      return Date();
   }
}