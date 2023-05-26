// find_client_by_account_number_49.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string FileName = "Clients.txt"; 


struct stClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string PhoneNumber;
    string AccountBalance;
    bool MarkForDelete = false;
};


vector <string> SpliteString(string str, string delim) {
    vector <string> vString;
    short pos = 0;
    string word;
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

stClient convertLineToRecord(string str, string separator = "#//#") {
    stClient Client;
    vector <string> vString;
    vString = SpliteString(str, separator);

    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.PhoneNumber = vString[3];
    Client.AccountBalance = vString[4];

    return Client;
}

string convertRecordToLine(stClient Client , string separator = "#//#") {
    string stClientToLine = "";

    stClientToLine += Client.AccountNumber + separator;
    stClientToLine += Client.PinCode + separator;
    stClientToLine += Client.Name + separator;
    stClientToLine += Client.PhoneNumber + separator;
    stClientToLine += Client.AccountBalance ;

    return stClientToLine;
}


vector<stClient>  LoadDataFromFile(string FileName) {

    vector  <stClient>  vClient;

    fstream MyFile;

     MyFile.open(FileName , ios::in);


    if (MyFile.is_open()) {

        string Line = "";
        stClient Client;

        while (getline(MyFile, Line)) {

            Client = convertLineToRecord(Line);

            vClient.push_back(Client);
        }

        MyFile.close();
    }   

    return vClient;

}




void PrintDetailsCard(stClient Client) {

    cout << "\n\t\t\t\t  More Delails : \n\n";

    cout << "  Account Number   : " << Client.AccountNumber << endl;
    cout << "  Pin Code         : " << Client.PinCode << endl;
    cout << "  Name             : " << Client.Name << endl;
    cout << "  Phone Number     : " << Client.PhoneNumber << endl;
    cout << "  Account Balance  : " << Client.AccountBalance << endl;

}





bool IsFindClientByAcountNumber(string AccountNumber, vector <stClient> vClient,  stClient& Client) {

   // vector <stClient> vClient = LoadDataFromFile(FileName);


    for (stClient& vCl : vClient) {
        if (AccountNumber == vCl.AccountNumber) {
            Client = vCl;
            return true;
        }

    }   

    return false;
}
  bool MarkClientForDeleteByAccountNumber(   string AccountNumber, vector <stClient>& vClients) { 

    for (stClient& C : vClients) { 

        if (C.AccountNumber == AccountNumber) { 
            C.MarkForDelete = true; 

            return true; 
        }
    }
    return false;
}



vector <stClient> SaveCleintsDataToFile(string FileName, vector<stClient> vClients) {

    fstream MyFile;    
    MyFile.open(FileName, ios::out); 

    //overwrite 

    string DataLine;

    if (MyFile.is_open())   
    {
        for (stClient vCl : vClients)       
        { 
            if (vCl.MarkForDelete == false)   { 
                //we only write records that are not marked for delete.    

                DataLine = convertRecordToLine(vCl);   
                
                MyFile << DataLine << endl;      
            }      
        }       
        MyFile.close();   
    } 
    return vClients; 
} 



bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& vClients) {
    stClient Client;
    char Answer = 'n';

    if (IsFindClientByAcountNumber(AccountNumber, vClients, Client)) {

        PrintDetailsCard(Client);

        cout << "\n\n Are you sure you want to delete this client? y/n ? ";

        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {

            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);

            SaveCleintsDataToFile(FileName, vClients);

            //Refresh Clients 

            vClients = LoadDataFromFile(FileName);

            cout << "\n\n Client Deleted Successfully.";

            return true;
        }
        else {
                 
            cout << "\n Client with Account Number (" << AccountNumber << ") is Not Found!";

            return false;

        }
    }
}





string ReadAccountNumber() {
    string AccountNumber;

    cout << "enter Account Number ?";
    cin >> AccountNumber;

    return AccountNumber;

}



int main() {

    vector <stClient> vClients = LoadDataFromFile(FileName); 
   
   string AccountNumber =   ReadAccountNumber();  

    DeleteClientByAccountNumber(AccountNumber, vClients);
   
   
    system("pause>0");
    return 0;
}




