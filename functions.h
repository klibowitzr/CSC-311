//
//  functions.h
//  assign6
//
//  Created by Rachel klibowitz on 9/26/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#ifndef functions_h
#define functions_h

#include <iostream>
#include "stack6.h"

string operators="+-/*()";



bool preced(string tos, string tok){
    if (tos==tok) return true;
    if((tos=="+" || tos=="-") && (tok=="-" || tok=="+")) return true;
    if((tos=="+" || tos=="-") && (tok=="*" || tok=="/")) return false;
    if((tos=="*" || tos=="/") && (tok=="+" || tok=="-")) return true;
    if((tos=="*" || tos=="/") && (tok=="*" || tok=="/")) return true;
    if((tos==")") && (tok=="+" || tok=="-" || tok=="*" || tok=="/")) return false;
    if((tok==")") && (tos=="+" || tos=="-" || tos=="/" || tos=="*")) return true;
    else return false;
}

//void cleanup(){
//    string input="";
//    string output="";
//    string trash="";
//    string tok="";
//    string tos="";
//}
string gettok(string& i){
    string ret;
    ret=i[0];
    i.erase(0,1);
    return ret;
}
string getrighttok(string &i){
    string ret;
    ret=i[i.length()-1];
    i.erase(i.length()-1, 1);
    return ret;
}
string post2in(string& x){
    string input;
    string output;
    string trash;
    Stack<string>stack;
    string tok;
    string tos;
    while(x.length()>0){
        tok=gettok(x);
        size_t found=operators.find(tok);
        if(found==string::npos){
            stack.push(tok);
        }
        else{
            string b=stack.pop();
            string a=stack.pop();
            string result="("+a+tok+b+")";
            stack.push(result);
        }
    }
    if(x.length()==0){
        while(!stack.empty()){
            string i=stack.pop();
            output+=i;
        }
    }
    return output;
}

string in2post(string x){
    string input;
    string output;
    string trash;
    Stack<string>stack;
    string tok;
    string tos;
    while(x.length()>0){
        tok=gettok(x);
        size_t found=operators.find(tok);
        if(found==string::npos){
            output+=tok;
        }
        else{
            if (stack.empty()==false)
                tos=stack.peek();
            if(tok=="(")
                stack.push(tok);
            else if(tok==")"){
                while(stack.peek()!="("){
                    string i=stack.pop();
                    output+=i;
                }
                stack.pop();
            }
            else{
                while(!stack.empty()&& preced(tos,tok)){
                    string i;
                    i=stack.pop();
                    output+=i;
                }
                stack.push(tok);
            }
        }
        
        if(x.length()==0){
            while(!stack.empty()){
                string i;
                i=stack.pop();
                output+=i;
            }
        }
    }
    return output;

}

string pre2in(string x){
    string input;
    string output;
    string trash;
    Stack<string>stack;
    string tok;
    string tos;
    while(x.length()>0){
        tok=getrighttok(x);
        size_t found=operators.find(tok);
        if(found==string::npos){
            stack.push(tok);
        }
        else{
            string a=stack.pop();
            string b=stack.pop();
            string result=("("+a+tok+b+")");
            stack.push(result);
        }
    }
    if(x.length()==0){
        while(!stack.empty()){
            string i=stack.pop();
            output+=i;
        }
    }
    return output;
}

string post2pre(string x){
    string input;
    string output;
    string trash;
    Stack<string>stack;
    string tok;
    string tos;
    while(x.length()>0){
        tok=gettok(x);
        size_t found=operators.find(tok);
        if(found!=string::npos && !stack.empty()){
            string a=stack.pop();
            string b=stack.pop();
            string result=tok+b+a;
            stack.push(result);
        }
        else if(found!=string::npos && stack.empty()){
            stack.push(tok);
        }
        else
            stack.push(tok);
    }
    return stack.peek();
}
string pre2post(string x){
    string result;
    result=in2post(pre2in(x));
    return result;
}
string in2pre(string x){
    string result;
    result=in2post(x);
    result=post2pre(result);
    return result;
}

#endif /* functions_h */
