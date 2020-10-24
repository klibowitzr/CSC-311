//
//  LongInt.h
//  LongIntx
//
//  Created by Rachel klibowitz on 10/25/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#ifndef LongInt_h
#define LongInt_h
//#ifndef LONGINT_H
//#define LONGINT_H

#include <string>

class Node {
    friend class LongInt;
    Node():next(NULL),prev(NULL){};
    Node(long v):val(v),next(NULL),prev(NULL){};
private:
    long val;
    Node* next;
    Node* prev;
};

class LongInt {
public:
    LongInt();
    LongInt(long);
    LongInt(std::string);
    LongInt(const LongInt& a);
    ~LongInt();
    LongInt operator+(LongInt& a);
    LongInt& operator=(const LongInt& a);
    void print(bool comma=false);

private:
    void append(long);
    long strToLong(std::string s);
    Node* head;
    Node* tail;
};

#endif /* LongInt_h */
