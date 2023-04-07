


#include <iostream>
using namespace std;

void fibonancciSeries(int prev1 , int prev2 ,int Number) {
    
    int fibonancciNumber = 0;
    if(Number >0){
     fibonancciNumber = prev1 + prev2;
     prev2 = prev1;
    prev1 = fibonancciNumber;
    cout << fibonancciNumber << " ";
    fibonancciSeries(prev1, prev2, Number - 1);
    }
   
}

int main()
{
    
    fibonancciSeries(1, 0, 10);
}
