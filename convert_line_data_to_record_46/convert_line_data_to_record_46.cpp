// convert_line_data_to_record_46.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;



struct stBankInfo {
    string acountNumber;
    string pinCode;
    string name;
    string phoneNumber;
    double acountBalance=0;
};



vector<string> SplitString(string str, string delim) {
    vector<string> vString;
    short pos = 0;
    string word = "";

    while ((pos = str.find(delim)) != std::string::npos) {
        word = str.substr(0, pos);

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

stBankInfo convertLineDataToRecord(string str, string separator= "#//#") {

    stBankInfo BankInfo;

    vector <string> vString;
    vString = SplitString(str, separator);

    BankInfo.acountNumber = vString[0];
    BankInfo.pinCode = vString[1];
    BankInfo.name = vString[2];
    BankInfo.phoneNumber = vString[3];
    BankInfo.acountBalance = stod( vString[4]);


   
    return  BankInfo;

}

void printRecord(stBankInfo BankInfo){

    cout << "the folowing is extracter client record  : \n";

    cout << "Account Number :     " <<  BankInfo.acountNumber << endl ;
    cout << "Account Number :     " << BankInfo.pinCode << endl;
    cout << "Account Number :     " << BankInfo.name << endl;
    cout << "Account Number :     " << BankInfo.phoneNumber << endl;
    cout << "Account Number :     " << BankInfo.acountBalance << endl;
    
    }



int main()
{
   
    string str = "A2344#//#1234#//#abdenabi#//#0634221367#//#500";
    cout << "Line Record is " << str << endl;  
    stBankInfo BankInfo = convertLineDataToRecord(str);

    printRecord(BankInfo);

   
    system("pause>0");

    return 0;
}

