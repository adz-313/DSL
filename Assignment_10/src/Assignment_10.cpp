//============================================================================
// Name        : Assignment_10.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 10

class dequeue{
	int data[MAX];
	int front,rear;
public:
	dequeue(){
		front = rear = -1;
	}
	int fullF();
	int fullR();
	int empty();
	void enqueF(int);
	void enqueR(int);
	int dequeF();
	int dequeR();
	void display();
};

int dequeue::fullF(){
	if(front == 0){
		return 1;
	}
	return 0;
}

int dequeue::fullR(){
	if(rear == MAX-1){
		return 1;
	}
	return 0;
}

int dequeue::empty(){
	if(front == -1){
		return 1;
	}
	return 0;
}

void dequeue::enqueF(int x){
	if(!fullF()){
		if(empty()){
			front = rear = 0;
		}
		else{
			front--;
		}
		data[front] = x;
	}
	else if(!fullR()){
        int i = rear;
        while(i>=front){
            data[i+1] = data[i];
            i--;
        }
        data[i+1] = x;
        rear++;
	}
	else{
		cout << "Full";
	}
}

void dequeue::enqueR(int x){
	if(!fullR()){
		if(empty()){
			front = rear = 0;
		}
		else{
			rear++;
		}
		data[rear] = x;
	}
	else{
		cout << "Full";
	}
}

int dequeue::dequeF(){
	if(!empty()){
		int x = data[front];
		if(front == rear){
			front = rear = -1;
		}
		else{
			front++;
		}
		return x;
	}
	else{
		cout << "Empty";
		return -1;
	}
}

int dequeue::dequeR(){
	if(!empty()){
		int x = data[rear];
		if(front == rear){
			front = rear = -1;
		}
		else{
			rear--;
		}
		return x;
	}
	else{
		cout << "Empty";
		return -1;
	}
}

void dequeue::display(){
    if(!empty()){
        cout << "Queue: ";
        for(int i=front;i<=rear;i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "Empty" << endl;
    }
}

int main(){
	int ch,element;
	dequeue obj;
	cout << "1. Enque from Front" << endl;
	cout << "2. Enque from Rear" << endl;
	cout << "3. Deque from Front" << endl;
	cout << "4. Deque from Rear" << endl;
	cout << "5. Display Queue." << endl;
	cout << "6. Exit" << endl << endl;
	while(1){
		cout << "Enter choice: ";
		cin >> ch;
		switch(ch){
			case 1:
				cout << "Enter Data: ";
				cin >> element;
				obj.enqueF(element);
				break;

			case 2:
				cout << "Enter Data: ";
				cin >> element;
				obj.enqueR(element);
				break;

			case 3:
				cout << "Front: " << obj.dequeF() << endl;
				break;

			case 4:
				cout << "Rear: " << obj.dequeR() << endl;
				break;

            case 5:
				obj.display();
				break;

			case 6:
				return 0;
		}
	}
}
