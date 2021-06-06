//============================================================================
// Name        : Assignment_4.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<math.h>
using namespace std;

class polynomial{
	int num;
	int *p;
	int *c;
    friend void add(polynomial t1,polynomial t2,int n);
    friend int distinct(polynomial t1,polynomial t2);
    friend istream &operator>>(istream &din,polynomial &a);
    friend ostream &operator<<(ostream &dout,polynomial b);
public:
	void eval();
	void sor_t();
	void multi(polynomial t);
	void distinct();
};

istream &operator>>(istream &din, polynomial &a){
    static int count =1;
    cout << "Enter number of Terms " << count << " :" ;
	cin >> a.num;
	a.p=new int[a.num];
	a.c=new int[a.num];
	int i;
	for(i=0;i<a.num;i++){
		cout << "Enter Coefficient of " << i << " Term: ";
		cin >>  a.c[i] ;

		cout << "Enter Power of " << i << " Term: ";
		cin >>  a.p[i] ;

	}
	count++;
	return cin;
}

ostream &operator<<(ostream &dout,polynomial b){
    int i;
	for(i=0;i<b.num;i++){
		cout <<  b.c[i]  << "x" <<  b.p[i];
		if(i!=(b.num-1)){
			cout << "+";
		}
	}
	cout << "\n";
	return cout;
}

void polynomial::eval(){
	int ans=0;
	int x;
	cout << "Enter x: ";
	cin >> x;
	for(int i=0;i<num;i++){
		ans+=(*(c+i))*(pow(x,(*(p+i))));
		}
	cout << "Answer is: " << ans << endl;

}

void polynomial::sor_t(){
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(*(p+i)<*(p+j)){
                swap(*(p+i),*(p+j));
                swap(*(c+i),*(c+j));
            }
        }
    }
}

void polynomial::multi(polynomial t){
    int ansc[50];
    int ansp[50];
    int fc[50];
    int fp[50];
    int k=0;
    for(int i=0;i<num;i++){
        for(int j=0;j<t.num;j++){
            ansp[k]=p[i]+t.p[j];
            ansc[k]=c[i]*(t.c[j]);
            int m=0;
            while(m<k){
                if(ansp[m]==ansp[k]){
                ansc[m]+=ansc[k];
                --k;
                }
                else{
                    m++;
                }
            }
            k++;
        }
    }

    for(int a=0;a<k;a++){
        cout << ansc[a] << "x" << ansp[a] << "+" << endl ;
    }
}

void add(polynomial t1,polynomial t2,int n){
    int ansc[n],ansp[n];
    int i=0;
    int j=0;
    int k=0;
        while(i+j<=(t1.num+t2.num))
        {
            if(t1.p[i]==t2.p[j])
            {
                ansp[k]=t1.p[i];
                ansc[k]=t1.c[i]+t2.c[j];
                j++;
                i++;
                k++;
            }
            else
            {
                    if(t1.p[i]>t2.p[j])
                    {
                        ansp[k]=t1.p[i];
                        ansc[k]=t1.c[i];
                        i++;
                        k++;

                    }
                    else
                    {
                        ansp[k]=t2.p[j];
                        ansc[k]=t2.c[j];
                        j++;
                        k++;

                    }
            }
        }
    for(int l=0;l<n;l++){
    	cout << ansc[l] << "x" << ansp[l] << "+";
    }
    cout << endl;
}

int distinct(polynomial t1,polynomial t2){
    int cnt=0;
    int p=t1.num+t2.num;
    int x[p];
    int i;
    for(i=0;i<t1.num;i++){
        x[i]=t1.p[i];
    }
    for(int j=0;j<t2.num;j++){
        x[i]=t2.p[j];
        i++;
    }

    for(int i=0;i<p;i++){
        for(int j=i+1;j<p;j++){
            if(x[i]<x[j]){
                swap(x[i],x[j]);
            }
        }
    }

    for(int l=0;l<p;l++){
        if(x[l]!=x[l+1]){
            cnt++;
        }
    }
    cout << "Distinct Elements are: " << cnt << endl;
    return cnt;
}

int main() {
	cout << "MENU: " << endl;
	cout << "Enter 1 for INPUT: " << endl;;
	cout << "Enter 2 to view our INPUT: " << endl;
	cout << "Enter 3 to EVALUATE FIRST POLYNOMIAL: " << endl;
	cout << "Enter 4 to EVALUATE SECOND POLYNOMIAL: " << endl;
	cout << "Enter 5 to ADD POLYNOMIALS: " << endl;
	cout << "Enter 6 to MULTIPLY POLYNOMIALS: " << endl;

	polynomial obj1,obj2;
	int choice;
	do{

		cout << "Enter choice: ";
		cin >> choice;
		int n;
		switch(choice){
			case 1: cin >> obj1 >> obj2;
					obj1.sor_t();
					obj2.sor_t();
					break;

			case 2:	cout << "Sorted Output for Polynomial 1 is: " << obj1;
					cout << "Sorted Output for Polynomial 2 is: " << obj2;
					break;

			case 3:	obj1.eval();
					break;

			case 4:	obj2.eval();
					break;

			case 5:	n=distinct(obj1,obj2);
					add(obj1,obj2,n);
					break;

			case 6: obj1.multi(obj2);
					break;

			deault: cout << "INVALID CHOICE. ";
			}

	}while(choice<7);
}
