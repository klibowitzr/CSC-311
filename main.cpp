//
//  main.cpp
//  assign6
//
//  Created by Rachel klibowitz on 9/25/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//
#include <iostream>
#include "functions.h"
using namespace std;
int main(){
    string input;
    try{
        cout << "Please enter an infix expression: " << endl;
        cin >> input;
        cout << "Infix to prefix is: " << in2pre(input) << endl;
        cout << "Infix to postfix is: " << in2post(input) << endl;
//        cout << "Please enter a prefix expression: " << endl;
//        cin >> input;
//        cout << "Prefix to infix is: " << pre2in(input) << endl;
//        cout << "Prefix to postfix is: " << pre2post(input) << endl;
//        cout << "Please enter an postfix string: " << endl;
//        cin >> input;
//        cout << "Postfix to prefix is: " << post2pre(input) << endl;
//        cout << "Postfix to infix is: " << post2in(input) << endl;
    }
    catch(out_of_range& e){
        cout << "Out of range: " << e.what() << endl;
        return 1;
    }
    catch(exception& e){
        cout << "Generic exception: " << e.what() << endl;
        return 2;
    }
    catch(...){
        cout << "What hit me?" << endl;
        return 3;
    }
}
