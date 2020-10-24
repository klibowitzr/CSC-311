//
//  main.cpp
//  sllx
//
//  Created by Rachel klibowitz on 10/23/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>

//#include <iostream>
//#include "Sll.h"
#include "single_linked_list.h"
using namespace std;

int main(int argc, char* argv[]) {
    Sll mylist;
//    ifstream fin;
//    int x;
//    fin.open(argv[1]);
//    if (fin.fail()){
//    cout << "file failed to open.\n" << endl;
//    }
//    while(fin>>x){
//        mylist.insert(x);
//    }
//    mylist.print();
//    cout << endl;
//    mylist.dump();
    int i;
    mylist.insert(7);
    mylist.insert(4);
    mylist.insert(3);
    mylist.insert(6);
    mylist.insert(6);

    mylist.print();

    while (mylist.removefirst(i)) {
        cout << "removed " << i << " from list\n";
    }
    cout << "Nothing left to remove\n";

    return 0;
}
//
