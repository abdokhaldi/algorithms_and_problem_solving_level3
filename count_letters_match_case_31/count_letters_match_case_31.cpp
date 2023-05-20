

#include <iostream>
#include <string>

using namespace std;

string ReadString(string str) {
    cout << str << endl;
    string S1;
    getline(cin, S1);
    return S1;
}


char ReadChar() {
    cout << "Enter character : \n";
    char char1 = ' ';
    cin >> char1;
    return char1;
}


char InvertLetter(char char1) {
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

int countletter(string str1, char char1, bool matchCase = true) {
    short counter = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (matchCase) {
            if (str1[i] == char1) {
                counter++;
            } 
        }
            else {
                if (toupper(str1[i]) == toupper(char1) ) {
                    counter++;
                }
            }
      
    }
    return counter;
}


int main()
{
    string str1 = ReadString("Enter String : ");
    char char1 = ReadChar();

    cout << "\n the letter " << char1 << " count = " << countletter(str1 , char1) << endl;

    cout << "\nLetter \'" << char1 << "\' ";   
    cout << "Or \'" << InvertLetter(char1) << "\' ";    
    cout << " Count = " << countletter(str1, char1, false);
    
    system("pause>0");
}


