//============================================================================
// Name        : Assignment_8.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
using namespace std;
#define MAX 10

class stack{
    int data[MAX];
    int top;
    char postfix[100];
public:
    stack(){
        top = -1;
    }
    void push(int);
    int pop();
    int empty();
    int full();
    void convert(char[]);
    int get_priority(int);
    void eval();
};

int stack::full(){
    if(top == MAX-1){
        return 1;
    }
    return 0;
}

void stack::push(int c){
    if(!full()){
        top++;
        data[top] = c;
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

int stack::pop(){
    if(!empty()){
        int x;
        x = data[top];
        top--;
        return x;
    }
    else{
        cout << "Empty";
    }
}

int stack::get_priority(int ch){
    if(ch == '/' || ch == '*'){
        return 2;
    }
    else{
        return 1;
    }
}

void stack::convert(char infix[]){
	int st_ch;
	int ex_ch;
	int flag = 0;
	int j = 0;
	int i = 0;
	while(infix[i] != '\0'){
	    ex_ch = infix[i];
	    i++;
	    if(ex_ch == '+' || ex_ch == '-' || ex_ch == '*' || ex_ch == '/'){
	        if(empty()){
	        	push(ex_ch);
	        }
	        else{
	            while(!empty()){
	            	int pr_ex = get_priority(ex_ch);
	                st_ch = pop();
	                int pr_st = get_priority(st_ch);
	                if(pr_st >= pr_ex){
	                	postfix[j] = st_ch;
	                    j++;
	                }
	                else{
	                     flag = 1;
	                     break;
	                }
	            }
	            if(flag == 1){
	                push(st_ch);
	                flag = 0;
	            }
	            push(ex_ch);
	        }
	    }
	    else{
	        postfix[j] = ex_ch;
	        j++;
	    }
	}
	while(!empty()){
	    postfix[j] = pop();
	    j++;
	}
	postfix[j] = '\0';
	cout << "Postfix: " << postfix << endl;
}

void stack::eval(){
	int k = 0;
	int ans;
	int ex_ch;
	int st_ch1,st_ch2;
	while(postfix[k] != '\0') {
		ex_ch = postfix[k];
	    if(ex_ch == '+' || ex_ch == '-' || ex_ch == '*' || ex_ch == '/'){
	    	st_ch1 = pop();
	        st_ch2 = pop();
	        if(ex_ch == '+'){
	        	ans = st_ch2 + st_ch1;
	        }
	        else if(ex_ch == '-'){
	            ans = st_ch2 - st_ch1;
	        }
	        else if(ex_ch == '*'){
	            ans = st_ch2 * st_ch1;
	        }
	        else if(ex_ch == '/'){
	            ans = st_ch2 / st_ch1;
	        }
	        push(ans);
	    }
	    else{
	        push(ex_ch-48);
	    }
	    k++;
	}
	while(!empty()){
	    cout << "Answer: " << pop();
	}
}

int main(){
    char infix[100];
    cout << "Infix: ";
    cin.getline(infix,98);
    stack s;
    cout << "Infix: " << infix << endl;
    s.convert(infix);
    s.eval();
}
