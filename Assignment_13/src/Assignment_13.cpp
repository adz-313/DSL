//============================================================================
// Name        : Assignment_13.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 100

int partition(float num[],int low,int up){
	int p = low+1;
	int q = up;
	float pivot = num[low];
	while(p <= q){
		while(num[p] <= pivot && p <= up){
			p++;
		}
		while(num[q] > pivot){
			q--;
		}
		if(p < q){
			swap(num[p],num[q]);
		}
	}
	swap(num[low],num[q]);
	return q;
}

void quick_sort(float num[],int low,int up){
	if(low <= up){
		int k = partition(num,low,up);
		quick_sort(num,low,k-1);
		quick_sort(num,k+1,up);
	}
}

void display(float num[],int n){
	for(int i=0;i<n;i++){
		cout << num[i] << " ";
	}
}

int main() {
	float num[MAX];
	int n;
	cout << "Enter n: ";
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> num[i];
	}
	display(num,n);
	cout << endl;
	quick_sort(num,0,n-1);
	display(num,n);
}
