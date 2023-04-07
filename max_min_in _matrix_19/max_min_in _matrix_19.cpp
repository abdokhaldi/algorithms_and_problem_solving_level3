// max_min_in _matrix_19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void printMatrix(int Matrix[3][3],short rows,short cols) {
    cout << " THE MATRIX : \n ";

    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < rows; j++) {
            cout << Matrix[i][j] << "      ";
        }
    }
}

int MinNumberInMatrix( int Matrix[3][3], short rows, short cols){
    int Min = Matrix[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (Matrix[i][j] < Min){

                Min = Matrix[i][j];
           }
        }
    }
    return Min;
}


int  MaxNumberInMatrix(int Matrix[3][3], short rows, short cols) {
    int Max = Matrix[0][0];
     
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (Matrix[i][j] > Max) {

                Max = Matrix[i][j];
            }
        }
    }
    return Max;
}

int main()
{

    int Matrix[3][3] = { {4,56,32},{34,78,90},{32,1,99 } };

    printMatrix(Matrix, 3, 3);

    cout << "\n the Min number in the matrix is " << MinNumberInMatrix(Matrix, 3, 3) << endl;

    cout << "\n the Max number in the matrix is " << MaxNumberInMatrix(Matrix, 3, 3) << endl;

}
