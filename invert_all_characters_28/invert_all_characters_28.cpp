

#include <iostream>
#include <string>

using namespace std;

string ReadCharacters(string msg) {
    cout << msg << endl;
    string S1;
   getline(cin, S1);
    return S1;
}

char InvertChars(char C1) {
    return isupper(C1) ? tolower(C1) : toupper(C1);
}

string invertAllStringLetters(string S1) {

    for (int i = 0; i <= S1.length(); i++) {
     
            S1[i] = InvertChars(S1[i]);
            
    }
    return S1;
}


int main()
{
   string sentence = ReadCharacters("enter your string ? "); 

   cout << invertAllStringLetters(sentence);
 



}

