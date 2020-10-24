//
//  LongInt.cpp
//  LongIntx
//
//  Created by Rachel klibowitz on 10/25/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "LongInt.h"
#include <sstream>

using namespace std;


LongInt::LongInt() {
    head=NULL;
    tail=NULL;
}

LongInt::LongInt(string s) {
    string temp;
    stringstream ss;
    int num=0;
    head = tail = NULL;
    if(s.length()%3==0){
        while(s.length()>0){
            temp=s.substr(s.length()-3,3);
            s.erase(s.length()-3,3);
            append(strToLong(temp));
        }
    }
    else if(s.length()%3==1){
       
        while(s.length()>1){
            temp=s.substr(s.length()-3,3);
            s.erase(s.length()-3,3);
            append(strToLong(temp));
        }
        temp=s.substr(s.length()-1,1);
        s.erase(s.length()-1,1);
        append(strToLong(temp));
    }
    else if(s.length()%3==2){
        while(s.length()>2){
            temp=s.substr(s.length()-3,3);
            s.erase(s.length()-3,3);
            append(strToLong(temp));
        }
        temp=s.substr(s.length()-2,2);
        s.erase(s.length()-2,2);
        append(strToLong(temp));
    }
}

LongInt::LongInt(long i) {
    head = tail = NULL;
    while (i) {
        append(i%1000);
        i = i / 1000;
    }
}

LongInt::~LongInt() {
    Node* p;
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
    
}

// the copy constructor
LongInt::LongInt(const LongInt& a) {
    Node* p;
    head = tail = NULL;
    p = a.head;
    while (p) {
        append(p->val);
        p = p->next;
    }
}

LongInt&
LongInt::operator=(const LongInt& a) {
    Node* p;
    
    // this would be copying myself to myself
    if (&a == this) return *this;
    
    // delete all my list if I have any allocated
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
    
    p = a.head;
    while (p) {
        append(p->val);
        p = p->next;
    }
    return *this;
}

void LongInt::append(long v){
    Node*p=new Node;
    if(v>=1000){
        cout << "Cannot append value--greater than 999" << endl;
        return;
    }
    else{
        p->val=v;
        p->next=NULL;
        if(head==NULL){ //list is empty
            p->prev=NULL;
            head=p;
            tail=p;
        }
        else{
            p->prev=tail;
            tail->next=p;
            tail=p;
        }
    }
}


void LongInt::print(bool comma) {
    Node*p=tail;
    if(comma==false){
        cout << p->val;
        p=p->prev;
        while(p){
            cout << setw(3) << setfill('0') << p->val;
            p=p->prev;
        }
    }
    else{
        if(p && p->prev!=NULL){
            if(head==tail){
                cout << p->val;
            }
            else{
                cout  << p->val << ',';
                p=p->prev;
            }
            while(p && p->prev!=NULL){
                cout  << setw(3) << setfill('0') << p->val << ',';
                p=p->prev;
            }
        }
        if(head==tail){
            cout << p->val;
        }
        else{
            cout << setw(3) << setfill('0')<< p->val;
        }
    }
}

long LongInt::strToLong(string s){
    stringstream ss;
    long num(0);
    if (s.length()>3){
        cout << "String is too long--more than three digits" << endl;
    }
    else{
        ss << s;
        ss >> num;
    }
    return num;
}

LongInt LongInt::operator+(LongInt& a){
    LongInt ret;
    int carry = 0;
    int sum=0;
    Node* p1 = head;
    Node* p2 = a.head;
    while(p1 && p2){
        sum=p1->val + p2->val + carry;
        if(sum>999){
            sum=sum%1000;
            ret.append(sum);
            carry=1;
            p1=p1->next;
            p2=p2->next;
        }
        else{
            carry=0;
            ret.append(sum);
            p1=p1->next;
            p2=p2->next;
        }
    }
    if(!p1 && p2){
        while(p2){
            sum=p2->val + carry;
            if(sum>999){
                sum=sum%1000;
                ret.append(sum);
                carry=1;
                p2=p2->next;
            }
            else{
                carry=0;
                ret.append(sum);
                p2=p2->next;
            }
        }
    }
    if(!p2 && p1){
        while(p1){
            sum=p1->val + carry;
            if(sum>999){
                sum=sum%1000;
                ret.append(sum);
                carry=1;
                p1=p1->next;
            }
            else{
                carry=0;
                ret.append(sum);
                p1=p1->next;
            }
        }
    }
    if(carry==1){
        ret.append(carry);
    }
    return ret;
}
