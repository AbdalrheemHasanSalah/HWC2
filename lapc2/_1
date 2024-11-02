//Given : int A[4][4];

//fill matrix then :

//Write a code segment to find the maximum value in matrix A.
//Print the location of maximum value.
//Print the elements on the main diagonal.


#include <iostream>

using namespace std;

void fill(int a[][4]) {

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++)
			 cin >> a[r][c];
			//a[r][c] = (c + 1) * (r + 2);
	}
}
void display(int a[][4]) {
	cout << "matrix is"<<endl;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {

			cout << " " << a[r][c]<<" ";
		}
		cout << endl;
	}
}

int max(int a[][4]) {
	int max = a[0][0];

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (a[r][c] > max)
				max = a[r][c];
		}
	}
	return max;
}
void row_column_max(int a[][4], int max) {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (a[r][c] == max)
				cout << endl << "row " << r << " column " << c << endl<<endl;
		}
	}
}
void diagonal(int a[][4]) {
	cout << "cell of diagonal  is : " << endl;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (r == c)
				cout << a[r][c] << endl;
		}
	}

}
int main()
{
	int A[4][4];

	fill(A);
	display(A);
	int max_cell=max(A);
	cout << endl << "max number is :" << max_cell << endl;

	row_column_max(A, max_cell);
	diagonal(A);

		

}
