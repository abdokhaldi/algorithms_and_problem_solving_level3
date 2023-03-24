// sum_matrex_row_in_single_arr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int randomNumber(int From, int To) {
    int random = rand() % (To + From - 1) + From;
    return random;
}

void fillMatrix(int arr[3][3], short rows,short cols) {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols;j++) {
            arr[i][j] = randomNumber(1,100);
        }

    }
}

void printMatrix(int arr[3][3], short rows, short cols) {
    cout << " the folowing is a 3x3 matrix : " << endl;
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

int  sumRow(int arr[3][3] , short rowNumber, short cols) {
    int sum = 0;
    for (int j = 0; j < cols;j++) {
        sum += arr[rowNumber][j];
     }   
    return sum;
}

void sumMatrexRowsInArray(int arr[3][3], int arrSum[3], short rows, short cols) {
    for (int i = 0; i < rows;i++) {
        arrSum[i] = sumRow(arr, i, cols);
    }
}

void printRowsInArray( int arrSum[3], short rows) {
    cout << "the folowing is a single array contains the sum of each row in 3x3 matrex \n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << " sum = " << arrSum[i] << endl;
    }
}

int main()
{
    
    srand((unsigned)time(NULL));

    int arr[3][3];
    int  arrSum[3];

    fillMatrix(arr, 3, 3);
    printMatrix(arr, 3, 3);
    sumMatrexRowsInArray(arr, arrSum, 3, 3);
    printRowsInArray(arrSum, 3);

}

