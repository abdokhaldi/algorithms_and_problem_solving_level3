

#include <iostream>
using namespace std;

char readChar() {
    cout << "ener character : \n";
    char char1;
    cin >> char1;
    return char1;
}


bool isVowel(char Ch1) {

    Ch1 = tolower(Ch1);
    return (Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'u') || (Ch1 == 'o') ; 

}




int main()
{ 
    char char1 = readChar();

    if (isVowel(char1)){
        cout << " Yes :  letter " << char1 << " is vowel";
      } else{
        cout << " No :  letter " << char1 << " is not vowel";
     }
}
