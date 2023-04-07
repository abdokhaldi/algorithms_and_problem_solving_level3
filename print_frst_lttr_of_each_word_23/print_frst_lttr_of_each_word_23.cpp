// print_frst_lttr_of_each_word_23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void printFirstLetterOfEachWord() {
    bool isFirstLetter = true;
    string  phrase = "hello abdo khaldi i love my parents";
    for (int i = 0; i <= phrase.length(); i++) {

         if (phrase[i] != ' ' && isFirstLetter ) {
             cout << phrase[i] << endl;
         }

         isFirstLetter = ( phrase[i] == ' ' ? true : false );
         }

       
}


int main()
{
    printFirstLetterOfEachWord();
}

