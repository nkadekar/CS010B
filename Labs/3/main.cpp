#include <iostream>

using namespace std;

//Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

//Rational class member functions
Rational::Rational(){
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int numer){
    numerator = numer;
    denominator = 1;
}

Rational::Rational(int numer, int denom){
    numerator = numer;
    denominator = denom;
}

//(a/b) + (c/d) = (ad + bc) / (b*d)
const Rational Rational::add(const Rational & newNum) const{
    Rational result;
    result.numerator = (numerator * newNum.denominator) + (denominator * newNum.numerator);
    result.denominator = denominator * newNum.denominator;
    return result;
}

//(a/b) - (c/d) = (ad - bc) / (b*d)
const Rational Rational::subtract(const Rational & newNum) const{
    Rational result;
    result.numerator = (numerator * newNum.denominator) - (denominator * newNum.numerator);
    result.denominator = denominator * newNum.denominator;
    return result;
}

//(a/b) * (c/d) = (ac) / (bd)
const Rational Rational::multiply(const Rational & newNum) const{
    Rational result;
    result.numerator = numerator * newNum.numerator;
    result.denominator = denominator * newNum.denominator;
    return result;
}

//(a/b) / (c/d) = (ad) / (cb)
const Rational Rational::divide(const Rational & newNum) const{
    Rational result;
    result.numerator = numerator * newNum.denominator;
    result.denominator = denominator * newNum.numerator;
    return result;
}

void Rational::simplify(){
    int a = numerator;
    int b = denominator;
    int commonD = gcd(a, b);
    numerator = numerator / commonD;
    denominator = denominator / commonD;
}

void Rational::display() const{
    cout << numerator << " / " << denominator;
}

int Rational::gcd(int a, int b) const{
    int gcd = 0;
    int min;
    int max;
    
    if (a < b){
        min = a;
        max = b;
    }
    else{
        max = a;
        min = b;
    }
    
    int i = min;
    while ((gcd == 0) && (i > 0)){
        if ((min % i == 0) && (max % i == 0)){
            gcd = i;
        }
        --i;
    }
    
    return gcd;
}

//Given
Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}