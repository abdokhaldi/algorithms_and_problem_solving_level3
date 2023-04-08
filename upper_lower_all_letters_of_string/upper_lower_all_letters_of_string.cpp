// upper_lower_all_letters_of_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

string LowerStringToUper(string S1) {
    for (int i = 0; i < S1.length() ; i++ ) {
        S1[i] =  toupper(S1[i]);
    }
    return S1;
}

string UpperStringToLower(string S1) {
    for (int i = 0; i < S1.length(); i++) {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

int main()
{
    string S1 = "welcome to my world";
    cout << S1 << "\n\n\n";

    cout << " string after upper \n";
    cout << LowerStringToUper(S1) << " \n\n";

    cout << "string after lower \n";
    cout << UpperStringToLower(S1) << "\n";
}
