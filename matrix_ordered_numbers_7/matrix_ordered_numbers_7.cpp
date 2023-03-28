// matrix_ordered_numbers_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void fillMatrixWithOrderedNumbers(int arr[3][3] , int rows,int cols) {
    int counter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols;j++) {
            counter++;
            arr[i][j] = counter;
         }
    }
}
void printMatrix(int arr[3][3], int rows, int cols) {
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
           cout <<  arr[i][j] << "     ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3];

    fillMatrixWithOrderedNumbers(arr,3,3);
    printMatrix(arr,3,3);

}

