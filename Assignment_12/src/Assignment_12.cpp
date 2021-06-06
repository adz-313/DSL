//============================================================================
// Name        : Assignment_12.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 100

void bubble_sort(float num[],float arr[],int n){
	for(int i=0;i<n;i++){
		arr[i] = num[i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

void selection_sort(float num[],float arr[],int n){
	for(int i=0;i<n;i++){
		arr[i] = num[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				swap(arr[i],arr[j]);
			}
		}
	}
}

void display(float arr[],int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	float num[MAX],arr[MAX];
	int n;
	cout << "Enter n: ";
	cin >> n;
	for(int i=0;i<n;i++){
		num[i] = rand();
	}
	cout << "Unsorted: ";
	display(num,n);
	int choice;
	cout << "1. Selection Sort." << endl;
	cout << "2. Bubble Sort." << endl;
	cout << "3. Exit." << endl;
	while(1){
		cout << "Enter choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				bubble_sort(num,arr,n);
				cout << "Bubble Sorted:   ";
				display(arr,n);
				break;

			case 2:
				selection_sort(num,arr,n);
				cout << "Selection Sorted:   ";
				display(arr,n);
				break;

			case 3:
				return 0;
		}
	}
}
