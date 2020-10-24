//
//  header.h
//  sllx
//
//  Created by Rachel klibowitz on 10/23/18.
//  Copyright © 2018 Rachel klibowitz. All rights reserved.
//

#ifndef single_linked_list
#define single_linked_list
using namespace std;

class Node {
    friend class Sll;
public:
    Node();
private:
    int val;
    Node* next;
};
Node::Node(){
    val=-1;
    next=NULL;
};

class Sll {
public:
    Sll();
    ~Sll();
    void insert(int);
    bool remove(int&);//removes node with a given value
    bool removefirst(int&); //removes first node
    void print();
    void dump(); //iterates through list, deletes all nodes and outputs it, basically
    //a glorified deconstructor?
private:
    Node* head;
    Node* tail;
};

Sll::Sll(){
    head=NULL;
};

Sll::~Sll(){
    Node* q=NULL;
    Node* p=head;
    while(p){
        q=p;
        p=p->next;
        delete q;
    }
};

void Sll::insert(int v){
    Node*n= new Node;
    n->val=v;
    Node*p, *q;
    q=NULL;
    p=head;
    while(p && p->val<=v){
        q=p;
        p=q->next;
    }
    if(q==NULL){
        n->next=p;
        head=n;
        tail=p;
    }
    else{
        n->next=q->next;
        q->next=n;
        if(p){tail=p;}
        if(!p){tail=n;}
    }
};

bool Sll::remove(int& v){
    Node *p;
    p=head;
    if(p->val==v){
        head=head->next;
        delete p;
        return true;
    }
    while(p->next && p->next->val!=v){
        p=p->next;
    }
    if(p->next==NULL){
        return false;
    }
    if(p->next->next==NULL){
        Node* q;
        q=p->next;
        delete q;
        p->next=NULL;
        return true;
    }
    else if(p->next->next!=NULL){
        Node* q;
        q=p->next;
        p->next=p->next->next;
        delete q;
        return true;
    }
    else{
        return false;
    }
};

bool Sll::removefirst(int& v){
    Node *p;
    p=head;
    if(head==NULL){
        return false;
    }
    v=head->val;
    if(head->next==NULL){
//        p=NULL;
        head=head->next;
        delete p;
        return true;
        //delete p;
    }
    //return false;
    else{
        head=head->next;
        delete p;
        return true;
    }
};

void Sll::dump(){
    Node* q=NULL;
    Node* p=head;
    while(p){
        q=p;
        p=p->next;
        cout << "removed " << q->val << endl;
        remove(q->val);
        //delete q;
    }
};

void Sll::print(){
    Node*p=head;
    while(p){
        cout << p->val << " ";
        p=p->next;
    }
    cout << endl;
};
#endif /* single_linked_list */
