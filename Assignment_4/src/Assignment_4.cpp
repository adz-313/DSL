//============================================================================
// Name        : Assignment_4.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node
{
	int prn;
	string name;
	node * next;
};

class Llist
{
	node * head;
	//int cntr;
	public:
		Llist(){
		head = NULL;
		}
		void insert_all(int &);
		void insert_prez();
		void insert_sec();
		void insert_pos(int);
		void delete_prez();
		void delete_pos(int);
		void delete_sec();
		void display();
		node* puthead();
		void reverse(node *);
		void concat(Llist);
		void sort();
};

void Llist::insert_all(int & cntr)
{
	node * newnode, *temp;
	cout<<"Enter the PRN and name of President: ";
	char choice = 'y';
	int flag = 1;
	while(choice == 'y' || choice == 'Y')
	{
		cntr++;
		newnode = new node;
		cin >> newnode->prn >> newnode->name ;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = newnode;
			temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
		if(!flag)
			break;
		cout<<"Enter Member details? (Y/N) ? ";
		cin>>choice;
		if(choice == 'y' || choice == 'Y')
		{
			cout<<"Enter the PRN and name of Member: ";
		}
		else
		{
			cout<<"Enter the PRN and name of Secretary: ";
			choice = 'y';
			flag = 0;
		}
	}
}

void Llist::insert_prez()
{
	node * newnode;
	newnode = new node;
	cout<<"Enter the PRN and name of new President: "<<endl;
	cin>>newnode->prn>>newnode->name;
	newnode->next = head;
	head = newnode;
}

void Llist::insert_sec()
{
	node * temp, * newnode;
	temp = head;
	newnode = new node;
	cout<<"Enter the PRN and name of new Secretary: "<<endl;
	cin>>newnode->prn>>newnode->name;
	newnode->next = NULL;
	while(temp->next != NULL)
	{
		temp = temp->next;
		temp->next = newnode;
	}
}

void Llist::insert_pos(int p)
{
	node * temp;
	temp = new node;
	cout<<"Enter the PRN and name of the new member: "<<endl;
	cin>>temp->prn>>temp->name;
	if(p==1)
	{
		temp = head;
		head = head->next;
		return;
	}
	int cntr=0;
	temp = head;
	while(!temp)
	{
		cntr++;
		temp = temp->next;
	}
	if(p<1||p>cntr)
	{
		cout<<"Invalid node position, can't insert member"<<endl;
		return;
	}
	node * temp1;
	temp = head;
	temp1 = head->next;
	cntr = 2;
	while(!temp)
	{
		if(p == cntr)
			break;
		temp = temp1;
		temp1 = temp1->next;
		cntr++;
	}
	temp->next = temp1->next;
}

void Llist::display()
{
	if(!head)
	{
		cout<<"Empty";
		return;
	}
	else
	{
		node * temp;
		cout<<"PRN\tNAME"<<endl;
		for(temp=head; temp!=NULL; temp = temp->next)
		{
			cout<<temp->prn<<"\t"<<temp->name<<endl;
		}
	}
}

void Llist::delete_prez()
{
	if(!head)
		return;
	else
	{
		node * temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
}

void Llist::delete_sec()
{
	if(!head)
		return;
	else
	{
		node * temp = head;
		node * p = NULL;
		while(temp->next)
		{
			p = temp;
			temp = temp->next;
		}
		p->next = NULL;
		temp->next = NULL;
		delete temp;
	}
}

void Llist::delete_pos(int p)
{
	node * temp;
	if(p==1)
	{
		temp = head;
		head = head->next;
		delete temp;
		return;
	}
	int cntr=0;
	temp = head;
	while(temp!=NULL)
	{
		cntr++;
		temp = temp->next;
	}
	if(p<1||p>cntr)
	{
		cout<<"Invalid node position, can't delete"<<endl;
		return;
	}
	node * temp1;
	temp = head;
	temp1 = head->next;
	cntr = 2;
	while(!temp)
	{
		if(p == cntr)
			break;
		temp = temp1;
		temp1 = temp1->next;
		cntr++;
	}
	temp->next = temp1->next;
	delete temp;
}

node* Llist::puthead()
{
	return head;
}

void Llist::reverse(node *head)
{
	if(!head)
		return;
	else
	{
		reverse(head->next);
		cout<<head->prn<<"\t"<<head->name<<endl;
	}
}

void Llist::sort()
{
	if(!head)
		return;
	else
	{
		node *i, *j;
		int prnt;
		string namet;
		for(i=head->next;i->next!=NULL;i=i->next)
		{
			for(j=head;j->next!=NULL;j=j->next)
			{
				if(j->prn > j->next->prn)
				{
					prnt=j->prn;
					namet=j->name;
					j->prn=j->next->prn;
					j->name=j->next->name;
					j->next->prn=prnt;
					j->next->name=namet;
				}
			}
		}
	}
}

void Llist::concat(Llist l)
{
	node * temp;
	temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = l.head;
	sort();
	display();
}

int main()
{
	int cntr1, cntr2, choice, memloc;
	Llist l1, l2;
	while(1)
	{
		cout<<"Menu: "<<endl;
		cout<<"1. Create lists"<<endl;
		cout<<"2. Insert new president"<<endl;
		cout<<"3. Insert new secretary"<<endl;
		cout<<"4. Insert new member"<<endl;
		cout<<"5. Remove president"<<endl;
		cout<<"6. Remove secretary"<<endl;
		cout<<"7. Remove member"<<endl;
		cout<<"8. Display lists"<<endl;
		cout<<"9. Number of students in list"<<endl;
		cout<<"10. Reverse lists"<<endl;
		cout<<"11. Get details of member"<<endl;
		cout<<"12. Concatenate lists"<<endl;
		cout<<"13. Exit"<<endl<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter list l1: "<<endl;
				l1.insert_all(cntr1);
				break;
			case 2:
				l1.insert_prez();
				cntr1++;
				break;
			case 3:
				l1.insert_sec();
				cntr1++;
				break;
			case 4:
				cout<<"Enter location at which member is to be inserted: ";
				cin>>memloc;
				l1.insert_pos(memloc);
				cntr1++;
				break;
			case 5:
				l1.delete_prez();
				cntr1--;
				break;
			case 6:
				l1.delete_sec();
				cntr1--;
				break;
			case 7:
				cout<<"Enter member location to be deleted: ";
				cin>>memloc;
				l1.delete_pos(memloc);
				cntr1--;
				break;
			case 8:
				l1.display();
				break;
			case 9:
				cout<<"Number of students in list l1: "<<cntr1<<endl;
				//cout<<"Number of students in list l2: "<<cntr2<<endl;
				//cout<<"Total number of students: "<<cntr1+cntr2<<endl;
				break;
			case 10:
				cout<<"Reversing list l1: "<<endl;
				cout<<"PRN\tNAME"<<endl;
				l1.reverse(l1.puthead());
				//cout<<"Reversing list l2: "<<endl;
				//cout<<"PRN\tNAME"<<endl;
				//l2.reverse(l2.puthead());
				break;
			case 11:
				break;
			case 12:
				cout<<"Enter list l2 for concatenation: "<<endl;
				l2.insert_all(cntr2);
				cout<<"Concatenating lists: "<<endl;
				l1.concat(l2);
				break;
			case 13:
				exit(0);
			default:
				cout<<"Invalid choice, try again"<<endl;
				break;
		}
	}
	return 0;
}
