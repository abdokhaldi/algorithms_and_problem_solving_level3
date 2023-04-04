

#include <iostream>

using namespace std;

void printMatrix(int Matrix[3][3],short rows,short cols) {
    for (short i = 0; i < rows;i++) {
        for (short j = 0; j < cols;j++) {
            cout << Matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

bool isScalarMatrix(int Matrix[3][3], short rows, short cols) {
    int FirstDiagElement = Matrix[0][0];

    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            if (i==j && Matrix[i][j] != FirstDiagElement) {
                return false;
            }
            else if (i!=j && Matrix[i][j] != 0) {
                return false;
           }
        }
        
    }
    return true ;
}
int main()
{
    int Matrix[3][3] = { {7,0,0}, {0,7,0} , {0,0,7} };

    cout << "Matrix : \n";

    printMatrix(Matrix,3,3);

    cout << "Result : \n";
    if (isScalarMatrix(Matrix, 3, 3)) {
        cout << " Yes : it is a scalar matrix ";
    }
    else {
        cout << " No : it is not a scalar matrix ";
    }
}

