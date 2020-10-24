#include <iostream>
#include "expressionParser.h"
using namespace std;

int main(){
    string s;
    cout << "Please enter an expression: " << endl;
    cin >> s;
    cout << s;
    if(isExpr(s)){
      cout << " is valid" << endl;
    }
    else{
      cout << " is invalid" << endl;
    }
}
