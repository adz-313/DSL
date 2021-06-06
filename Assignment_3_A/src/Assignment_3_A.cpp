

#include<iostream>
#include<stdlib.h>
using namespace std;

class Sparsematrix
{
	int row,col,val;
	public:
		void accept();
		int getrow();
		int getval();
		void display();
		friend void transpose(Sparsematrix *);
		friend void addition(Sparsematrix *, Sparsematrix *);
};

void Sparsematrix::accept()
{
	cin>>row>>col>>val;
}

/*int Sparsematrix::getrow()
{
	return row;
}

int Sparsematrix::getval()
{
	return val;
}*/

void Sparsematrix::display()
{
	cout<<row<<"\t"<<col<<"\t"<<val<<endl;
}

void transpose(Sparsematrix *s)
{
	int i, j, noc, nov; //no. of columns, no. of non-zero values
	noc = s[0].col;
	nov = s[0].val;
	Sparsematrix result[nov+1];
	int rowterms[noc+nov], pos[noc+nov];//position of start


	result[0].row = noc;
	result[0].col = s[0].row;
	result[0].val = nov;
	if(nov>0)
	{
		for(i=0 ; i<noc+nov ; i++)
			rowterms[i]=0;
		for(i=1 ; i<=nov ; i++)
		{
			rowterms[s[i].col]++;
			pos[0]=1;
		}
		for(i=1 ; i<=nov ; i++)
			pos[i]=pos[i-1]+rowterms[i-1];
		for(i=1 ; i<=nov ; i++)
		{
			j=pos[s[i].col]++;
			result[j].row = s[i].col;
			result[j].col = s[i].row;
			result[j].val = s[i].val;
		}
		for(i=0 ; i<nov+1 ; i++)
			result[i].display();
	}
}

void addition(Sparsematrix *objs1, Sparsematrix *objs2)
{
	if(objs1[0].row == objs2[0].row && objs1[0].col == objs2[0].col)
	{
		int i=1, j=1, cntr=0;
		int val1 = objs1[0].val;
		int val2 = objs2[0].val;
		Sparsematrix result[val1 + val2 + 2];
		while(i < val1+1 && j < val2+2)
		{
			if((objs1[i].row >= objs2[j].row) && objs1[i].col > objs2[j].col)
			{
				result[cntr+1].row = objs2[j].row;
				result[cntr+1].col = objs2[j].col;
				result[cntr+1].val = objs2[j].val;
				j++;
				cntr++;
			}
			else if((objs1[i].row <= objs2[j].row) && objs1[i].col < objs2[j].col)
			{
				result[cntr+1].row = objs1[i].row;
				result[cntr+1].col = objs1[i].col;
				result[cntr+1].val = objs1[i].val;
				i++;
				cntr++;
			}
			else
			{
				if((objs1[i].val + objs2[j].val)!=0)
				{
					result[cntr+1].row = objs1[i].row;
					result[cntr+1].col = objs1[i].col;
					result[cntr+1].val = objs1[i].val + objs2[j].val;
				}
				i++;
				j++;
				cntr++;
			}
		}
		while(i<val1+1)
		{
			result[i].row = objs1[i].row;
			result[i].col = objs1[i].col;
			result[i].val = objs1[i++].val;
			cntr++;
		}
		while(j<val2+1)
		{
			result[j].row = objs2[j].row;
			result[j].col = objs2[j].col;
			result[j].val = objs2[j++].val;
			cntr++;
		}
		result[0].row = objs1[0].row;
		result[0].col = objs1[0].col;
		result[0].val = cntr;
		for(i=0;i<cntr+1;i++)
			result[i].display();
	}
	else
	{
		cout<<"Rows and columns of 1st and 2nd matrix are not equal!"<<endl;
		cout<<"Addition not possible!"<<endl;
	}
}

