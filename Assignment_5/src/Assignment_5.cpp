//============================================================================
// Name        : Assignment_7.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class node{
    int data;
    node* next;
    node* prev;
public:
    node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
    friend class DLL;
};

class DLL{
    node* head;
public:
    DLL(){
        head = NULL;
    }
    void add_at_beg(int);
    void create(int);
    void show();
    void one(int);
    void two();
    void add(DLL,DLL);
};

void DLL::add_at_beg(int x){
    node* p = new node(x);
    if(head == NULL){
        head = p;
    }
    else{
        p->next = head;
        head->prev = p;
        head = p;
    }
}

void DLL::create(int num){
    for(int i = 0;i<8;i++){
        add_at_beg(num%2);
        num = num/2;
    }
}

void DLL::show(){
    node* p = head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

void DLL::one(int num){
    for(int i = 0;i<8;i++){
        if(num%2 == 0){
            add_at_beg(1);
        }
        else if(num%2 == 1){
            add_at_beg(0);
        }
        num = num/2;
    }
}

void DLL::two(){
    node* p = head;
    int x;
    int c = 1;
    while(p->next != NULL){
        p = p->next;
    }
    while(p != NULL){
        x = p->data + c;
        if(x == 0){
            p->data = 0;
            c = 0;
        }
        else if(x == 1){
            p->data = 1;
            c = 0;
        }
        else if(x == 2){
            p->data = 0;
            c = 1;
        }
        p = p->prev;
    }
}

void DLL::add(DLL a,DLL b){
    node* p = a.head;
    node* q = b.head;
    int x;
    int c = 0;
    while(p->next != NULL){
        p = p->next;
    }
    while(q->next != NULL){
        q = q->next;
    }
    while(q!=NULL){
        x = q->data + p->data;
        x = x+c;
        if(x == 0){
            c = 0;
            add_at_beg(0);
        }
        else if(x == 1){
            c = 0;
            add_at_beg(1);
        }
        else if(x == 2){
            c = 1;
            add_at_beg(0);
        }
        else if(x == 3){
            c = 1;
            add_at_beg(1);
        }
        q = q->prev;
        p = p->prev;
    }
}

int main(){
    int num;
    cout << "Enter number: ";
    cin >> num;
    DLL d1,d2,d3,d4,d5,d6,d7;
    d1.create(num);
    cout << "Binary:          ";
    d1.show();
    cout << endl;
    d2.one(num);
    cout << "Ones Complement: ";
    d2.show();
    cout << endl;
    d3.one(num);
    d3.two();
    cout << "Twos Complement: ";
    d3.show();
    cout << "Enter number: ";
    cin >> num;
    d4.create(num);
    cout << "Binary:          ";
    d4.show();
    cout << endl;
    d5.one(num);
    cout << "Ones Complement: ";
    d5.show();
    cout << endl;
    d6.one(num);
    d6.two();
    cout << "Twos Complement: ";
    d6.show();
    cout << endl;
    d7.add(d1,d4);
    cout << "Addition:        ";
    d7.show();
}
