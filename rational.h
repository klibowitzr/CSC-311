//
//  rational.h
//  RationalClass
//
//  Created by Rachel klibowitz on 9/17/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#ifndef rational_h
#define rational_h
#include <iostream>
using namespace std;
class Rational{
public:
   
    Rational(int, int);
    Rational();
    void MasterRational();
    void ResetValues(int, int);
    Rational add(Rational&);
    Rational multiply(Rational&);
    bool equals(Rational&);
    void print();
    void printMaster();
    bool operator<(Rational &x);
    bool operator<=(Rational &x);
    bool operator>(Rational &x);
    bool operator>=(Rational &x);
    bool operator!=(Rational &x);
    bool operator==(Rational &x);
    Rational operator+(Rational &x);
    Rational operator-(Rational &x);
    Rational operator*(Rational &x);
    Rational operator/(Rational &x);
    friend ostream &operator<<(std::ostream &stream, Rational &x);
private:
    int num;
    int denom;
    int masternum;
    int masterdenom;
    void reduce();
};

#endif /* rational_h */
