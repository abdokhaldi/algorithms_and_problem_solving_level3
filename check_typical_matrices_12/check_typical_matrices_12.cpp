   
// check typical matrices

// write a program to print a 3x3 matrex with random numbers and then print the sum of matrix

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



int randomNumber(int from, int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}

void fillMatrix(int arr[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            arr[i][j] = randomNumber(1, 10);
        }
    }
}


void printMatrix(int arr[3][3], short rows, short cols) {

    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
}

bool checkTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3] , short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            if (Matrix1 != Matrix2) {
                return false;
             }
        }
       
    }

    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3], arr2[3][3];
    
    cout << " matrix 1 : \n";
    fillMatrix(arr1, 3, 3);
    printMatrix(arr1, 3, 3);

    cout << "matrix 2 : \n";
    fillMatrix(arr2, 3, 3);
    printMatrix(arr2, 3, 3);

   

    if (checkTypicalMatrices(arr1,arr2, 3,3) == true) {
        cout << " \n the Matrices are typical";
    }
    else {
        cout << " \n the Matrices are not typical";
    }



   

}

