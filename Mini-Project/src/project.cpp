//============================================================================
// Name        : mini_project.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdio.h>
#include<ctime>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include<cstdlib>
using namespace std;

typedef struct issue{
    int roll;
    char bname[25];
    int iss_date;
}issue;
issue i;
void print_issue(issue obj)
{
	cout<<"\n";
    cout << obj.roll << endl << obj.bname << endl << obj.iss_date;
}

/*void scan_issue(issue *obj,char* n,int r,int dat){
    obj->iss_date = dat;
    strcpy(obj->bname,n);
    obj->roll = r;
}*/


//*********************************************************************************************************************************************************************************

typedef struct book{
    char name[25];
    int copy;
}book;

//*********************************************************************************************************************************************************************************

void scan(book *obj){
	cout<<"\n";
    cout << "Name: ";
    cin.getline(obj->name,25);
    cout << "Copy: ";
   cin>> obj->copy;
    cin.ignore(1);
}

void show(book obj){
    cout << obj.name << "\t" << obj.copy << endl;
}

//*********************************************************************************************************************************************************************************

class student_node{
	char name[25];
	int age;
	int roll;
	char dept[5];
    long pass;
    int iss_date;
	student_node* next;
	student_node* prev;
public:
	student_node(char *n,int a,int rol,char* dep,long p,int date){
		strcpy(name,n);
		age = a;
		roll = rol;
		strcpy(dept,dep);
		pass= p;
		iss_date = date;
		next = prev = NULL;
	}
	student_node(){
        //blank
	}
	void print();
	friend class Student;
	friend class Admin;
};

//*********************************************************************************************************************************************************************************

void student_node::print(){

	cout<<"\n\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Roll No: " << roll << endl;
    cout << "Department: " << dept << endl;
    cout << "Pass: " << pass << endl;
}

//*********************************************************************************************************************************************************************************

class Student
{
protected:
	student_node* shead;
public:
	Student(){
		shead = NULL;
	}
	void stud_page(int);
	void stud_login(int);
	bool valid_pass(long);
	int check_val(int,int);
	void issue_book(int);
	void donate_book(int);
	void e_library();
	void pr_book();
	void novels();
	void math_books();
	void eff_think_books();
	void edu_videos();

};

//*********************************************************************************************************************************************************************************

void Student::stud_login(int d)
{
	cout<<"******************************** STUDENT LOGIN PAGE***************************"<<endl;
	fstream fobj;
	switch(d)
		{
	        case 1:
	            fobj.open("stud_fe.txt",ios::in|ios::binary);
	            break;

	        case 2:
	            fobj.open("stud_ce.txt",ios::in|ios::binary);
	            break;

	        case 3:
	            fobj.open("stud_it.txt",ios::in|ios::binary);
	            break;

	        case 4:
	            fobj.open("stud_entc.txt",ios::in|ios::binary);
	            break;
		}
	    if(fobj.fail()){
	        cout << "Unable to read from file." << endl;
	        return;
		}
	    int roll,flag=0;
	    long p;
	    cout<<"\nEnter Roll no : ";cin>>roll;
       cout<<"\nEnter Password : ";cin>>p;
	    student_node var;
	    while(fobj.read((char*)&var,sizeof(var)))
	    {
	    	if(roll==var.roll && p==var.pass)
	    	{
	    		fobj.close();
	    		flag = 1;
	    		stud_page(d);
	    	}
	    }
	    if(flag==0)
	    	cout<<"\nInvalid Username or password"<<endl;
}


void Student::stud_page(int d)
{
	int n;

	system("clear");
    cout<<"********************************* STUDENT PAGE ******************************"<<endl;
   do
   {
    cout<<"\n\n1) Issue Book\n"
    	<<"2) Donate Book\n"
		<<"3) E-Library\n"
		<<"4) Programming Tutorials\n"
		<<"5) Log Out"<<endl;
    cin>>n;

    switch(n)
    {
    case 1 : issue_book(d);break;
    case 2 : donate_book(d);break;
    case 3 : e_library();break;
    case 4 : edu_videos();break;
    case 5 : return;
    default : cout<<"\nEnter a valid choice!"<<endl;
    }
  }while(1);
}

