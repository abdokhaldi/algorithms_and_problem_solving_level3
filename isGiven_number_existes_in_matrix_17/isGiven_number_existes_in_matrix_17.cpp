// isGiven_number_existes_in_matrix_17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int ReadNumber()
{
    cout << "Please enter number to check ? \n";
    int Number ;
    cin >> Number;

    return Number;
}

void PrintMatrix(int Matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < rows; j++) {
            cout << Matrix[i][j] << "      ";
        }
     cout <<    endl;
    }
}

bool isGivenNumberExists(int Matrix[3][3], int Number,short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < rows; j++) {
            if (Matrix[i][j] == Number) {
                return true;
            }
        }
        cout << endl;
    }
   return  false;
}
int main()
{
    int Number = ReadNumber();
    int Matrix[3][3]{ {32,4,54} , {67,21,34}, {11,8,60} };

    PrintMatrix(Matrix, 3, 3);

    cout << endl;

    if (isGivenNumberExists(Matrix, Number, 3, 3)) {
        cout << "\n Yes : the number " << Number << " is exists in Matrix ";
    }else{
        cout << "\n No : the number " << Number << " is not exists in Matrix ";
    }
}

