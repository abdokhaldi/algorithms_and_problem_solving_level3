

#include <iostream>

using namespace std;


int ReadNumber() {
    short Number;
    cout << "enter the number to count in matrix : \n";
    cin >> Number;
    return Number;
}
int  RandomNumber(int From, int To) {
    int Random = rand() % ( To - From + 1 ) + From;
    return Random;
}
void FillMatrix(int Matrix[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols;j++) {
            Matrix[i][j] = RandomNumber(0, 9);
        }
    }
}


void printMatrix(int Matrix[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout << Matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

int countNumberInMatrix(int Matrix[3][3], short rows, short cols, int Number) {
    
    int count = 0;

   
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < rows; j++) {
            if (Matrix[i][j] == Number) {
                count += 1;
            }
        }
    }
    return count;
}

int main()
{
    int Number = ReadNumber();

    int Matrix[3][3] ;

    cout << "Matrix : \n";
    FillMatrix(Matrix,3,3);
    printMatrix(Matrix, 3, 3);

    cout << endl;

    cout << "count  " << Number << " in Matrix is " << countNumberInMatrix(Matrix, 3, 3, Number);
    
    
}

