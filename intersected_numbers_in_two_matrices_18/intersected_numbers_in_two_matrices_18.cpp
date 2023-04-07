// intersected_numbers_in_two_matrices_18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


void PrintMatrix(int Matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < rows; j++) {
            cout << Matrix[i][j] << "              ";
        }
        cout << endl;
    }
}
bool isExistsNumber(int Matrix1[3][3], int Number ,short rows, short cols) {
   
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < rows; j++) {

            if (Matrix1[i][j] == Number) {
                return  true;
            }
        }
    }

        return false;
}


void PrintInterSectionNumbersInMatrices(int Matrix1[3][3],int Matrix2[3][3], short rows, short cols) {

    int Number=0;

    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < rows; j++) {
            Number = Matrix1[i][j];
            if ( isExistsNumber(Matrix2,Number,3,3)) {
                cout << Number <<  "    ";
            }
        }
       
    }
   
}

int main()
{
    int Matrix1[3][3] = { {32,34,65}, {22,12,53}, {88,41,13} };
    int Matrix2[3][3] = { {22,99,65}, {22,87,53}, {88,41,15} };

    cout << "Matrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << endl;

    cout << "Matrix 2 : \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << endl;

    cout <<  " intersected Numbers in two Matrices are : ";
    PrintInterSectionNumbersInMatrices(Matrix1, Matrix2, 3, 3);

    cout << endl;
}

