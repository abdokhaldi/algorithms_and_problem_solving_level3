

#include <iostream>
#include <string>

using namespace std;

string readString() {
	cout << " enter string : \n  ";
	string s1;
	getline(cin,s1);
	return s1;

}

void printEachWordInString(string s1) {
	string delim = " ";
	cout << "\n your string words are : \n";
	short pos = 0;
	string sWord;
	while ((s1.find(delim)) != std::string::npos) {
		pos = s1.find(delim);
		sWord = s1.substr(0, pos);
		if (sWord != "") {
			cout << sWord << endl;
		}
		s1.erase(0, pos + delim.length());
	}
	if (s1 != ""){
		cout << s1 << endl;
	}
}



int main()
{
	//string str1 = readString();

	printEachWordInString(readString());

	system("pause>0");
}

