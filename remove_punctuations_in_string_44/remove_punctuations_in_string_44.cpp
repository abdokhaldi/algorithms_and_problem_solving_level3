// remove_punctuations_in_string_44.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string removePunct(string str ) {
	int countChar = 0;
	string newStr = "";
	for (int i = 0; i<str.length() ; i++){
		if(!ispunct(str[i]))
		newStr += str[i];
		
	}

	return newStr;
}

int main()
{
	string str = "hello , world ; i amm abdo .";

	  cout << "original string : " << str << "\n\n\n";

	  cout << "string wihout punctuations : "  << removePunct(str);

	 

	system("pause>0");
}
