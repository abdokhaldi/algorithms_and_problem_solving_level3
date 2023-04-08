
#include <iostream>
#include <string>

using namespace std;

enum enCountLetters { capitalLetter = 0 , smallLetter=1 , All=2};

string ReadCharacters(string msg) {
    cout << msg << endl;
    string S1;
    getline(cin, S1);
    return S1;
}




    
short countNumberOfSmallLetters(string S1 , enCountLetters countLetters = enCountLetters::All) {
    short count = 0;

    if (countLetters == enCountLetters::All) {

        return S1.length();
    }
   
    for (int i = 0; i < S1.length(); i++) {
       
            if ( enCountLetters::capitalLetter && isupper(S1[i])) {
                count++;
            }
            if (enCountLetters::smallLetter && islower(S1[i])) {
                count++;
            }
        }
    
    return count ;
}



int main()
{
    string sentence = ReadCharacters("enter your string ? ");

    cout << "the length of string : " << countNumberOfSmallLetters(sentence , enCountLetters::All) << endl;
    cout << "Number of small letters : " << countNumberOfSmallLetters(sentence, enCountLetters::smallLetter) << endl;
    cout << "number of capital Letters : " << countNumberOfSmallLetters(sentence, enCountLetters::capitalLetter) << endl;
       




}

