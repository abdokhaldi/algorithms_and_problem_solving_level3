
#include <iostream>
using namespace std;

char readChar(string msg) {
    cout << msg;
    char letter = ' ';
    cin >> letter;

    return letter;
}



char invertCharacter(char Char1) {
   
    return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

        int main()
        {

           char  String = readChar("enter character ? \n");

           cout << "character befor invert \n ";
           cout << String << endl;

           cout << "character after invert \n ";
          cout <<   invertCharacter(String);

        }