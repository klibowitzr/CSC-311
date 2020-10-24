//
//  main.cpp
//  stack
//
//  Created by Rachel klibowitz on 9/21/18.
//  Copyright Â© 2018 Rachel klibowitz. All rights reserved.
//

#include <iostream>
#include "stack.h"

int main(){
    Stack<int>mystack;
    //    int i;
    //    mystack.push(1);
    //    mystack.push(2);
    //    mystack.push(3);
    try{
        mystack.push(99);
        mystack.push(80);
        cout << "Peeking at..." << mystack.peek() << endl;
        mystack.push(78);
//        mystack.push(11);
        //    mystack.push(7);
        cout << "Is the stack empty? " << mystack.empty() << endl;
        mystack.pop();
        mystack.pop();
        cout << "Is the stack empty? " << mystack.empty() << endl;
        mystack.pop();
        mystack.pop();
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
