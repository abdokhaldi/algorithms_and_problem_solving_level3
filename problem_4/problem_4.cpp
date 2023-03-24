
//   write a program to fill 3x3 matrex with random nummbers and print them then sum each collumn in the matrix and print results

#include <iostream>

 using namespace std;

int RandomNumber(int From, int To) {
	int random = rand() % (To + From - 1) + From;
	return random;
}


void FillMatrexByRandomNums(int Arr[3][3] , int Rows, int Cols) {
	for (int i = 0; i < Rows;i++) {

		for (int j = 0; j < Cols;j++) {
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrex(int Arr[3][3], int Rows, int Cols) {

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {
			cout << Arr[i][j] << "   ";
		}
		cout << endl;
	}
}

int SumCols(int Arr[3][3], int Rows, int ColNumber) {
	int Sum = 0;

	for (int i = 0; i < Rows;i++) {
		Sum += Arr[i][ColNumber];
	}
	return Sum;
}


void PrintSumCols(int Arr[3][3], int Rows , int ColNumber) {

	cout << "the folowing is the sum of each row in matrix : " << endl;

	for (int j = 0; j < Rows; j++) {
		cout << " Row " << j + 1 << " Sum = " << SumCols(Arr ,Rows, j) << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));

	int Arr[3][3];

	FillMatrexByRandomNums(Arr,3,3);
	PrintMatrex(Arr, 3, 3);
	PrintSumCols(Arr, 3, 3);



}