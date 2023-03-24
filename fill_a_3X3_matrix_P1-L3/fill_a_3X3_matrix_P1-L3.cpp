

#include<iostream>
#include<string>

using namespace std;

int RandomNumber(int From, int To) {
	int random = rand() % (To + From - 1) + From;
	return random;
}

void fillDimentionalArray(int arr[3][3], int rows, int cols) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {
			arr[i][j] = RandomNumber(1, 100);
		}

	}
}

void printDimentionalArray(int arr[3][3], int rows, int cols) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];
	fillDimentionalArray(arr, 3, 3);
	printDimentionalArray(arr, 3, 3);

	return 0;

}