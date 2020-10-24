#include "mytree.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[]) {
    myTree t;
    ifstream fin;
    string s;
    int x;
    fin.open(argv[1]);
    if (fin.fail()){
        cout << "file "<<argv[1] <<" failed to open.\n" << endl;
        cout << "If using from the command line, rebuild then run the";
        cout << " program using:" << endl << "./EXECUTABLENAME FILENAME.txt" << endl;
        cout << "If you have to rebuild the program, type:" << endl << "g++ -o EXECUTABLENAME main.cpp mytree.cpp" << endl;
        cout << "in the terminal window." << endl;
    }
    while(fin>> s >> x){
        t.insertVal(x,s);
    }

    t.XdoInorder();
    //t.doPreorder();
    //t.doPostorder();

    
    return 0;
}
