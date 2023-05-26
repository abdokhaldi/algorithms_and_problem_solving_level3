

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string readString() {
    cout << "enter string : \n";
    string str;
    getline(cin , str);
    return str;
}

string readWords(string msg) {
    cout << msg << "\n";
    string word;
    cin >> word;
    return word;
}

vector<string> SplitString(string str , string delim) {
    vector<string> vString;
    short pos = 0;
    string word = "";

    while ((pos = str.find(delim)) != std::string::npos) {
        word = str.substr(0,pos);

        if (word != "") {
            vString.push_back(word);
        }
        str.erase(0, pos + delim.length());
   }

    if (str != "") {
        vString.push_back(str);
    }
    return vString;
}


string JoinString(vector<string> vString , string delim ) {
    string str;

    for (string S : vString) {
        str = str + S + delim;
    }

    return str.substr(0, str.length() - delim.length());
}

string LowerAllString(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

string ReplaceWordsInString(string str, string strToReplace, string replaceTo, bool matchCase = true) {
    vector <string> vString;
    vString = SplitString(str , " ");
    for (string& S : vString) {
        if (matchCase) {
            if (S == strToReplace) {
                S = replaceTo;
            }
        }
        else {
            if (LowerAllString(S) == LowerAllString(strToReplace)) {
                S = replaceTo;
            }
        }
    }
        return JoinString(vString, " ");
}




int main()
{
   
    string str = "hello , my name is abdo , nice Abdo";
    string oldWord = "abdo";
    string newWord = "aziz";

    cout << "original string :    " << str << " \n";
    cout << "sring with match case : \n ";
    cout << ReplaceWordsInString(str,oldWord,newWord);

    cout << "\n\n string without match case : \n";
    cout << ReplaceWordsInString(str, oldWord, newWord, false);
    

   

    system("pause>0");
}

