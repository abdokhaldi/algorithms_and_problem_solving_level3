// convert_record_to_line_45.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


struct stBankInfo {
    string acountNumber;
    string pinCode;
    string name;
    string phoneNumber;
    int acountBalance;
};



stBankInfo readInfo() {
    stBankInfo  acountInfo;
    cout << "enter acount number ? ";
    cin >> acountInfo.acountNumber;
    cout << "enter pin code ? ";
    cin >> acountInfo.pinCode;
    cout << "enter name ? ";
    cin >> acountInfo.name;
    cout << "enter phone number ? ";
    cin >> acountInfo.phoneNumber;
    cout << "enter acount balance ? ";
    cin >> acountInfo.acountBalance;

    return acountInfo;
}



string convertRecortToLine( stBankInfo  acountInfo, string separator = "#//#") {

   string  stAcountInfo = "";
   stAcountInfo += acountInfo.acountNumber + separator;
   stAcountInfo += acountInfo.pinCode + separator;
   stAcountInfo += acountInfo.name + separator;
   stAcountInfo += acountInfo.phoneNumber + separator;
   stAcountInfo += to_string(acountInfo.acountBalance) ;

   return stAcountInfo;

}

int main()
{

    stBankInfo acountInfo = readInfo();

    

    cout << "\nclient record for saving is : \n"; 
    cout << convertRecortToLine(acountInfo);

}

