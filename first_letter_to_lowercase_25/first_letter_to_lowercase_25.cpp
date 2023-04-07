// first_letter_to_lowercase_25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;




string  FirstLetterToLowercase() {
    string s1 = "Welcome Everybody To My World";
    bool isFirstLeter = true ;

    for (int i = 0;i<s1.length() ;i++){
        if (s1[i] != ' ' && isFirstLeter) {
           s1[i]  =  tolower(s1[i]) ;
        }
        isFirstLeter = (s1[i] == ' ' ? true : false);
    }
    return s1;
}


int main()
{
   cout <<  FirstLetterToLowercase();
}

