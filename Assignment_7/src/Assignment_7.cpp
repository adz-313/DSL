//============================================================================
// Name        : Assignment_7.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
#define MAX 10

class stack{
    char data[MAX];
    int top;
    char str[100];
public:
    stack(){
        top = -1;
    }
    void push(char);
    int full();
    int empty();
    char pop();
    int check(char,char);
    int par();
};

int stack::full(){
    if(top == MAX-1){
        return 1;
    }
    return 0;
}

void stack::push(char x){
    if(!full()){
        top++;
        data[top] = x;
    }
    else{
        cout << "Full";
        return;
    }
}

int stack::empty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

char stack::pop(){
    if(!empty()){
        char x;
        x = data[top];
        top--;
        return x;
    }
    else{
        cout << "Empty" << endl;
    }
}

int stack::check(char st_ch,char ex_ch){
    if(st_ch == '(' && ex_ch == ')'){
        return 1;
    }
    else if(st_ch == '{' && ex_ch == '}'){
        return 1;
    }
    else if(st_ch == '[' && ex_ch == ']'){
        return 1;
    }
    else{
        return 0;
    }
}

int stack::par(){
	int i = 0;
	int flag = 0;
	cout << "Enter expression: ";
    cin.getline(str,98);
	char ex_ch,st_ch;
	while(str[i] != '\0'){
	    ex_ch = str[i];
	    if(ex_ch == '(' || ex_ch == '[' || ex_ch == '{'){
	        push(ex_ch);
	    }
	    else if(ex_ch == ')' || ex_ch == ']' || ex_ch == '}'){
	       st_ch = pop();
	       flag = check(st_ch,ex_ch);
	    }
	    i++;
	}
	return flag;
}

int main(){
    stack s;
    int x = s.par();
    if(x == 1 && s.empty() == 1){
        cout << "OK";
    }
    else{
        cout << "Not OK";
    }
}
