//
//  stack6.h
//  assign6
//
//  Created by Rachel klibowitz on 9/28/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#ifndef stack6_h
#define stack6_h


#include <stdexcept>
#include <iostream>

using namespace std;
int const MAX=25;

template <class T>
class Stack{
public:
    Stack();
    T pop(void);
    void push(const T&);
    bool empty(void);
    T peek(void);
private:
    T st[MAX];
    T* sp;
};

template<class T>
bool
Stack<T>::empty(){
    return (sp==st);
}

template<class T>
Stack<T>::Stack(){
    sp=st;
}

template<class T>
void
Stack<T>::push(const T& val){
    *sp++=val;
    if(sp>st+MAX){ //if sp>end of array (where st is the beginning and max is the size)
        throw out_of_range("Pushing will result in overflow");
    }
}

template<class T>
T
Stack<T>::pop(void){
    if(empty()){
        throw out_of_range("Popping will result in underflow");
    }
    else{
        return *--sp;
    }
}

template<class T>
T
Stack<T>::peek(){
    T i;
    i=pop();
    push(i);
    return i;
}
#endif /* stack6_h */
