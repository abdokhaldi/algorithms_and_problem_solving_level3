// multiply_tow_matrices_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int RandomNumber(int from , int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}

void FillMatrix(int arr[3][3], int rows, int cols) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            arr[i][j] = RandomNumber(1,100);
        }
    }
}

void printMatrix(int arr[3][3], int rows, int cols) {
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %0*d   ", 2, arr[i][j]);
        }
        cout << endl; 
    }
}
 


void multiplyMatrices(int arr1[3][3], int arr2[3][3], int arr3[3][3], int rows, int cols) {
    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < cols; j++) {
            arr3[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));


    int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];

    cout << "Matrix 1 : \n";
    FillMatrix(Matrix1,3,3);
    printMatrix(Matrix1, 3, 3);

    cout << "\n Matrix 2 : \n";
    FillMatrix(Matrix2, 3, 3);
    printMatrix(Matrix2, 3, 3);

    cout << "\n Reasults \n";
    multiplyMatrices(Matrix1, Matrix2, MatrixResults, 3, 3);
    printMatrix(MatrixResults,3,3);
    
}

