// write a program to print a 3x3 matrex with random numbers and then print the sum of matrix

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int randomNumber(int from,int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}

void fillMatrix(int arr[3][3], short rows , short cols) {
    for (short i = 0; i < rows;i++) {
        for (short j = 0; j < cols;j++) {
            arr[i][j] = randomNumber(1, 10);
        }
    }
}

void printMatrix(int arr[3][3], short rows, short cols) {
    cout << "the matrix : \n";
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout << setw(3) << arr[i][j] ;
        }
        cout << endl;
    }
}

int sumMatrix(int arr[3][3], short rows, short cols) {
    int sum = 0;
    for (short i = 0; i < rows;i++) {
        for (short j = 0; j < cols;j++) {
            sum += arr[i][j];
         }
    }
    return sum;
}
int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    fillMatrix(arr, 3, 3);
    printMatrix(arr, 3, 3);
   cout << endl << " sum of matrix is : " << sumMatrix(arr, 3, 3);
}

