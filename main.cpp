//
//  main.cpp
//  RationalClass
//
//  Created by Rachel klibowitz on 9/12/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//
#include "rational.h"
#include <iostream>
using namespace std;


void Rational::MasterRational(){ //stores original values incase user needs
    masternum=num;     //the values before simplification
    masterdenom=denom;
}

Rational::Rational(int a,int b){
    num=a;
    denom=b;
    MasterRational();
}

Rational::Rational(){
    num=0;
    denom=1;
    MasterRational();
}

void Rational::ResetValues(int a,int b){ // replace num and denom with args
    num=a;
    denom=b;
}

Rational Rational::add(Rational& x){
    int sumnum, sumdenom, t;
    Rational r;
    reduce();
    x.reduce();
    r.ResetValues(denom,x.denom);
    r.reduce();
    t=x.denom;
    sumdenom=denom*t;
    sumnum=(num * t) + (x.num * (sumdenom/x.denom));
    r.ResetValues(sumnum, sumdenom);
    r.reduce();
    return r;
}

Rational Rational::multiply( Rational& x){
    Rational r1, r2, r3;
    int numer, denomor;
    reduce();
    x.reduce();
    r1.ResetValues(num, x.denom);
    r1.reduce();
    r2.ResetValues(x.num, denom);
    r2.reduce();
    numer=r1.num * r2.num;
    denomor=r1.denom * r2.denom;
    r1.ResetValues(numer, denomor);
    return r1;
}

bool Rational::equals(Rational& x){
    reduce();
    x.reduce();
    if((num==x.num) && (denom==x.denom)){
        return true;
    }
    else
        return false;
};

void Rational::print(){
    cout << "(" << num << "," << denom << ") ";
}
void Rational::printMaster(){
    cout << "(" << masternum << "," << masterdenom << ") ";
}
//Overloaded operators
bool Rational::operator<(Rational &x){
    int product1, product2;
    reduce();
    x.reduce();
    product1=num*x.denom;
    product2=denom*x.num;
    return(product1<product2);
}

bool Rational::operator<=(Rational &x){
    int product1, product2;
    reduce();
    x.reduce();
    product1=num*x.denom;
    product2=denom*x.num;
    return(product1<=product2);
}
bool Rational::operator>(Rational &x){
    int product1, product2;
    reduce();
    x.reduce();
    product1=num*x.denom;
    product2=denom*x.num;
    return(product1>product2);
}

bool Rational::operator>=(Rational &x){
    int product1, product2;
    reduce();
    x.reduce();
    product1=num*x.denom;
    product2=denom*x.num;
    return(product1>=product2);
}
bool Rational::operator!=(Rational &x){
    reduce();
    x.reduce();
    if((num!=x.num) || (denom!=x.denom)){
        return true;
    }
    else
        return false;
}
bool Rational::operator==(Rational &x){
    reduce();
    x.reduce();
    if((num==x.num) && (denom==x.denom)){
        return true;
    }
    else
        return false;
}

Rational Rational::operator+(Rational &x){
    int sumnum, sumdenom, t;
    Rational r;
    reduce();
    x.reduce();
    r.ResetValues(denom,x.denom);
    r.reduce();
    t=x.denom;
    sumdenom=denom*t;
    sumnum=(num * t) + (x.num * (sumdenom/x.denom));
    r.ResetValues(sumnum, sumdenom);
    r.reduce();
    return r;
}
Rational Rational::operator-(Rational &x){
    int remaindernum, remainderdenom, t;
    Rational r;
    reduce();
    x.reduce();
    r.ResetValues(denom,x.denom);
    r.reduce();
    t=x.denom;
    remainderdenom=denom*t;
    remaindernum=(num * t) - (x.num * (remainderdenom/x.denom));
    r.ResetValues(remaindernum, remainderdenom);
    r.reduce();
    return r;
}

Rational Rational::operator*(Rational &x){
    Rational r1, r2, r3;
    int numer, denomor;
    reduce();
    x.reduce();
    r1.ResetValues(num, x.denom);
    r1.reduce();
    r2.ResetValues(x.num, denom);
    r2.reduce();
    numer=r1.num * r2.num;
    denomor=r1.denom * r2.denom;
    r1.ResetValues(numer, denomor);
    return r1;
}
Rational Rational::operator/(Rational &x){
    Rational r1;
    r1.ResetValues(x.denom, x.num);
    return multiply(r1);
}
 ostream &operator<<(std::ostream &stream, Rational &x){
    stream << "(" << x.num << "," << x.denom << ")" << endl;
    return stream;
}

void Rational::reduce()  {
    int a, b, sign, rem; //newnum, newdenom;
    if(num==0){
        denom=1;
    }
    sign=1;
    if((num<0)&&(denom<0)){
        num=-num;
        denom=-denom;
    }
    if(num<0){
        num=-num;
        sign=-1;
    }
    if(denom <0){
        denom=-denom;
        sign=-1;
    }
    if (num >=denom){
        a=num;
        b=denom;
    }
    else {
        a=denom;
        b=num;
    }
    while(b!=0){
        rem=a%b;
        a=b;
        b=rem;
    }
    num=sign * num / a;
    denom=denom / a;
    
};  // apply euclid's algorithm to reduce to
// lowest terms

int main (){
    int x1, x2, y1, y2;
    cout << "Please enter four intergers to create two rational numbers:" << endl;
    cin >> x1 >> x2 >> y1 >> y2; //THIS PROGRAM CAN ONLY HANDLE 4 BYTE NUMBERS
    Rational a, b, result, master1, master2;
    a=Rational(x1,x2);
    b=Rational(y1,y2);
    result=Rational();
    result=a.add(b);
    cout << "Sum using function is: ";
    result.print();
    cout << endl;
    result.ResetValues(0,1);
    result=a+b;
    cout << "Sum using overloaded operator (+) is " << result << endl;
    result=a-b;
    cout << "Remainder using overloaded operator (-) is " << result << endl;
    result=a.multiply(b);
    cout << "Product using function is: " << result << endl;
    result.ResetValues(0,1);
    result=a*b;
    cout << "Product using overloaded operator (*) is " << result << endl;
    result=a/b;
    cout << "Quotient using overloaded operator (/) is " << result << endl;
    cout << "Now on to the boolean part...0 is no, 1 is yes." << endl;
    cout << "Using the function, are the two rational numbers equal? " << a.equals(b) << endl;
    cout << "Using the overloaded operator, are the two rational numbers equal? " << (a==b) << endl;
    cout << "Using the overloaded operator, are the two rational numbers NOT equal? " << (a!=b) << endl;
    cout << "Using the overloaded operator, is 'a' greater than or equal to 'b'? " << (a>=b) << endl;
    cout << "Using the overloaded operator, is 'a' greater than 'b'? " << (a>b) << endl;
    cout << "Using the overloaded operator, is 'a' less than or equal to 'b'? " << (a<=b) << endl;
    cout << "Using the overloaded operator, is 'a' less than 'b'? " << (a<b) << endl;
    cout << "Here are your original values:" << endl;
    a.printMaster();
    cout << endl;
    cout << "and the second one " << endl;
    b.printMaster();
    cout << endl;
    return 0;
}
