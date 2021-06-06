//============================================================================
// Name        : assignment.cpp
// Author      : adiya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

class strin{
char arr[100];
char str[100];
char cpy[100];
char con[100];
char sub[100];
char sub2[100];
char rev[100];
char freq;
char del[100];
char cdel[100];
char rep[100];

public:
void input();
void strcopy();
void concat();
void subst_r();
void equa_l();
void reverse();
void lenght();
void frequency();
void d_el();
void c_del();
void replac_e();
void palindrome();

};

void strin::input(){
	cin.ignore(1);
	cout << "Enter string 1: ";
	cin.getline(arr,98,'\n');



	cout << "Enter string 2: ";
		cin.getline(str,98,'\n');

}


void strin::strcopy(){


	int i=0;

	while(arr[i]!='\0'){
			cpy[i]=arr[i];
			i++;
		}
	cpy[i]='\0';
		cout << "Copied string is: " << cpy << endl;
}

void strin::concat(){
	int i=0;
	while(arr[i]!='\0'){
		con[i]=arr[i];
		i++;
	}


	int j=0;
		while(str[j]!='\0'){
			con[i]=str[j];
			i++;
			j++;
		}
		con[i]='\0';
		cout << "Concatenated string is: " << con << endl;


}

void strin::subst_r(){
	cin.ignore(1);

	int i=0;

	int fir[100];
		int a=0;
		int j=0;
		int x,b;
		int m=0;
		int c=0;
		int r=0;
		//cin.getline(arr,98,'\n');
		cout << "Enter substring: ";
	    cin.getline(sub,98,'\n');
	    while(sub[a]!='\0'){
	          a++;
	          }
	          //cout << a <<endl;

	    /*while(arr[m]!='\0'){
	        if(arr[m]==sub[0]){
	            fir[c]=m;
	            c++;
	        }
	        m++;
	    }*/

	      while(arr[j]!='\0'){
	    if(arr[j]==sub[0] && arr[j+a-1]==sub[a-1]){
	         for(x=0;x<a;x++){
	            sub2[x]=arr[j+x];
	         }
	         sub2[x]='\0';
	         goto down;

	    }

	j++;
	}


	down:
	    //cout << x << endl << sub2 << endl;
	 b=strcmp(sub2,sub);
	if(b==0){
	    cout << "Yes, it is a substring" << endl;
	}
	else{
	    cout << "No, it is not a substring." << endl;
	}

}

void strin::equa_l(){
	int i=0;
	while(arr[i]!='\0'){
		if(arr[i]==str[i]){
			cout << "Strings are equal" << endl;
			break;
		}
		else{
			cout << "Strings are not equal" << endl;
			break;
		}
		i++;
	}

}

void strin::reverse(){
	int i=0;
		while(arr[i]!='\0'){
			i++;

		}

	int j=0;
	while(arr[j]!='\0'){
		rev[j]=arr[i-1];
		i--;
		j++;

			}
	rev[j]='\0';
	cout << rev << endl;
}

void strin::lenght(){
	int j=0;
		while(arr[j]!='\0'){
			j++;
		}
		cout << j << endl;
}

void strin::frequency(){
	cout << "Enter char to check frequency: " << endl;
	cin >> freq;

	int j=0;
	int cnt=0;
	while(arr[j]!='\0'){
		if(arr[j]==freq){
			cnt++;
		}
		j++;
	}
cout << cnt << endl;

}

void strin::d_el(){
int a,b,i;
int x=0;
int j;
int v=0;
cout << "Enter a: ";
cin >> a;
cout << "Enter b: ";
cin >> b;
while(arr[v]!='\0'){
	v++;
}
while(arr[x]!='\0'){
    x++;


for(i=0;i<=a;i++){
    del[i]=arr[i];
}
j=a+1;

for(i=i+b;arr[i]!='\0';i++)
{
	del[j]=arr[i];
	j++;
}

del[j]='\0';

}
cout << "New string is: " << del << endl;
}

void strin::c_del(){
char a;
cout << "Enter character: ";
cin >> a;
int i=0;

int j=0;
	while(arr[j]!='\0')
        {
            if(arr[j]!=a)
            {
            	cdel[i]=arr[j];
            	i++;
		}
    j++;
	}
	cdel[i]='\0';
	cout << cdel <<endl;




}

void strin::replac_e(){
    int u,l,n;
    cout << "Enter upper and lower limit of substring: ";
    cin >> u >> l;
    char rep[100];
    char x[100];
    cout << "Enter new string: " << endl;
    cin.ignore(1);
    cin.getline(x,98);
    int a=strlen(x);
    int b=strlen(arr);
    int c=b-u;
    cout << a << endl;
    int q,r,s;
    n=u-l;
    for(q=0;q<l;q++){
        rep[q]=arr[q];
    }
    for(r=0;r<a;r++){
        rep[r+q]=x[r];
        }

cout << r << endl;
cout << q << endl;



    for(s=q+r;arr[u]!='\0';s++){
        rep[s]=arr[u+1];
        u++;
    }
   rep[s]='\0';
    cout << rep << endl;


}

void strin::palindrome(){
    int a=strlen(arr);
int x=0;
int s=0;
for(int i=0;i<((a+1)/2);i++){
        if(arr[i]==arr[a-i-1]){

            if(arr[i]==' '){
                cout << "Invalid";
                break;
            }
            x++;
        }
        else{
            cout << "Not Palindrome";
            break;
        }
}
if(x==((a+1)/2)){
  cout << "Palindrome";
}
}

int main() {
int i;
do{	strin s;

	cout << "Menu:" << endl;
	cout << "Enter 1 for Input." << endl;
	cout << "Enter 2 for Copy." << endl;
    cout << "Enter 3 for Concatenation." << endl;
	cout << "Enter 4 for Substring." << endl;
	cout << "Enter 5 for Equal." << endl;
	cout << "Enter 6 for Frequency." << endl;
	cout << "Enter 7 for Delete." << endl;
    cout << "Enter 8 for Character Delete." << endl;
    cout << "Enter 9 for Replace." << endl;
	cout << "Enter 10 for Palindrome." << endl;
	cout << "Enter 0 to Exit program." << endl;
	cout << "\n";
	cout << "Enter your choice: " << endl;
	cin >> i;



    switch(i){
    case 1: s.input();break;
    case 2: s.strcopy();break;
    case 3: s.concat();break;
    case 4: s.subst_r();break;
    case 5: s.equa_l();break;
    case 6: s.frequency();break;
    case 7: s.d_el();break;
    case 8: s.c_del();break;
    case 9: s.replac_e();break;
    case 10: s.palindrome();break;
    case 0: break;
   default: cout << "Enter valid choice. ";break;
    }}while(i!=0);
	return 0;
}
