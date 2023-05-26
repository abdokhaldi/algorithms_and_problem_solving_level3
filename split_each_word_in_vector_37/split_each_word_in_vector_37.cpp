// split_each_word_in_vector_37.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
string readString() {
    cout << "enter string : \n";
    string str;
    getline(cin, str);
    return str;
}





vector <string> splateWordsInVector(  string str, string spl) {
    vector<string> spVector;
    string word = "";
    short pos = 0;
    while ((pos = str.find(spl)) != std::string::npos) {
       
         word = str.substr(0, pos);
        if (word != "") {
            spVector.push_back(word);
        }
        str.erase(0, pos + spl.length());
    }

    if (str != "") {
        spVector.push_back(str);
    }
    return spVector;
}




int main()
{
    vector <string>spVector;
    string str = readString();

   spVector =  splateWordsInVector(str," ");
    cout << endl;
    cout << "tokens : " << spVector.size();
    cout << endl;
    for (string vec : spVector ) {
        cout << vec << "\n";
    }
}

