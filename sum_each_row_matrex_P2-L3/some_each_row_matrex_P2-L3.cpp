
// write a program  to fill 3x3 Matrex by random numbers then sum each row

#include <iostream>
using namespace std;

int RandomNumber(int From, int To) {
    int random = rand() % (To + From - 1) + From;
    return random;
}

void FillDimentionalArray(int arr[3][3] , short rows,short cols) {
    
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            arr[i][j] = RandomNumber(1,100);
         }
        }
    
}

void printDimentionalArray(int arr[3][3], short rows, short cols) {

    for (short i = 0; i < rows; i++) {

        for (short j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int RowSum(int arr[3][3],short RowNumber, short cols) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += arr[RowNumber][j];
    }
    return sum;
}

void PrintSumEachRow(int arr[3][3], short rows, short cols) {

    
    
    for (int i = 0; i < cols; i++) {
        
      cout << "Row " << i + 1 << " sum " << RowSum(arr, i, cols) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillDimentionalArray(arr,3,3);
    printDimentionalArray(arr, 3, 3);

    cout << "\t\t ______________ sum each row in 3x3 matrix __________________ \n";

    PrintSumEachRow(arr, 3, 3);
    
}

