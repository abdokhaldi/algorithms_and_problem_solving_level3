
#include <iostream>
using namespace std;

int RandomNumber(int From, int To) {
    int random = rand() % (To - From + 1) + From;
    return random;
}

void fillMatrix(int arr[5][5], short row, short col) {
    for (short i = 0; i < row;i++) {
        for (short j = 0; j < col;j++) {
            arr[i][j] = RandomNumber(1, 100);
         }
    }
}


void printMatrix(int arr[5][5], short row, short col) {
    cout << " Matrix 1 :   \n";
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
           cout  <<   arr[i][j] << "      ";
        }
        cout << endl;
    }
}

void MidleRow(int arr[5][5], short row , short col) {

    cout << "\n the midle row : \n";
    int MiddleRow = row / 2;
    for (short i = 0; i < col; i++) {

        printf(" %0*d   ", 2, arr[MiddleRow][i]);
         }
       cout <<  endl;
  }
    
void MidleCol(int arr[5][5], short row, short col) {

    cout << "\n the midle col : \n";
    int MiddleCol = col / 2;
    
         for (short j = 0; j < col; j++) {

             printf(" %0*d   ", 2, arr[j][MiddleCol]);
          }
       // cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[5][5];

    fillMatrix(arr, 5, 5);
    printMatrix(arr, 5,5);
    MidleRow(arr,5,5);
    MidleCol(arr, 5, 5);
}

