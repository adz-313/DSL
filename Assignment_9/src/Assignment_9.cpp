//============================================================================
// Name        : Assignment_9.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 5

class Queue{
	int arr[MAX];
	int front,rear;
public:
	Queue(){
		front = -1;
		rear = -1;
	}
	void enque(int x){
		if(!full()){
			if(front == -1){
				front++;
			}
			rear++;
			arr[rear] = x;
		}
		else{
			cout << "Queue is Full.";
		}
	}

	int full(){
		if(rear == MAX-1){
			return 1;
		}
		return 0;
	}

	int deque(){
		if(!empty()){
			int x = arr[front];
			if(front == rear){
				front = rear = -1;
			}
			else{
				front++;
			}
			return x;
		}
		else{
			cout << "Queue is Empty.";
			return -1;
		}
	}

	int empty(){
		if(rear == -1){
			return 1;
		}
		return 0;
	}
};

int main(){
	int x;
	Queue q;
	for(int i=0;i<6;i++){
		cout << "Data: ";
		cin >> x;
		q.enque(x);

	}
	for(int i=0;i<6;i++){
		cout << q.deque() << endl;
	}

}
