// read_dataFile_to_table_48.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;



string FileName = "Clients.txt";

enum enActionsList { ShowAllClients=0, AddNewClient=1,UpdateClient=2,DeleteClient=3,FindClient=4,Exit=6 };

struct  stClient
{
    string acountNumber;
    string pinCode;
    string Name;
    string phoneNumber;
    int acountBalance = 0;
    bool MarkForDelete = true;
};


// ###################################Read data and convert it to one string line and then save it to file ################################

enActionsList Actions(int UserInput) {

    switch (UserInput) {
    case 1:
        return enActionsList::ShowAllClients;
    case 2:
        return enActionsList::AddNewClient;
    case 3:
        return enActionsList::UpdateClient;
    case 4:
        return enActionsList::DeleteClient;
    case 5:
        return enActionsList::FindClient;
    case 6:
        return enActionsList::Exit;

   }

}

// #########################start add new item part ####################

stClient ReadClient() {
    stClient  Client;

    cout << "enter acount number : \n";
    getline(cin >> ws, Client.acountNumber);
    cout << "enter pin code : \n"; \
        getline(cin, Client.pinCode);
    cout << "enter your name : \n";
    getline(cin, Client.Name);
    cout << "enter phone number : \n";
    getline(cin, Client.phoneNumber);
    cout << "enter acount balance : \n";
    cin >> Client.acountBalance;

    return Client;

}

string convertDataToLine(stClient Client, string separator = "#//#") {

    string  stClientLine = "";

    stClientLine += Client.acountNumber + separator;
    stClientLine += Client.pinCode + separator;
    stClientLine += Client.Name + separator;
    stClientLine += Client.phoneNumber + separator;
    stClientLine += to_string(Client.acountBalance);

    return  stClientLine;
}

void AddDataLineToFile(string FileName, string DataLine) {

    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
     if (MyFile.is_open()) {

        MyFile <<  DataLine << endl;
        MyFile.close();
    }

}

void funcAddNewClient() {
    stClient Client = ReadClient();
    AddDataLineToFile(FileName, convertDataToLine(Client));
}


