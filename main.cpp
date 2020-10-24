//
//  main.cpp
//  LongIntx
//
//  Created by Rachel klibowitz on 10/25/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#include <iostream>
#include <string>
#include "LongInt.h"

using namespace std;

int main() {
    //string s="999";
    //LongInt t;
    //t.strToLong(s);
    
      //strToLong();
//    LongInt x(12312345678);
//    LongInt x;
//    x.append(1);
//    x.append(40);
//    x.append(43);
//    x.append(78);
//    x.append(65);
//    x.append(566);
//    x.append(499);
//    x.append(2);
//    x.append(134);
//    x.print(true);
    
//    LongInt a("7909991");
//    LongInt b("100");
//    LongInt sum=a+b;
//    sum.print(true);
//    LongInt i(123456789123456);
//    x.print(true);
    
    
    

    LongInt a(1);
    LongInt b(1);
    a.print(true);
    cout << endl;
    b.print(true);
    cout << endl;
    for (int i = 0; i < 98; i++ ) {
        LongInt fib = a + b;
        fib.print(true);
        cout << endl;
        a = b;
        b = fib;
    }

    return 0;
}
