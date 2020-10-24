//
//  Header.h
//  stack
//
//  Created by Rachel klibowitz on 9/21/18.
//  Copyright Â© 2018 Rachel klibowitz. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdexcept>
#include <iostream>

using namespace std;
int const MAX=50;

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
/* I also had if(sp>&st[MAX] but I had a funny feeling that this was only working by chance. I can't believe how wrong I was before.*/

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


#endif /* stack_h */
