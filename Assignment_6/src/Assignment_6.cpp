//============================================================================
// Name        : Assignment_6.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <math.h>
using namespace std;

class node{
public:
    int exp,coeff;
    node *next;
    node(int c,int e){
        exp = e;
        coeff = c;
        next = NULL;
    }
};

class Polynomial{
node *head;
node *rear;
public:
    Polynomial(){
        head = NULL;
        rear = NULL;
    }
    void create();
    void show();
    void eval();
    void add(Polynomial,Polynomial);
    void sort();
    int count();
    void add_at_beg(int,int);
    void add_at_end(int,int);
};

void Polynomial::create(){
    cout << "Enter n: ";
    int n;
    cin >> n;
    int c,e;
    cout << "Coefficient: ";
    cin >> c;
    cout << "Exponent: ";
    cin >> e;
    head = new node(c,e);
    node* p = head;
    for(int i=1;i<n;i++){
        cout << "Coefficient: ";
        cin >> c;
        cout << "Exponent: ";
        cin >> e;
        p->next = new node(c,e);
        p = p->next;
    }
    rear = p;
    p->next = head;
}

void Polynomial::show(){
    if(head == NULL){
        cout << "Please enter a polynomial first." << endl;
        return;
    }
    node* p = head;
    while(p != rear){
        cout << p->coeff << "x" << p->exp << " + ";
        p = p->next;
    }
    cout << p->coeff << "x" << p->exp << endl;
}

void Polynomial::eval(){
    node* p = head;
    int x;
    cout << "Enter x to evaluate polynomial: ";
    cin >> x;
    int sum = 0;
    do{
        sum += pow(x,p->exp)*p->coeff;
        p = p->next;
    }while(p != head);
    cout << sum << endl;
}

/*void Polynomial::add(Polynomial a,Polynomial b){
	/*int n = a.count();
	int m = b.count();
	int j = 0;
	int i = 0;
	node* p = a.head;
	node* q = b.head;
	do{
		if(p->exp == q->exp){
			int sum = p->coeff + q->coeff;
			add_at_beg(sum,q->coeff);
		}
		else{
			if(q->exp > p->exp){
				add_at_end(q->coeff,q->exp);
			}
			else{
				add_at_end(p->coeff,p->exp);
			}
		}
	}while(p != a.head && q != b.head);
}*/

void Polynomial::add(Polynomial a,Polynomial b){
    int flag = 0;
    node* p = a.head;
    node* q = b.head;
    node* r;
    do{
        add_at_beg(q->coeff,q->exp);
        q = q->next;
    }while(q != b.head);
    do{
        r = head;
        do{
            if(r->exp == p->exp){
                flag = 1;
                break;
            }
            r = r->next;
        }while(r != head);
        if(flag == 1){
            r->coeff = r->coeff + p->coeff;
            flag = 0;
        }
        else{
            add_at_end(p->coeff,p->exp);
        }
        p = p->next;
    }while(p != a.head);
}

int Polynomial::count(){
    int cnt = 0;
    node *p = head;
    do{
        cnt++;
        p = p->next;
    }while(p != head);
    return cnt;
}

void Polynomial::sort(){
    int e,c;
    node* temp1;
    node* temp2;
    int cnt = count();
    for(int i=1;i<cnt;i++){
        temp1 = head;
        temp2 = head->next;
        for(int j=0;j<cnt-1;j++){
            if(temp1->exp > temp2->exp){
                e = temp1->exp;
                c = temp1->coeff;
                temp1->exp = temp2->exp;
                temp1->coeff = temp2->coeff;
                temp2->exp = e;
                temp2->coeff = c;
            }
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
}

void Polynomial::add_at_beg(int c,int e){
    node *p = new node(c,e);
    if(head == NULL){
    	head = p;
    	rear = p;
    	p->next = p;
    }
    else{
    	p->next = head;
    	head = p;
    	rear->next = head;
    }
}

void Polynomial::add_at_end(int c,int e){
	node* p = new node(c,e);
	if(head == NULL){
	    head = p;
	   	rear = p;
	   	p->next = p;
	}
    else{
	    rear->next = p;
	   	p->next = head;
	   	rear = p;
    }
}

int main(){
    int ch;
    Polynomial p,q,sum;
    cout << "Enter 1 to enter polynomial. " << endl;
    cout << "Enter 2 to display polynomial. " << endl;
    cout << "Enter 3 to evaluate polynomial. " << endl;
    cout << "Enter 4 to add polynomials. " << endl;
    cout << "Enter 5 to exit." << endl;
    do{
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
        case 0: return 0;
        case 1: p.create(); break;
        case 2: p.sort();p.show(); break;
        case 3: p.eval(); break;
        case 4: q.create();q.show();sum.add(p,q);sum.sort();sum.show(); break;
        case 5: return 0;
        default: cout << "In-valid choice: ";
        }
    }while(ch != 0);
}
