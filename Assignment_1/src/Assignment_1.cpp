//============================================================================
// Name        : assignment.cpp
// Author      : adiya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string.h>
using namespace std;
int n;
class test
{
public:
	string na;
	int roll;
	int marks;
    void getdata();
	void avg(test o[]);
	int max(test o[]);
    void min(test o[]);
	void f(int,test o[]);
	void a(test o[]);
};

void test::getdata()
	{
		cout<<"enter name \t";
		cin>>na;
		cout<<"enter roll \t";
		cin>>roll;
		cout<<"enter marks \t";
		cin>>marks;
	}

void test::a(test o[])
{
	int i;
		for(i=0;i<n;i++)
		{
			if(o[i].marks<0)
			{
				cout<<o[i].na<<" is absent"<<endl;
			}
		}
}
void test::f(int max,test o[])
{
	int j=0;
	int	i=0;
		int flag=0;
		int t=0;
		int k=0;
		 int arr[max+1];
		 for(i=0;i<max+1;i++)
		 {
		 	 arr[i]=0;
		 }
		 for(i=0;i<n;i++)
		 {
		 	 k=o[i].marks;
		 	 arr[k]++;
		 }
		 t=0;
		for(i=1;i<max+1;i++)
		{
			if(arr[i]>t)
			{
				t=arr[i];
			}
		}
		j=0;
		for(i=0;i<max+1;i++)
		{
			if(t==arr[i])
			{
				j++;
			}
		}
		flag=0;
		cout<<"marks scored by most of students is " << endl;
		for(i=0;i<max+1;i++)
		{
			if(t==arr[i])
			{
				if(flag==0)
				{
					cout<<i;
					flag++;
				}
				else
				{
					cout<<" or "<<i;
				}
			}
		}
		//cout<<" and their frequency is "<<j<<endl;
}
	void test::min(test o[])
	{
		int min=999;
		int i;
		for(i=1;i<n;i++)
		{
			if(o[i].marks>0)
			{
				if(o[i].marks<min)
				{
					min=o[i].marks;
				}
			}
		}
		cout<<"min marks are"<<min<<endl;
	}
	int test::max(test o[])
	{
		int max=o[0].marks;
		int i;
	for(i=1;i<n;i++)
	{
		if(o[i].marks>0)
		{
			if(o[i].marks>max)
			{
				max=o[i].marks;
			}
		}
	}
	return(max);
	}
void test::avg(test o[])
{
	int sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(o[i].marks>0)
		{
		sum=sum+o[i].marks;
		}
	}
	sum=sum/n;
	cout<<sum<<endl;
}
int main()
{
	cout<<"enter no of students"<<endl;
	cin>>n;
	test o[n];
	test obj;
	int i=0;
	for(i=0;i<n;i++)
	{
		o[i].getdata();
	}
	cout<<"average marks:-"<<endl;
	obj.avg(o);
	int k;
k=obj.max(o);
cout<<"max marks are"<<k<<endl;
	obj.min(o);
	obj.f(k,o);
	obj.a(o);
/*	int max=o[0].marks;
	for(i=1;i<n;i++)
	{
		if(o[i].marks>0)
		{
			if(o[i].marks>max)
			{
				max=o[i].marks;
			}
		}
	}
	cout<<"max marks are"<<max<<endl;
	int min=999;
		for(i=1;i<n;i++)
		{
			if(o[i].marks>0)
			{
				if(o[i].marks<min)
				{
					min=o[i].marks;
				}
			}
		}
		cout<<"min marks are"<<min<<endl;
		int j=0;
		i=0;
		int flag=0;
		int t=0;
		int k=0;
		 int arr[max+1];
		 for(i=0;i<max+1;i++)
		 {
		 	 arr[i]=0;
		 }
		 for(i=0;i<n;i++)
		 {
		 	 k=o[i].marks;
		 	 arr[k]++;
		 }
		 t=0;
		for(i=1;i<max+1;i++)
		{
			if(arr[i]>t)
			{
				t=arr[i];
			}
		}
		j=0;
		for(i=0;i<max+1;i++)
		{
			if(t==arr[i])
			{
				j++;
			}
		}
		flag=0;
		cout<<"marks scored by most of students is ";
		for(i=0;i<max+1;i++)
		{
			if(t==arr[i])
			{
				if(flag==0)
				{
					cout<<i;
					flag++;
				}
				else
				{
					cout<<" or "<<i;
				}
			}
		}
		cout<<" and their frequency is "<<j<<endl;


		for(i=0;i<n;i++)
		{
			if(o[i].marks<0)
			{
				cout<<o[i].n<<" is absent"<<endl;
			}
		} */
}


