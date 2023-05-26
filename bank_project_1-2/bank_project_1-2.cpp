// bank_project_1-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

 string ClientsFileName = "Clients.txt";

void ShowMainMenue();

enum enActions {   
    ShowAll = 1,
    AddNew=2,
    Update=3,
    Delete=4,
    Find=5,
    Exit=6,
};

struct stClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string PhoneNumber;
    string AccountBalance;
    bool MarkForDelete = false;
};




void BackToMainMenue() {
    cout << "\n\n press any Key to go back to main menue ... \n";
    system("pause>0");
    ShowMainMenue();
}

short ReadNumberFromList() {
    short Number;
    cout << "select a number from list above ? \n";
    cin >> Number;
    return Number;
}

//vector <string> SplitLine(string str, string Delim) {
//    vector<string> vString;
//    string word = "";
//    short pos = 0;
//    while ((pos = str.find(Delim) != std::string::npos) ){
//        word = str.substr(0, pos);
//        if (word != "") {
//            vString.push_back(word);
//        }
//        str.erase(0, pos + Delim.length());
//    }
//
//    if (str != "") {
//        vString.push_back(str);
//    }
//    return vString;
//}
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    size_t pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}
stClient ConvertLineToRecord(string Line , string Separator = "#//#") { 
    stClient Client;
 vector<string> vString = SplitString(Line,Separator);
   
   
    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.PhoneNumber = vString[3];
    Client.AccountBalance = vString[4];
    return Client;
}

vector<stClient> LoadClientsDataFromFile(string FileName) {
    
    vector<stClient> vClients;
    
    fstream  MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {

        string Line;
        stClient Client;

        while (getline(MyFile , Line)){
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;

}

void PrintClientRecordLine(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.PhoneNumber;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}


 
bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

    vector <stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }

        MyFile.close();

    }
    return false;
}


stClient ReadNewClient()
{
    stClient Client;
    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.PhoneNumber);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

void ShowAllClientsScreen() {
    vector <stClient>  vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0) {
        cout << "\t\t\t No Clients Available in this system !";
    }
    else {
        for (stClient Client : vClients) {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    }

}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.PhoneNumber + Seperator;
    stClientRecord += Client.AccountBalance;
    return stClientRecord;
}

void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }
}
void AddNewClient()
{
    stClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}
void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

string ReadClientAccountNumber() {
    string AccountNumber;
    cout << "enter client account number : ";
    cin >> AccountNumber;
    return AccountNumber;
}
bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient& Client)
{
    for (stClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.PhoneNumber;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{

    for (stClient& C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }

    }

    return false;
}

vector <stClient> SaveCleintsDataToFile(string FileName, vector <stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (stClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }

        }

        MyFile.close();
    }

    return vClients;
}

stClient ChangeClientRecord(string AccountNumber)
{

    stClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.PhoneNumber);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{

    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (stClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            //Refresh Clients 

            vClients = LoadClientsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}
    void ShowAddNewClientsScreen()
    {
        cout << "\n-----------------------------------\n";
        cout << "\tAdd New Clients Screen";
        cout << "\n-----------------------------------\n";

        AddNewClients();
    }


    void ShowUpdateClientScreen()
    {

        cout << "\n-----------------------------------\n";
        cout << "\tUpdate Client Info Screen";
        cout << "\n-----------------------------------\n";

        vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
        string AccountNumber = ReadClientAccountNumber();
        UpdateClientByAccountNumber(AccountNumber, vClients);

    }

 void ShowDeleteClientScreen()
 {
     cout << "\n-----------------------------------\n";
     cout << "\tDelete Client Screen";
     cout << "\n-----------------------------------\n";

     vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
     string AccountNumber = ReadClientAccountNumber();
     DeleteClientByAccountNumber(AccountNumber, vClients);
 }

 void ShowFindClientScreen()
 {
     cout << "\n-----------------------------------\n";
     cout << "\tFind Client Screen";
     cout << "\n-----------------------------------\n";

     vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
     stClient Client;
     string AccountNumber = ReadClientAccountNumber();
     if (FindClientByAccountNumber(AccountNumber, vClients, Client))
         PrintClientCard(Client);
     else
         cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
 }

 void ShowEndScreen()
 {
     cout << "\n-----------------------------------\n";
     cout << "\tProgram Ends :-)";
     cout << "\n-----------------------------------\n";
 }

void PerformansAllActions(enActions MainMenueAction) {

    switch (MainMenueAction) {

    case enActions::ShowAll :
        system("cls");
        ShowAllClientsScreen();
        BackToMainMenue();
        break;
    case enActions:: AddNew:
        system("cls");
        ShowAddNewClientsScreen();
        BackToMainMenue();
        break;
    case enActions::Update:
        system("cls");
        ShowUpdateClientScreen();
        BackToMainMenue();
        break;
    case enActions::Delete:
        system("cls");
        ShowDeleteClientScreen();
        BackToMainMenue();
        break;
    case enActions::Find:
        system("cls");
        ShowFindClientScreen();
        BackToMainMenue();
        break;
    case enActions::Exit:
        system("cls");
        ShowEndScreen();
        break;
    
    }

}

void ShowMainMenue() {
    system("cls");
    cout << "________________ Welcome to main menue _______________ \n";
    cout << "[1] Show all clients .\n";
    cout << "[2] Add new client .\n";
    cout << "[3] Update new client .\n";
    cout << "[4] Delete  client .\n";
    cout << "[5] find Client .\n";
    cout << "[6] Exit .\n";
    cout << "___________________________________________\n\n";

    PerformansAllActions((enActions)ReadNumberFromList());

}

int main()
{
    
    ShowMainMenue();

    system("pause<0");
    return 0;
}

