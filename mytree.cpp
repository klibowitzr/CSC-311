//
//  mytree.cpp
//  Tree
//
//  Created by Rachel klibowitz on 10/31/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "mytree.h"

using namespace std;

Node::Node() {
    left=NULL;
    right=NULL;
}

Node::Node(int v) {
    left=NULL;
    right=NULL;
    val=v;
}
Node::Node(string s){
    left=NULL;
    right=NULL;
    sval=s;
}
myTree::myTree() {
    root=NULL;
}
Node::Node(string s, int v){
    left=NULL;
    right=NULL;
    sval=s;
    val=v;
}

myTree::~myTree() {
    PostorderDelete(root);
}

void
myTree::Visit(Node* p) {
    cout << p->val << " ";
}
void
myTree::XVisit(Node* p){
    cout << p->sval << " "<< p->val << endl;
}
void
myTree::doInorder() {
    Inorder(root);
    cout << endl;
}
void myTree::XdoInorder(){
    XInorder(root);
    cout << endl;
}
void
myTree::doPreorder() {
    Preorder(root);
    cout << endl;
}

void
myTree::doPostorder() {
    Postorder(root);
    cout << endl;
}

void
myTree::Preorder(Node* p) {
    if (p==NULL) {
        return;
    }
    Visit(p);
    Preorder(p->left);
    Preorder(p->right);
}

void
myTree::Postorder(Node* p) {
    if (p==NULL) {
        return;
    }
    Postorder(p->left);
    Postorder(p->right);
    Visit(p);
}

void
myTree::Inorder(Node* p) {
    if (p==NULL) {
        return;
    }
    Inorder(p->left);
    Visit(p);
    Inorder(p->right);
}
void
myTree::XInorder(Node* p) {
    if (p==NULL) {
        return;
    }
    XInorder(p->left);
    XVisit(p);
    XInorder(p->right);
}
void
myTree::PostorderDelete(Node* p) {
    if (p==NULL) {
        return;
    }
    PostorderDelete(p->left);
    PostorderDelete(p->right);
    delete p;
}
void
myTree::insertVal(int val) {
    Node *n = new Node(val);
    if (root==NULL) {
        root=n;
        return;
    }
    Node *p, *q;
    p = q = root;
    while(q!=NULL) {
        p=q;
        if(val<p->val) {
            q=p->left;
        }
        else {
            q=p->right;
        }
    }
    if(val<p->val){
        setLeft(p,n);
    }
    else{
       setRight(p,n);
    }
}
void
myTree::insertVal(int val, string s) {
    Node *n = new Node(s,val);
    if (root==NULL) {
        root=n;
        return;
    }
    Node *p, *q;
    p = q = root;
    while(q!=NULL) {
        p=q;
        if(val<p->val) {
            q=p->left;
        }
        else {
            q=p->right;
        }
    }
    if(val<p->val){
        setLeft(p,n);
    }
    else{
        setRight(p,n);
    }
}
void
myTree::setLeft(Node* p, Node* n) {
    p->left=n;
}

void myTree::setRight(Node* p, Node* n) {
    p->right=n;
}
