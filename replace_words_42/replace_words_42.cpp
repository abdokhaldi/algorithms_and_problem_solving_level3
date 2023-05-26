// replace_words_42.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<string>

using namespace std;




string readString() {

    cout << " enter string : \n";
    string str;
    getline(cin, str);
    return str;

}



string replaceWordsInString(string str, string oldWord, string newWord) {
    //vector <string> vString;
    short  pos = str.find(oldWord);
    // string word;

    while ( pos != std::string::npos) {

       str = str.replace(pos, oldWord.length(), newWord);

       pos = str.find(oldWord);
 
    }
 return str;
}


int main()
{
   // string readStr = readString();
    string str = "hello Abdo , welcome to my city , i love you Abdo";
    cout << "string befor replace words";
    cout << str ;

    cout << "\n\nString after replacing words: \n ";

   cout <<  replaceWordsInString(str , "Abdo", "aziz");






    system("pause>0");
}


