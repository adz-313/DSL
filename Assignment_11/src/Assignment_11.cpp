//============================================================================
// Name        : Assignment_11.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define MAX 100

int main(){
    int *attend_stud[MAX];
    char arr[5];
    int x;
    int cnt = 0;
    cout << "Enter Roll Nos: ";
    while(1){
        cin.getline(arr,5);
        if(strcmp(arr,"stop") == 0){
            break;
        }
        x = atoi(arr);
        attend_stud[cnt] = new int(x);
        cnt++;
        //cin.ignore(1);
    }
    int i;
    cout << "Present Students: ";
    for(i=0;i<cnt;i++){
        cout << *attend_stud[i] << " ";
    }
    cout << endl << "Enter Roll No. to be Searched: ";
    cin >> x;
    int flag = 0;
    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            for(i=0;i<cnt;i++){
                if(x == *attend_stud[i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                cout << "Found at: " << i;
            }
            else{
                cout << "Not Found.";
            }
            break;

        case 2:
            int j = 0;
            attend_stud[cnt] = new int(x);
            while(x != *attend_stud[j]){
                j++;
            }
            if(j == cnt){
                cout << "Not Found.";
            }
            else{
                cout << "Found at: " << j;
            }
            break;

    }
}
