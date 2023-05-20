// count_vowels_33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string read_string() {
    cout << "enter your string : \n";
    string Str1;
    getline(cin, Str1);
    return Str1;
    
}


bool isVowel(char char1) {
    char1 = tolower(char1);

    return (char1 == 'a') || (char1 == 'e') || (char1 == 'u') || (char1 == 'o');
}

int countVowels(string Str1) {
    short counter = 0;

    for (int i = 0; i < Str1.length() ; i++ ) {
        if (isVowel(Str1[i])) {
            counter++;
        }
    }
    return counter;
}

int main()
{
   
    string str1 = read_string();

    cout << "Number of vowels is " << countVowels(str1);  


}