int main()
{
	int n1,n2,choice,flag;
	flag=1;
	cout<<"\nMenu: "<<endl;
	cout<<"1. Enter sparse matrices."<<endl;
	cout<<"2. Perform fast transpose. "<<endl;
	cout<<"3. Add sparse matrices. "<<endl;
	cout<<"4. Exit. "<<endl<<endl;
	while(1)
	{
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the number of non-zero elements for matrix 1: ";
				cin>>n1;
				cout<<"Enter the number of non-zero elements for matrix 2: ";
				cin>>n2;
				Sparsematrix *s1,*s2;
				s1 = new Sparsematrix[n1+1];
				s2 = new Sparsematrix[n2+1];

				cout<<"Enter sparse matrix 1: "<<endl;
				cout<<"Row\tColumn\tValue"<<endl;
				cout<<"--------------------------"<<endl;
				for(int i=0;i<n1+1;i++)
				{
					s1[i].accept();
				}
				/*
				for(int i=1;i<n1+1;i++)
				{
					if(s1[i].getrow()>s1[i+1].getrow())
					{
					cout<<"Error,sparse matrix s1 is not row major!"<<endl;
					cout<<"Please enter sparse matrix again."<<endl;
					flag=0;
					break;
					}
					else if(s1[i].getval()==0)
					{
					cout<<"Error, zero detected in sparse matrix s1!"<<endl;
					cout<<"Please enter sparse matrix with non-0 values."<<endl;
					flag=0;
					break;
					}
				}
				*/
				cout<<"Enter sparse matrix 2: "<<endl;
				cout<<"Row\tColumn\tValue"<<endl;
				cout<<"--------------------------"<<endl;
				for(int i=0;i<n2+1;i++)
				{
					s2[i].accept();
				}
				/*
				for(int i=1;i<n2+1;i++)
				{
					if(s2[i].getrow()>s2[i+1].getrow())
					{
					cout<<"Error,sparse matrix s2 is not row major!"<<endl;
					cout<<"Please enter sparse matrix again."<<endl;
					flag=0;
					break;
					}
					else if(s2[i].getval()==0)
					{
					cout<<"Error, zero detected in sparse matrix s2!"<<endl;
					cout<<"Please enter sparse matrix with non-0 values."<<endl;
					flag=0;
					break;
					}
				}
				*/
				break;
			case 2:
				cout<<"Transpose of sparse matrix 1:"<<endl;
				cout<<"\n\nRow\tColumn\tValue"<<endl;
				cout<<"------------------"<<endl;
				transpose(s1);

				cout<<"\nTranspose of sparse matrix 2:"<<endl;
				cout<<"\n\nRow\tColumn\tValue"<<endl;
				cout<<"------------------"<<endl;
				transpose(s2);

				break;
			case 3:
				cout<<"\nSum of entered sparse matrices is: "<<endl;
				cout<<"\n\nRow\tColumn\tValue"<<endl;
				cout<<"------------------"<<endl;
				addition(s1,s2);
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"Invalid choice entered, please try again."<<endl;
		}
	}
	return 0;
}

/* int apos = 0, bpos = 0;
            sparse_matrix result = new sparse_matrix(row, col);

            while (apos < len && bpos < b.len) {

                // if b's row and col is smaller
                if (data[apos][0] > b.data[bpos][0] ||
                  (data[apos][0] == b.data[bpos][0] &&
                   data[apos][1] > b.data[bpos][1]))

                {

                    // insert smaller value into result
                    result.insert(b.data[bpos][0],
                                  b.data[bpos][1],
                                  b.data[bpos][2]);

                    bpos++;
                }

                // if a's row and col is smaller
                else if (data[apos][0] < b.data[bpos][0] ||
                (data[apos][0] == b.data[bpos][0] &&
                  data[apos][1] < b.data[bpos][1]))

                {

                    // insert smaller value into result
                    result.insert(data[apos][0],
                                  data[apos][1],
                                  data[apos][2]);

                    apos++;
                }

                else {

                    // add the values as row and col is same
                    int addedval = data[apos][2] + b.data[bpos][2];

                    if (addedval != 0)
                        result.insert(data[apos][0],
                                      data[apos][1],
                                      addedval);
                    // then insert
                    apos++;
                    bpos++;
                }
            }

            // insert remaining elements
            while (apos < len)
                result.insert(data[apos][0],
                              data[apos][1],
                              data[apos++][2]);

            while (bpos < b.len)
                result.insert(b.data[bpos][0],
                              b.data[bpos][1],
                              b.data[bpos++][2]);
  */
