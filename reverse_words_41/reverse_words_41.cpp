
#include <string>
#include <iostream>
#include <vector>
using namespace std;


string readString() {

    cout << " enter string : \n";
    string str;
    getline(cin, str);
    return str;
    
}

vector <string> splitString(string S1, string delim) {
    vector <string> vString;
    short pos = 0;
    string word ;
    
    while ((pos=S1.find(delim)) != std::string::npos) {
        word = S1.substr(0, pos);
        if (word !="") {
            vString.push_back(word);
        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}



string reverse_words(string str) {
    vector<string> vString;
    string S2 = "";

    vString = splitString(str, " ");

    // declare iterator

    vector<string>::iterator Iter = vString.end();
    while (Iter != vString.begin()) {
        --Iter;
        S2 += *Iter + " ";
   }
    S2 = S2.substr(0, S2.length() - 1); //remove last space.
    return S2;
}

int main()
{
    string readStr = readString();
    cout << "\n\nString after reversing words:";
   cout <<  reverse_words(readStr);


   
   


   system("pause>0");
}

