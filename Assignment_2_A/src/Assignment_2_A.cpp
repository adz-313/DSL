//============================================================================
// Name        : assignment.cpp
// Author      : adiya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;
int i, j;

class matrix {

public:
	int row, col;
	float m[10][10];
	void getdata();
	void caltrace();
	void displaymatrix();
	void transpose();
	void saddlepoint();
	void checkuppertriangular();
	void addmatrix(matrix, matrix);
	void submatrix(matrix, matrix);
	void multmatrix(matrix, matrix);
};
void matrix::getdata()
{
	cout << "Enter the no. of rows: ";
	cin >> row;
	cout << "Enter the number of columns: ";
	cin >> col;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << "Enter m[" << i << "]  [" << j << "]: ";
			cin >> m[i][j];
		}
	}
}
void matrix::caltrace()
{
	float trace=0;
	i = 0; j = 0;
	do
	{
		trace += m[i][j];
		i++;
		j++;
	} while (i < row || j < col);
	cout << "The Sum of diagonal elements is: " << trace << endl;
}
void matrix::displaymatrix()
{

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << m[i][j];
		}
		cout << endl;
	}
}
void matrix::transpose()
		{
			cout << "The transpose is as follows: " << endl;
			cout << endl;
			for (i = 0; i < col;i++)
			{
				for(j=0;j<row;j++)
				{
					cout << m[j][i] << " ";
				}
		cout << endl;
			}
		}
void matrix::saddlepoint()
{
	float min_row = m[0][0];int x = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (min_row > m[i][j])
			{
				min_row = m[i][j];
				x = j;
			}
		}
		int k;
		for (k = 0; k < row; k++)
		{
			if (min_row < m[k][x])
			{
				break;
			}
		}
		if (k == row - 1)
		{
			cout << "Saddle point is present" << endl;
			cout << "Saddle point is: " << min_row << endl;
		}
	}

}
void multmatrix(matrix c1, matrix c2)
{
	matrix f;
	f.row = c1.row;
	f.col = c2.col;
	if (c1.col == c2.row)
	{
		for (i = 0; i < c1.row; i++)
		{
			for (j = 0; j < c2.col; j++)
			{
				f.m[i][j] = 0;
				for (int k = 0; k < c2.row; k++)
				{
					f.m[i][j] += c1.m[i][k] * c2.m[k][j];
				}
			}
		}
		f.displaymatrix();
	}
	else { cout << "Matrix cannot be multiplied"; }
}
void addmatrix(matrix m1, matrix m2)
{
	matrix y;
	y.row = m1.row;
	y.col = m1.col;
	if (m1.row == m2.row && m1.col == m2.col)
	{
		for (i = 0; i < m1.row;i++)
		{
			for (j = 0; j < m1.col; j++)
			{
				y.m[i][j] = m1.m[i][j] + m2.m[i][j];
			}
		}
		y.displaymatrix();
	}
	else { cout << "The matrices cannot be added" << endl; }
}
void submatrix(matrix s1, matrix s2)
{
	matrix y;
	y.row = s1.row;
	y.col = s1.col;
	if (s1.row == s2.row && s1.col == s2.col)
	{
		for (i = 0; i < s1.row; i++)
		{
			for (j = 0; j < s1.col; j++)
			{
				y.m[i][j] = s1.m[i][j] - s2.m[i][j];
			}
		}
		y.displaymatrix();
	}
	else { cout << "The matrices cannot be subtracted" << endl; }
}
void matrix::checkuppertriangular()
{
	if(i>j && i!=j)
	{

		if(m[i][j]=0)
		{
			cout<<"it is upper triangular matrix" << endl;
			for (i = 0; i < row;i++)
			{
				for(j=0;j< col;j++)
					{
						cout<<"it is upper triangular matrix" << endl;
					}
			}
		}
	}

					else{ cout<<"it is not upper triangular matrix" << endl;
				}


}



int main()
{
	int v,o=0;
	matrix h1, h2;
	h1.getdata();
	h2.getdata();
	cout << "Select the operation to be performed" << endl;
	cout << "1. Calculate the trace" << endl;
	cout << "2. Calculate the transpose" << endl;
	cout << "3. Check if saddle point is present" << endl;
	cout << "4. Add the two matrices" << endl;
	cout << "5. Subtract the two matrices" << endl;
	cout << "6. Multiply the two matrices" << endl;
	cout << "7. check whether given matrices are upper triangular  " << endl;
	cout << "Enter choice: ";
	do {
		cin >> v;
		switch (v) {
		case 1: {h1.displaymatrix(); h1.caltrace(); cout << endl; h2.displaymatrix(); h2.caltrace(); }break;
		case 2: {h1.transpose(); cout << endl; h2.transpose(); }break;
		case 3: {h1.displaymatrix(); h1.saddlepoint(); cout << endl; h2.displaymatrix(); h2.saddlepoint(); }break;
		case 4: {addmatrix(h1, h2); }break;
		case 5: {submatrix(h1, h2); }break;
		case 6: {multmatrix(h1, h2); }break;
		case 7: {h1.displaymatrix(); h1.checkuppertriangular(); cout << endl; h2.displaymatrix(); h2.checkuppertriangular(); }break;
		default: {cout << "Invalid choice"; }
		}
	} while (o != 5);
}

