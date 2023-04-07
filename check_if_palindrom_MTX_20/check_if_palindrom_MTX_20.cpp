

#include <iostream>

using namespace std;

void PrintMatrix(int Matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows;i++) {
		for (short j = 0; j < rows; j++) {
			cout << Matrix[i][j] << "    ";
		}
		cout << endl;
	}
}

int isPalindromMatrix(int Matrix[3][3], short rows, short cols) {
	
	for (short i = 0; i < rows; i++) {
		
		for (short j = 0; j < cols/2; j++ ) {
			
			if (Matrix[i][j] != Matrix[i][cols - 1 - j ])
				return false;
		}
	}
	return true;
}

int main()
{
	int Matrix[3][3] = { {1,2,1} , {2,3,2} , {4,3,4} };

	PrintMatrix(Matrix, 3, 3);

	if (isPalindromMatrix(Matrix, 3, 3))
		cout << "Yes : it is a palindrom matrix /n " ;
	else 
	     cout << "No : it is Not palindrom matrix /n " ;

}
