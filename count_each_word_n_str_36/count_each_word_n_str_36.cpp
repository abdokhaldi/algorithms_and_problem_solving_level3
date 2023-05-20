#include <iostream>
#include <string>

using namespace std;

string readStr() {
	cout << " enter string : \n";
	string str;
	getline(cin, str);
	return str;

}

short countWordsInString(string str) {
	string delim = " ";
	string sWord = "";
	short pos = 0, counter = 0;
	
	while ((pos = str.find(delim)) != std::string::npos){
		 sWord = str.substr(0,pos);
	if (sWord != "" ) {
		counter ++;
		 }
	str.erase(0, pos + delim.length());
	
	
	}
	
	if (str != "") {
		counter++;
	}
	return counter;
}







int main() {


	cout << "the number of words in string is : " << countWordsInString(readStr());
}