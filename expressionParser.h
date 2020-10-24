//
//  Assign7h.h
//  Assign7
//
//  Created by Rachel klibowitz on 10/4/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H
using namespace std;
#include <string>
bool isExpr(string&);
bool isFact(string&);
bool isTerm(string&);
bool match(char, string&);
bool matchalpha(string&);
int i=0;

bool matchalpha(string& s){
  if(isalpha(s[0])){
    s.erase(0,1);
    // cout << "Match alpha returned true" << endl;
    return true;
  }
  else {
    // cout << "Match alpha returned false" << endl;
    return false;
  }
}

bool match(char c,string& s){
  if(s[0]==c){
    s.erase(0,1);
    // cout << "Match returned true" << endl;
    return true;
  }
  else{
    // cout << "Match returned false" << endl;
    return false;
  }
}
bool isFact(string& s){
  if(match('(',s)){
    // cout << "inside of isFact" << endl;
    return(isExpr(s)&& match(')',s));
  }
  else{
    // cout << " was called from within isFact " << endl;
    return matchalpha(s);
  }
}

bool isTerm(string& s){
  if(isFact(s)){
    if(s=="") return true;
    if(match('*', s)){
      if(isFact(s)) return true;
      else return false;
    }
    else return true;
  }
  else return false;
}
bool isExpr(string& s){
  ++i;
  if(isTerm(s)){
    if(s==""){
      return true;
    }
    else if(match('+',s)){
      if(isTerm(s)){
        if(i==1 && s.length()!=0){
          return false;
        }
        else{
          --i;
          return true;
        }
        // else return true;
      }
      else return false;//was false
    }
    else return true;//was false
  }
  else return false;
}

#endif /* EXPRESSIONPARSER_H */