int Student::check_val(int d,int r)
{
    fstream fobj;
    switch(d)
	{
        case 1:
            fobj.open("stud_fe.txt",ios::in|ios::binary);
            break;

        case 2:
            fobj.open("stud_ce.txt",ios::in|ios::binary);
            break;

        case 3:
            fobj.open("stud_it.txt",ios::in|ios::binary);
            break;

        case 4:
            fobj.open("stud_entc.txt",ios::in|ios::binary);
            break;
	}
    if(fobj.fail()){
        cout << "Unable to read from file." << endl;
        return -1;
	}
    student_node var;
    while(fobj.read((char*)&var,sizeof(student_node))){
        if(r == var.roll){
            fobj.close();
            return 1;
        }
    }
    fobj.close();
    return 0;
}

void Student::issue_book(int d)
{
	system("clear");
	cout<<"***************************** ISSUE BOOK ******************************"<<endl;
	issue iss;
    cout << "\nEnter Student Roll No. to continue: " << endl;
    cin >> iss.roll;
    if(check_val(d,iss.roll) == 0){
        cout << "\nError 404: Student not Found.\n";
        return;
    }
    fstream fobj;
    switch(d)
	{
        case 1:
            fobj.open("books_fe.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;

        case 2:
            fobj.open("books_ce.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;

        case 3:
            fobj.open("books_it.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;

        case 4:
            fobj.open("books_entc.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;
	}
    if(fobj.fail()){
        cout << "\nConnection Error." << endl;
        return;
    }
    book s;
    fobj.seekp(0,ios::beg);
    while(fobj.read((char*)&s,sizeof(s))){
        show(s);
    }
    char arr[20];
    int flag = 0;
    cout << "\n\n\nEnter book to be Issued: ";
    cin.ignore(1);
    cin.getline(arr,20);
    fobj.clear();
    fobj.seekp(0,ios::beg);
    while(fobj.read((char*)&s,sizeof(s))){
        if(strcmp(arr,s.name) == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << "\nError 404: Book not Found." << endl;
    }
    else if(flag == 1){
        int pos = fobj.tellp();
        cout << s.name << "\t" << s.copy << endl;
        if(s.copy > 0){
            --s.copy;
            //fobj.clear();
            //cout << "Pos: " << fobj.tellp() << endl << s.copy << endl;
            fobj.seekp(pos-32,ios::beg);
            //cout << "Pos: " << fobj.tellp();
            fobj.write((char*)&s,sizeof(s));
            strcpy(iss.bname,s.name);
            cout << "\nEnter Issue Date: \n";
            cin >> iss.iss_date;
            fstream fvar;
            fvar.open("issued_books.txt",ios::out|ios::binary|ios::app);
            fvar.write((char*)&iss,sizeof(issue));
            fvar.close();
        }
        else{
            cout << "\nBook out of Stock." << endl;
        }
    }
    fobj.close();
}

void Student::donate_book(int d)
{
	int n;
	system("clear");
	cout<<"****************************** DONATE BOOK ***************************"<<endl;
	cout<<"\n\n\nYour generous donation will help the needy!!"<<endl;
	cout << "\n\nPlease enter Number of Books to be Donated: \n";
	cin >> n;
	cin.ignore(1);
	book b[10];
	fstream fobj;
	switch(d)
	{
        case 1:
            fobj.open("books_fe.txt",ios::out|ios::binary|ios::app);
            break;

        case 2:
            fobj.open("books_ce.txt",ios::out|ios::binary|ios::app);
            break;

        case 3:
            fobj.open("books_it.txt",ios::out|ios::binary|ios::app);
            break;

        case 4:
            fobj.open("books_entc.txt",ios::out|ios::binary|ios::app);
            break;
	}
    if(fobj.fail()){
        cout << "Connection Error." << endl;
        return;
    }
    for(int i=0;i<n;i++){
        scan(&b[i]);
        fobj.write((char*)&b[i],sizeof(book));
    }
}

void Student::e_library()
{
	int n;
	system("clear");

	cout<<"\n************************* WELCOME TO E-LIBRARY*************************"<<endl;
	cout<<"\n\n";
	cout<<"1) Programming Books\n"
		<<"2) Mathematics Reference\n"
		<<"3) Effective Thinking\n"
		<<"4) Novels"<<endl;
	cout<<"\n\nEnter your choice"<<endl;
	cin>>n;

	switch(n)
	{
	case 1 : pr_book();break;
	case 2 : math_books();break;
	case 3 : eff_think_books();break;
	case 4 : novels();break;
	default : cout<<"\nNot a valid choice!"<<endl;
	}
}

void Student::edu_videos()
{
	char video[50];
    system("clear");
    cin.ignore(1);

	cout<<"*************************** PROGRAMMING TUTORIALS **************************"<<endl;

	cout<<"\n\n1) Android Development(Android)\n"
		<<"2) Java Programming - Beginners (Java)\n"
		<<"3) C++ Programming (C++)\n"
		<<"4) Python Programming (Python)\n"
		<<"5) Data Structures and Algorithms (DSA)"<<endl;
	cout<<"\n\nEnter your choice (as given in parenthesis) :"<<endl;

	cin.getline(video,50);

	string str = "open ";
	str = str + video + ".mp4";
	const char* command = str.c_str();
	system(command);

}

void Student::novels()
{
	char book[100];
	system("clear");
	cin.ignore(1);

				cout<<"*************************** E-LIBRARY[NOVELS] ****************************"<<endl;
				cout<<"\n\n1) The Immortals of MELUHA(Meluha)\n"
					<<"2) The Secret of Nagas(Nagas)\n"
					<<"3) The Oath of Vayuputras(Oath)"<<endl;

				cout<<"\n\nEnter your choice(name as given in parenthesis) : ";
				cin.getline(book,100);

				string str = "open ";
				str = str + book + ".pdf";

				const char* command = str.c_str();
				cout<<"\nOpening "<<book<<endl;

				system(command);
}

void Student::eff_think_books()
{
	char book[100];
	system("clear");
	cin.ignore(1);

			cout<<"*************************** E-LIBRARY[EFFECTIVE THINKING] ****************************"<<endl;
			cout<<"\n\n1) 5 Elements of Effective Thinking(5Elements)\n"
				<<"2) Law of Success(Success)\n"
				<<"3) The Art and Craft of Problem Solving(ProblemSolving)\n"
				<<"4) Thinking Skills(Thinking)\n"
				<<"5) Think Smarter(ThinkSmarter)\n"<<endl;

			cout<<"\n\nEnter your choice(name as given in parenthesis) : ";
			cin.getline(book,100);

			string str = "open ";
			str = str + book + ".pdf";

			const char* command = str.c_str();
			cout<<"\nOpening "<<book<<endl;

			system(command);
}

void Student::math_books()
{
	char book[100];
	system("clear");
	cin.ignore(1);

		cout<<"*************************** E-LIBRARY[MATHEMATICS] ****************************"<<endl;
		cout<<"\n\n1) Schaum's Discrete Mathematics(DMRef)\n"
			<<"2) Discrete Mathematics and Applications(Discrete)\n"
			<<"3) Discrete Mathematics Solutions(DMSOL)"<<endl;

		cout<<"\n\nEnter your choice(name as given in parenthesis) : ";
		cin.getline(book,100);

		string str = "open ";
		str = str + book + ".pdf";

		const char* command = str.c_str();
		cout<<"\nOpening "<<book<<endl;

		system(command);
}

void Student::pr_book()
{
	char book[100];
	system("clear");
    cin.ignore(1);
	cout<<"*************************** E-LIBRARY[PROGRAMMING] ****************************"<<endl;
	cout<<"\n\n1) Programming with C++(C++)\n"
		<<"2) Head-First Java(Java)\n"
		<<"3) Data Structures and Algorithms in C++(DSAC++)\n"
		<<"4) Head-First Android(Android)\n"
		<<"5) Introduction to Algorithms(Algorithms)\n"
		<<"6) Clean Code(CleanCode)\n"
		<<"7) Data Structures and Algorithms Made Easy(DSAEASY)"<<endl;
	cout<<"\n\nEnter your choice(name as given in parenthesis) : ";
	cin.getline(book,100);

	string str = "open ";
	str = str + book + ".pdf";

	const char* command = str.c_str();
	cout<<"\nOpening "<<book<<endl;

	system(command);
}

//*********************************************************************************************************************************************************************************

class admin_node{
	char dept[4];
	char pass[10];
	admin_node *next;
public:
	admin_node(char* dep){
		strcpy(dept,dep);
		next = NULL;
	}
	friend class Admin;
};

//*********************************************************************************************************************************************************************************

class Admin:public Student
{
	admin_node* ahead;
public:
	Admin(){
		ahead = new admin_node("FE");
		admin_node* p = ahead;
		p->next = new admin_node("CE");
		p = p->next;
		p->next = new admin_node("IT");
		p = p->next;
		p->next = new admin_node("ENTC");
	}
	void add_at_end(char*,int,int,char*,long,int,int);
	void delete_student(int);
	void new_stud(int);
	void view_stud(int);
	int calc_penalty();
	void pay_fine(int);
	void add_book(int);
	void disp_book(int);
	int check_val(int,int);
	void book_cntr(int);
	void connect(int);
	void issue_book(int);
	void return_book(int);
	void admin_page(int);
	int admin_login();
	void admin_pass();
};

//*********************************************************************************************************************************************************************************

void Admin::add_at_end(char *n,int a,int rol,char* dep,long pas,int s,int date)
{
	student_node* p;
	p = new student_node(n,a,rol,dep,pas,date);
	fstream fobj;
	switch(s)
	{
        case 1:
            fobj.open("stud_fe.txt",ios::out|ios::binary|ios::ate|ios::app);
            break;

        case 2:
            fobj.open("stud_ce.txt",ios::out|ios::binary|ios::ate|ios::app);
            break;

        case 3:
            fobj.open("stud_it.txt",ios::out|ios::binary|ios::ate|ios::app);
            break;

        case 4:
            fobj.open("stud_entc.txt",ios::out|ios::binary|ios::ate|ios::app);
            break;
	}
	if(fobj.fail())
    {
        cout << "Unable to write to file." << endl;
        return;
	}
	fobj.write((char*)p,sizeof(student_node));
	fobj.close();

	student_node* q = shead;
	if(q == NULL)
    {
		q = p;
	}
	else{
		while(q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}

void Admin::delete_student(int d)
{
	fstream fobj;
	fstream fobj2;

	switch(d)
		{
	        case 1:
	            fobj.open("stud_fe.txt",ios::in|ios::binary);
	            break;

	        case 2:
	            fobj.open("stud_ce.txt",ios::in|ios::binary);
	            break;

	        case 3:
	            fobj.open("stud_it.txt",ios::in|ios::binary);
	            break;

	        case 4:
	            fobj.open("stud_entc.txt",ios::in|ios::binary);
	            break;
		}
	    if(fobj.fail()){
	        cout << "Unable to read from file." << endl;
	        return;
		}
	    int roll;
	    cout<<"\nEnter roll number to delete : ";cin>>roll;
	    fobj2.open("temp.txt",ios::in|ios::binary|ios::app|ios::out);
	    if(fobj2.fail())
	    {
	    	cout<<"\nProblem in file"<<endl;
	    }

	    student_node s;
	    while(fobj.read((char*)&s,sizeof(s)))
	    {
	    	if(roll != s.roll)
	    	{
	    		fobj2.write((char*)&s,sizeof(s));
	    	}
	    }

	    fobj.close();
	    fobj2.close();


	    switch(d)
	    {
	    case 1 : remove("stud_fe.txt");
	    		 rename("temp.txt","stud_fe.txt");break;
	    case 2 : remove("stud_ce.txt");
	             rename("temp.txt","stud_ce.txt");break;
	    case 3 : remove("stud_it.txt");
	    		 rename("temp.txt","stud_it.txt");break;
	    case 4 : remove("stud_entc.txt");
	    		 rename("temp.txt","stud_entc.txt");break;

	    }

}

void Admin::new_stud(int flag)
{
    cout << "Enter Student Name: ";
	char name[25];
	cin.getline(name,23);
	cout << "Enter Student Age: ";
	int age;
	cin >> age;
	cout << "Enter Student Roll No: ";
	int roll;
	cin >> roll;
	cin.ignore(1);
	char dept[4];
	cout << "Enter Student Department: ";
	cin.getline(dept,4);
    unsigned seed = time(NULL);
    srand(seed);
    long pass = rand();
    cout<<"\nYour unique Password is : "<<pass<<endl;
	add_at_end(name,age,roll,dept,pass,flag,NULL);
}

void Admin::view_stud(int d)
{

    fstream fobj;
    switch(d)
	{
        case 1:
            fobj.open("stud_fe.txt",ios::in|ios::binary);
            break;

        case 2:
            fobj.open("stud_ce.txt",ios::in|ios::binary);
            break;

        case 3:
            fobj.open("stud_it.txt",ios::in|ios::binary);
            break;

        case 4:
            fobj.open("stud_entc.txt",ios::in|ios::binary);
            break;
	}
    if(fobj.fail()){
        cout << "Unable to read from file." << endl;
        return;
	}

    student_node var;
    cout<<"\nDisplaying Student Records : "<<endl;
    while(fobj.read((char*)&var,sizeof(student_node))){
        var.print();
    }
    fobj.close();
}

int Admin::calc_penalty()
{
    int flag = 0;
    int nod=0,x;
    cout << "\nCurrent Date(dd-mm-yyyy): \n";
    int cur_date;
    cin >> cur_date;
    cout << "\nEnter Roll No: \n";
    int roll;
    cin >> roll;
    fstream fobj;
    fobj.open("issued_books.txt",ios::in|ios::binary);
	if(fobj.fail()){
        cout << "\nConnection Error." << endl;
        return -1;
    }
    issue i;
    while(fobj.read((char*)&i,sizeof(issue))){
        if(roll == i.roll){
            flag = 1;
            break;
        }
    }
    fobj.close();
    if(flag == 0){
        cout << "\nError 404: Record not Found." << endl;
        return -1;
    }
    else{
        int iss_date = i.iss_date;
        cur_date = cur_date/100;
        iss_date = iss_date/100;
        if(iss_date%100 == cur_date%100){
            cur_date = cur_date/100;
            iss_date = iss_date/100;
            nod = cur_date - iss_date;
        }
        else if(iss_date%100 < cur_date%100){
            if(iss_date%100 == 2){
                x = iss_date/100;
                x = 28 - x;
            }
            else if(iss_date%100 == 1 || iss_date%100 == 3 || iss_date%100 == 5 || iss_date%100 == 7 || iss_date%100 == 8 || iss_date%100 == 10 ||iss_date%100 == 12){
                x = iss_date/100;
                x = 31 - x;
            }
            else {
                x = iss_date/100;
                x = 30 - x;
            }
            nod = cur_date/100 + x;
        }
        return nod;
    }
}

void Admin::pay_fine(int d)
{
    int offset = calc_penalty();
    int fine = 0;
    if(offset > 7){
        fine = (offset-7)*10;
        cout << "\nFine is: " << fine << endl;
    }
    else{
        cout << "\nNo Fine." << endl;
    }

}

void Admin::add_book(int d)
{
    fstream fobj;
    switch(d)
	{
        case 1:
            fobj.open("books_fe.txt",ios::out|ios::binary|ios::app);
            break;

        case 2:
            fobj.open("books_ce.txt",ios::out|ios::binary|ios::app);
            break;

        case 3:
            fobj.open("books_it.txt",ios::out|ios::binary|ios::app);
            break;

        case 4:
            fobj.open("books_entc.txt",ios::out|ios::binary|ios::app);
            break;
	}
	if(fobj.fail()){
        cout << "\nConnection Error." << endl;
        return;
    }
    book b;
    scan(&b);
    fobj.write((char*)&b,sizeof(book));
    fobj.close();
}

void Admin::disp_book(int d)
{
    fstream fobj;
    switch(d)
	{
        case 1:
            fobj.open("books_fe.txt",ios::in|ios::binary);
            break;

        case 2:
            fobj.open("books_ce.txt",ios::in|ios::binary);
            break;

        case 3:
            fobj.open("books_it.txt",ios::in|ios::binary);
            break;

        case 4:
            fobj.open("books_entc.txt",ios::in|ios::binary);
            break;
	}
	if(fobj.fail()){
        cout << "\nConnection Error." << endl;
        return;
    }
    book b;
    cout << "Name" << "\t" << "No. of Copies" << endl;
    while(fobj.read((char*)&b,sizeof(book))){
        show(b);
    }
    fobj.close();
}

int Admin::check_val(int d,int r)
{
    fstream fobj;
    switch(d)
	{
        case 1:
            fobj.open("stud_fe.txt",ios::in|ios::binary);
            break;

        case 2:
            fobj.open("stud_ce.txt",ios::in|ios::binary);
            break;

        case 3:
            fobj.open("stud_it.txt",ios::in|ios::binary);
            break;

        case 4:
            fobj.open("stud_entc.txt",ios::in|ios::binary);
            break;
	}
    if(fobj.fail()){
        cout << "Unable to read from file." << endl;
        return -1;
	}
    student_node var;
    while(fobj.read((char*)&var,sizeof(student_node))){
        if(r == var.roll){
            fobj.close();
            return 1;
        }
    }
    fobj.close();
    return 0;
}

void Admin::book_cntr(int d)
{
    fstream fobj;
    switch(d)
	{
        case 1:
            fobj.open("books_fe.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;

        case 2:
            fobj.open("books_ce.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;

        case 3:
            fobj.open("books_it.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;

        case 4:
            fobj.open("books_entc.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;
	}
    if(fobj.fail()){
        cout << "\nConnection Error." << endl;
        return;
    }
    book s;
    fobj.clear();
    fobj.seekp(0,ios::beg);
    while(fobj.read((char*)&s,sizeof(s))){
        show(s);
    }
    char arr[10];
    int flag = 0;
    cout << "\n\n\nEnter book to be Issued: ";
    cin.ignore(1);
    cin.getline(arr,10);

    //cout << fobj.tellp() << endl;
    fobj.clear();
    fobj.seekp(0,ios::beg);
    //cout << fobj.tellp() << endl;
    while(fobj.read((char*)&s,sizeof(s))){
        if(strcmp(arr,s.name) == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << "\nError 404: Book not Found." << endl;
        return;
    }
    else if(flag == 1){
        //cout << fobj.tellp() << endl;
        int pos = fobj.tellp();
        cout << s.name << "\t" << s.copy << endl;
        if(s.copy > 0){
            s.copy--;
            //fobj.clear();
            cout << s.name << "\t" << s.copy << endl;
            fobj.seekp(pos-32,ios::beg);
            fobj.write((char*)&s,sizeof(book));
        }
        else{
            cout << "\nBook out of Stock." << endl;
        }
    }
    strcpy(i.bname,s.name);
    fobj.close();
}

void Admin::connect(int d)
{
    //int roll,iss_date;

    cout << "\nEnter Student Roll No. to continue: " << endl;
    cin >> i.roll;
    if(check_val(d,i.roll) == 0){
        cout << "\nError 404: Student not Found.\n";
        return;
    }
    else{
        book_cntr(d);
        cout << "\nEnter Issue Date: \n";
        cin >> i.iss_date;
        fstream fvar;
        fvar.open("issued_books.txt",ios::out|ios::binary|ios::app);
        if(fvar.fail()){
            cout << "\nConnection Error." << endl;
            return;
        }
        fvar.write((char*)&i,sizeof(issue));
        fvar.close();
        return;
    }
}

void Admin::issue_book(int d)
{
    system("clear");
	cout<<"***************************** ISSUE BOOK ******************************"<<endl;
    connect(d);
    issue i;
    fstream fobj;
    fobj.open("issued_books.txt",ios::in|ios::binary|ios::app);
    if(fobj.fail()){
        cout << "\nConnection Error." << endl;
        return;
    }
    while(fobj.read((char*)&i,sizeof(issue))){
        print_issue(i);
    }
    fobj.close();
}

void Admin::return_book(int d)
{
    system("clear");
	cout<<"***************************** RETURN BOOK ******************************"<<endl;
    fstream fobj;
    switch(d)
	{
        case 1:
            fobj.open("books_fe.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;

        case 2:
            fobj.open("books_ce.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;

        case 3:
            fobj.open("books_it.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;

        case 4:
            fobj.open("books_entc.txt",ios::in|ios::out|ios::binary|ios::ate);
            break;
	}
    if(fobj.fail()){
        cout << "\nConnection Error." << endl;
        return;
    }
    book s;
    fobj.seekp(0,ios::beg);
    while(fobj.read((char*)&s,sizeof(s))){
        show(s);
    }
    char arr[10];
    int flag = 0;
    cout << "\n\n\nEnter book to be Returned: ";
    cin.getline(arr,10);
    fobj.clear();
    fobj.seekp(0,ios::beg);
    while(fobj.read((char*)&s,sizeof(s))){
        if(strcmp(arr,s.name) == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << "\nError 404: Book not Found." << endl;
    }
    else if(flag == 1){
        int pos = fobj.tellp();
        cout << s.name << "\t" << s.copy << endl;
        s.copy++;
        fobj.clear();
        fobj.seekp(pos-16,ios::beg);
        fobj.write((char*)&s,sizeof(book));
    }
    fobj.close();
}

void Admin::admin_pass()
{
    admin_node *temp;
    temp = ahead;
    strcpy(temp->pass,"fedept");
    temp = temp->next;
    strcpy(temp->pass,"csdept");
    temp = temp->next;
    strcpy(temp->pass,"itdept");
    temp = temp->next;
    strcpy(temp->pass,"entcdept");
}

int Admin::admin_login()
{
    char dept[15];
    int flag = 0,cnt =1;
    admin_pass();
    system("clear");
    cout<<"********************************* ADMINISTRATOR LOGIN *****************************"<<endl;
    cout<<"\n\nEnter Department : ";
    cin>>dept;
    cin.ignore(1);
    char *p = getpid("\nEnter password : ");

    admin_node *t = ahead;

    while(t!=NULL)
    {
        if(strcmp(p,t->pass)==0 && strcmp(dept,t->dept)==0)
        {
            flag = 1;

            break;
        }
        else
            t = t->next;
        cnt++;
    }

    if(flag==1)
        return cnt;
    else
        cout<<"\nPassword Incorrect!!"<<endl;

    return -1;
}

void Admin::admin_page(int dept)
{
  int ch;
  Admin a;
  system("clear");
  do
  {
	  cout<<"\n\n\n";

      cout<<"------------------------ Administrator Page ---------------------\n";

      cout<<"\n1) Add student record.\n"
          <<"2) View student.\n"
          <<"3) Add book.\n"
          <<"4) Display books.\n"
          <<"5) Issue book.\n"
          <<"6) Return book.\n"
          <<"7) Pay fine.\n"
		  <<"8) Delete Student.\n"
          <<"9) Exit.\n";
      cin>>ch;

      switch(ch)
      {
      case 1 :
            cin.ignore(1);
            new_stud(dept);
            break;

      case 2:
            view_stud(dept);
            break;

      case 3:
            cin.ignore(1);
            add_book(dept);
            break;

      case 4:
            disp_book(dept);
            break;

      case 5:
            cin.ignore(1);
            issue_book(dept);
            break;

      case 6:
            return_book(dept);
            break;

      case 7:
            pay_fine(dept);
            break;

      case 8: delete_student(dept);
            break;

      case 9 : return;

      }
  }while(1);
}

//*********************************************************************************************************************************************************************************

int main() {
	int choice,see,dept;
	    Student fe,cs,it,entc,s;
	    Admin a;
         system("clear");

	    cout<<"--------------------------- SMART LIBRARY ----------------------------\n";

	    cout<<"\n1) Administrator Login\n"
	        <<"2) Student Login\n";
	    cin>>choice;

	    switch(choice)
	    {
	    case 1 : see=a.admin_login();

	            switch(see)
	            {
	            case 1 : cout<<"\nIn FE record\n";a.admin_page(1);break;
	            case 2 : cout<<"\nIn CS record\n";a.admin_page(2);break;
	            case 3 : cout<<"\nIn IT record\n";a.admin_page(3);break;
	            case 4 : cout<<"\nIn ENTC record\n";a.admin_page(4);break;
	            default : cout<<"\nNot authorized to login"<<endl;
	            }
	            break;

	    case 2 : cout<<"\nEnter your department : \n"
	    		     <<"\n\n1) First Year\n"
					 <<"2) Computer Engineering\n"
					 <<"3) Information Technology\n"
					 <<"4) Electronics & Telecommunications"<<endl;
	           cin>>dept;
	           switch(dept)
	           {
	           case 1 : cout<<"\nIn FE Records\n";fe.stud_login(1);break;
	           case 2 : cout<<"\nIn Computer Engineering Records\n";cs.stud_login(2);break;
	           case 3 : cout<<"\nIn Information Technology Records\n";it.stud_login(3);break;
	           case 4 : cout<<"\nIn ENTC Records\n";entc.stud_login(4);break;
	           default : cout<<"\nOOPS!! Wrong choice"<<endl;
	           }
	    	    break;

	           default : cout<<"\nNot a valid Option!"<<endl;
	    }

       system("clear");
       cout<<"************************ LOGGED OUT SUCCESSFULLY*******************"<<endl;
       cout<<"\n\nThank You for using SMART LIBRARY"<<endl;

	 return 0;


}
