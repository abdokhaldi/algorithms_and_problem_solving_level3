
#include <iostream>
#include <vector>

using namespace std; 

void FibonancciSeries(int Number) {
    int prev1 = 0 , prev2 = 1;
    cout << "1 |";
    for (int i = 0; i < Number; i++) {
        int fibonancciNumber = prev1 + prev2;
        cout << fibonancciNumber << " | ";
        prev1 = prev2;
        prev2 = fibonancciNumber;
      
    }
}


int main()
{
   FibonancciSeries(10);
   
}

