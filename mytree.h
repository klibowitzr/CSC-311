//
//  mytree.h
//  Tree
//
//  Created by Rachel klibowitz on 10/31/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#ifndef mytree_h
#define mytree_h
#include <string>
using namespace std;

class myTree;  // forward declaration

class Node {
    friend class myTree;
public:
    Node();
    Node(int val);
    Node(string s);
    Node(string s, int v);
    Node* left;
    Node* right;
private:
    int val;
    string sval;
};

class myTree {
public:
    myTree();
    ~myTree();
    Node* makeNode();
    void insertVal(int val);
    void insertVal(int val, string s);
    void doInorder();
    void XdoInorder();
    void doPreorder();
    void doPostorder();
    void Visit(Node*);
    void XVisit(Node*);
    void PostorderDelete(Node *p);
private:
    Node* root;
    
    // methods for building and traversing trees
    void Inorder(Node* p);
    void XInorder(Node* p);
    void Preorder(Node* p);
    void Postorder(Node* p);
    void setLeft(Node* p, Node* n);
    void setRight(Node* p, Node* n);
};
#endif

