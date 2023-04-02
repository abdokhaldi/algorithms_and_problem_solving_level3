#include <iostream>;
using namespace std;

void printMatrix(int Matrix[3][3], short rows, short cols) {

	for (int i = 0; i < rows;i++) {
		for (int j = 0; j < cols; j++) {
			cout << Matrix[i][j] << "      ";
		}
		cout << endl;
	}
}

bool IsIdentityMatrix(int Matrix[3][3], short rows, short cols) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < rows; j++) {
			if (i==j && Matrix[i][j] !=1 ) {
				return false;
			}
			else if (i!=j && Matrix[i][j] !=0) {
				return false;
			 }
		}
	}
	return true ;
}

int main() {

	int Matrix[3][3] = { {1,0,0}, {0,1,0}, {0,0,1} };

	cout << " Matrix : \n";
	printMatrix(Matrix,3,3);

	cout << " the result : \n";

	if (IsIdentityMatrix(Matrix, 3, 3)) {
		cout << "Yes : the Matrix is identity \n";
	}
	else {
		cout << " No : the matrix is not identity \n";
	}

}