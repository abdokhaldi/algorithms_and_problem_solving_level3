
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string joinString(vector<string> vStrings, string spr)
{
	string sentence = " ";

	for (string& vString : vStrings) {
		sentence = sentence + vString + spr;
	}
	return sentence.substr(0,sentence.length() - spr.length());
}



string joinString(string arr1[100] , int arrLength , string spr)
{
	string sentence = " ";

	for (int i = 0; i < arrLength;i++) {
		sentence = sentence + arr1[i] + spr;
	}
	return sentence.substr(0, sentence.length() - spr.length());
}



int main() {
	vector <string> vStrings = { "ahmed", "ali","rachid","mohammed","abdo" };
	string arr1[] = {"ahmed", "ali","rachid","mohammed","abdo"};
	cout << "vector after join : \n";
	cout << joinString(vStrings, " , ");

	cout << "\n\n array after joing : \n ";
	cout << joinString(arr1, 5 , ",");


	system("pause>0");

}