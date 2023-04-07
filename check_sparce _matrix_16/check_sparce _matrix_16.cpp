

#include <iostream>

using namespace std;



void printMatrix(int Matrix[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout << Matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

int countNumber(int Matrix[3][3], int Number, short rows,short cols)
{
    int countNumber = 0;

    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            if (Matrix[i][j] == Number) {
                countNumber += 1;
            }
        }
       
    }
    return countNumber;
}

bool isSparceMatrix( int Matrix[3][3] , short rows, short cols)
{
    short MatrixSize = rows * cols;    

    return (countNumber(Matrix, 0,3, 3) >= (MatrixSize / 2));
}


int main()
{
   
    int Matrix[3][3] = {{4,8,6}, {9,9,9} , {0,0,0}};

    cout << "Matrix : \n";
   
    printMatrix(Matrix, 3, 3);

    cout << endl;

    if (isSparceMatrix(Matrix,3,3) ) {
        cout << "Yes : the matrix is sparce \n ";
    }
    else {
        cout << "No : the Matrix is not Sparce \n";
    }

    
    cout << countNumber(Matrix,0,3,3);

}

