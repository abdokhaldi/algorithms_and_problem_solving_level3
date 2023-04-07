

#include <iostream>
using namespace std;

string firstLetterToCapitalLetter() {
    bool isFirstLetter = true;

    string s1 = "welcome everyone  to my world";
    for (int i=0;i<= s1.length(); i++)
    {
        if(s1[i] != ' ' && isFirstLetter) {
             s1[i] = toupper(s1[i]) ;
        }
        isFirstLetter = (s1[i] == ' ' ? true : false) ;
    }
    return s1;
}
int main()
{
    cout << firstLetterToCapitalLetter();
}

