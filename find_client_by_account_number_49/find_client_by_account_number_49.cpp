// find_client_by_account_number_49.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string FileName = "example.txt";

struct stClient {
    string AccountNumber ;
    string PinCode;
    string Name;
    string PhoneNumber;
    string AccountBalance;
};

vector <string> SpliteString(string str , string delim) {
    vector <string> vString;
    short pos = 0;
    string word;
    while ((pos = str.find(delim) ) != std::string::npos) {
        word = str.substr(0, pos);
        if (word != "") {
            vString.push_back(word);
        }
        str.erase(0 , pos + delim.length());
    }

    if (str != "") {
        vString.push_back(str);
    }

    return vString;
}

stClient convertLineToRecord(string str , string separator = "#//#") {
    stClient Client;
    vector <string> vString;
    vString = SpliteString(str, separator);

    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.PhoneNumber = vString[3];
    Client.AccountBalance =  vString[4];

    return Client;
}



vector<stClient>  LoadDataFromFile(string FileName) {

    vector  <stClient>  vClient;

    fstream inputFile(FileName);

    if (inputFile.is_open(), ios::in) {

        string Line = "";
        stClient Client;

        while (getline(inputFile, Line)) {
            Client = convertLineToRecord(Line);
            vClient.push_back(Client);
        }

        inputFile.close();
    }

    return vClient;
}



void PrintDetailsCard(stClient Client) {

    cout << "\n\t\t\t\t  More Delails : \n\n";

    cout << "  Account Number   : " << Client.AccountNumber << endl;
    cout << "  Pin Code         : "  << Client.PinCode << endl;
    cout << "  Name             : " << Client.Name << endl;
    cout << "  Phone Number     : " << Client.PhoneNumber << endl;
    cout << "  Account Balance  : " << Client.AccountBalance << endl;
}



bool IsFindAcountNumber(string AccountNumber , stClient& Client) {
  
    vector <stClient> vClient = LoadDataFromFile(FileName);
   
      
    for (stClient& vCl : vClient) {
        if (AccountNumber == vCl.AccountNumber) {
            Client = vCl;
            return true;
      }
       
     }

    return false;
}

string ReadAccountNumber() {
    string AccountNumber;

    cout << "enter Account Number ?";
    cin >> AccountNumber;

    return AccountNumber;

}





int main() {

    string AccountNumber = ReadAccountNumber();
    stClient Client;

    if (IsFindAcountNumber(AccountNumber, Client)) {
        PrintDetailsCard(Client);
    }
    else {
        cout << "oops , the account number ( " << AccountNumber << " ) , Not Exists !!";
    }
    

    system("pause>0");
}
   