void AddClients() {
    char AddMore = 'Y';

    do {
        system("cls");
        cout << "Adding New Client:\n\n";
        funcAddNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');

}

// ######################### the End of add new item part ####################


// ######################### Start the part of Showing the List Of clients completely  ####################

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


stClient ConvertLineToRecord(string Line, string Separator = "#//#") {
    stClient Client;
    vector <string> vString;
    vString = SplitString(Line, Separator);

    Client.acountNumber = vString[0];
    Client.pinCode = vString[1];
    Client.Name = vString[2];
    Client.phoneNumber = vString[3];
    Client.acountBalance = stoi(vString[4]);

    return Client;

}



vector<stClient>  LoadDataFromFile(string FileName) {

    vector  <stClient>  vClient;

    fstream inputFile(FileName);

    if (inputFile.is_open(), ios::in) {

        string Line = "";
        stClient Client;

        while (getline(inputFile, Line)) {
            Client = ConvertLineToRecord(Line);
            vClient.push_back(Client);
        }

        inputFile.close();
    }

    return vClient;
}

void PrintClientRecord(stClient Client) {

    cout << "| " << setw(15) << left << Client.acountNumber;
    cout << "| " << setw(10) << left << Client.pinCode;
    cout << "| " << setw(40) << left << Client.Name;   
    cout << "| " << setw(12) << left << Client.phoneNumber;
    cout << "| " << setw(12) << left << Client.acountBalance;
}




void PrintAllClientsData(vector <stClient> vClients) {

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

    for (stClient Client : vClients) {

        PrintClientRecord(Client);
        cout << endl;

    }


    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;


}

// ######################### the End of Show the List Of clients completely  ####################


// ######################### the part of menue Controling (HOME SCREEN )  ####################

short ReadUserInput(vector <stClient> vClients) {
    short MenueLength = Exit;
    int ActionNumber = 0;
    cout << " \n enter Number ( 1 - " << MenueLength << " : ";
    cin >> ActionNumber;
    return ActionNumber;
}



void PrintAllClientsData() {

    cout <<  "\t\t\t\t\t\t\t\t Select an Item From List : \n";

   
    cout << "_________________________________________\n" << endl;
    cout << "  | [1] Show All List Of CLients \n";
    cout << "  | [2] Add new Client \n ";
    cout << " | [3] Update Client \n";
    cout << "  | [4] Delete Client \n";
    cout << "  | [5] Find Client \n";
    cout << "  | [6] Exit \n";
    cout << "_______________________________________\n";
}

// ######################### the End of Home Screen Mene Controlling Part  ####################

// ######################### Start the part of find client by account Number   ####################

void PrintDetailsCard(stClient Client) {

    cout << "\n\t\t\t\t  More Delails : \n\n";

    cout << "  Account Number   : " << Client.acountNumber << endl;
    cout << "  Pin Code         : " << Client.pinCode << endl;
    cout << "  Name             : " << Client.Name << endl;
    cout << "  Phone Number     : " << Client.phoneNumber << endl;
    cout << "  Account Balance  : " << Client.acountBalance << endl;
    cout << endl << "____________________________ \n";
   
}

bool IsFindAcountNumber(string AccountNumber, stClient& Client , vector <stClient> vClient) {

    for (stClient& vCl : vClient) {
        if (AccountNumber == vCl.acountNumber) {
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

// ######################### The End of part of find client by account Number   ####################


// ######################### Start Delete Client Part  ####################

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClients) {

    for (stClient& C : vClients) {

        if (C.acountNumber == AccountNumber) {
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
            if (vCl.MarkForDelete == false) {
                //we only write records that are not marked for delete.    

                DataLine = convertDataToLine(vCl);

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

    if (IsFindAcountNumber(AccountNumber, Client, vClients)) {

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




// ######################### The End of Delete Client Part   ####################



// ######################### Update  Client Part   ####################

stClient ChangeClientRecord(string AccountNumber) { 
    stClient Client;   

    Client.acountNumber = AccountNumber;     
    cout << "\n\nEnter PinCode? ";    
    getline(cin >> ws, Client.pinCode);   
    cout << "Enter Name? ";   
    getline(cin, Client.Name);  
    cout << "Enter Phone? ";   
    getline(cin, Client.phoneNumber);  
    cout << "Enter AccountBalance? ";   
    cin >> Client.acountBalance;
    
    return Client; 
}


 bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient> &vClients) { 
     stClient Client; 
     char Answer = 'n'; 
     if (IsFindAcountNumber(AccountNumber, Client, vClients)) { 
         PrintDetailsCard(Client);     
         cout << "\n\nAre you sure you want update this client? y/n ? ";      
         cin >> Answer; 
         if (Answer == 'y' || Answer == 'Y') { 
             for (stClient& C : vClients) {
                 if (C.acountNumber == AccountNumber) { 
                     C = ChangeClientRecord(AccountNumber); 
                     break; 
                 }
             }    SaveCleintsDataToFile(FileName, vClients);       
                 cout << "\n\nClient Updated Successfully."; 
                 return true; 
         }
     } else { 
         cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!"; 
         return false; 
     }
 }
 
 
// ######################### The End of Update Client Part   ####################

 
 void MyApp() {


     stClient Client;
     vector <stClient> vClient;
     vClient = LoadDataFromFile(FileName);

     PrintAllClientsData();

     string AccountNumber;

     short UserInput = ReadUserInput(vClient);

    

     switch (Actions(UserInput)) {
     case  enActionsList::ShowAllClients:

         system("cls");
         PrintAllClientsData(vClient);
         break;
     case  enActionsList::AddNewClient:
         system("cls");
         AddClients();
         break;
     case enActionsList::UpdateClient:
         system("cls");
         AccountNumber = ReadAccountNumber();
         UpdateClientByAccountNumber(AccountNumber, vClient);
         break;

     case  enActionsList::DeleteClient:
         system("cls");
         AccountNumber = ReadAccountNumber();
         DeleteClientByAccountNumber(AccountNumber, vClient);
     case enActionsList::FindClient:
         system("cls");
         cout << " \t\t\t\t\t Find Client By Account Number  \n\n";
         AccountNumber = ReadAccountNumber();
         if (IsFindAcountNumber(AccountNumber, Client, vClient)) {
             PrintDetailsCard(Client);
             break;
         }
         else {

             cout << "oops , the Client with Account Number ( " << AccountNumber << " )  Client Not Exist ";
             break;
         }
     case  enActionsList::Exit:
         exit(0);

     default:
         std::cout << "Invalid choice. Please try again.\n";
         break;
     }

    
 }
   


int main()
{ 
   
   MyApp();

    //system("pause>0");
    return 0;
}

