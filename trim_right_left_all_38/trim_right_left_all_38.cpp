

#include <iostream>
#include <string>

using namespace std;

string trim_right(string str) {
   

    for (int i = str.length(); i >=0; i--) {
        if (str[i] != ' ') {
            return str.substr(0, i+1);
        }
    }

    return "";
}


string trim_left(string str) {
   
   
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            return str.substr(i, str.length()-i);
        }
    } 
    
    return "";
}

string trim(string str) {
    return trim_left(trim_right(str));
}

int main()
{
    
    string str1 =  "         hello world     how are       ";

         
   

   cout <<  "Trim Left = " << trim_left(str1) ;
   cout << endl;
   cout << "Trim Right = " << trim_right(str1) ;
   cout << endl;
   cout << "Trim  = " << trim(str1);

   
   system("pause>0");

}
