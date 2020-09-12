#include <iostream>
#include <cstdlib>

using namespace std;

#include "Distance.h"

Distance::Distance(){
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in){
    if (in < 12 && in > -12){
        feet = ft;
        inches = abs(in);
    }
    else {
        in = abs(in);
        int int_in = static_cast<int>(in);
        int exFt = 0;
        double deci = in - int_in;
        int leftIn = 0;
        
        exFt = int_in / 12;
        leftIn = int_in % 12;
        
        inches = leftIn + deci;
        feet = ft + exFt;
    }
    
}

Distance::Distance(double in){
    if (in < 12 && in > -12){
        feet = 0;
        inches = abs(in);
    }
    else {
        in = abs(in);
        int int_in = static_cast<int>(in);
        int exFt = 0;
        double deci = in - int_in;
        int leftIn = 0;
        
        exFt = int_in / 12;
        leftIn = int_in % 12;
        
        inches = leftIn + deci;
        feet = exFt;
    } 
}

unsigned Distance::getFeet() const{
    return feet;
}

double Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const{
    return (inches + (feet * 12));
}

double Distance::distanceInFeet() const{
    return distanceInInches() / 12.0;
}

double Distance::distanceInMeters() const{
    return (inches + (feet * 12)) * 0.0254;
}

Distance Distance::operator+(const Distance &rhs) const{

    Distance subtract;
    double a = distanceInInches();
    double b = rhs.distanceInInches();
    double sumInches = a + b;
    sumInches = abs(sumInches);
    int int_in = static_cast<int>(sumInches);
    int exFt = 0;
    double deci = sumInches - int_in;
    int leftIn = 0;
    exFt = int_in / 12;
    leftIn = int_in % 12;
    subtract.inches = leftIn + deci;
    subtract.feet = exFt;
    
    return subtract;
}

Distance Distance::operator-(const Distance &rhs) const{
    Distance subtract;
    double a = distanceInInches();
    double b = rhs.distanceInInches();
    double sumInches = a - b;
    sumInches = abs(sumInches);
    int int_in = static_cast<int>(sumInches);
    int exFt = 0;
    double deci = sumInches - int_in;
    int leftIn = 0;
    exFt = int_in / 12;
    leftIn = int_in % 12;
    subtract.inches = leftIn + deci;
    subtract.feet = exFt;
    
    return subtract;
}

ostream & operator<<(ostream &out, const Distance &rhs){
    out << rhs.feet << "' " << rhs.inches << '"';
    return out;
}