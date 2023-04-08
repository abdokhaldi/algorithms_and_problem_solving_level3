

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


int countLetterInString(string str1, char char1) {
    short count = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == char1 ) {
            count++;
        }
    }
    return count;
}

int main()
{
    string readString = ReadString("Enter String : ");
    char readChar = ReadChar();

    cout << " the letter " << readChar << " count " << countLetterInString(readString, readChar) << "  times in string ";
}

