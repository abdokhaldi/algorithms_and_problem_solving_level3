// read_dataFile_to_table_48.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;



string FileName = "example.txt";


struct  stClient
{
    string acountNumber;
    string pinCode;
    string Name;
    string phoneNumber;
    int acountBalance = 0;

};


// ###################################Read data and convert it to one string line and then save it to file ################################

stClient ReadClient() {
    stClient Client;
    cout << "enter your  acount number ? ";
    getline(cin >> ws, Client.acountNumber);
    cout << "enter your pin code ?";
    getline(cin,Client.pinCode );
    cout << "enter your Name ? ";
    getline(cin, Client.Name );
    cout << "enter your phone number ?";
    getline(cin, Client.phoneNumber );
    cout << "enter your account balance ?";
    cin >> Client.acountBalance;
   
   return Client;
}



string ConvertDataToStringLine(stClient Client, string separator="#//#") {

    string stClient = "";

    stClient += Client.acountNumber + separator;
    stClient += Client.pinCode + separator;
    stClient += Client.Name + separator;
    stClient += Client.phoneNumber + separator;
    stClient += to_string(Client.acountBalance);

    return stClient;

}



void AddDataToFlie( stClient Client) {
   
    string Line = ConvertDataToStringLine(Client);

  fstream   MyFile;

  MyFile.open(FileName, ios::out | ios::app);
  if (!MyFile.is_open() ){
      cout << "Failed to open file !!" << endl;
  }

      MyFile << Line << endl;
      MyFile.close ();
}



void AddNewClient() {
    stClient Client = ReadClient();
    AddDataToFlie(Client);
}



void AddClients() {
    char AddMore = 'Y';
    do {
        system("cls");
        cout << " Add new Client : \n ";
        AddNewClient();

        cout << "the cient added succesfuly , do you want to add more clients ? Y/N";

        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}



// ############################ Load data from file and print them in a table ########################

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


stClient ConvertLineToRecord(string Line , string Separator = "#//#") {
    stClient Client;
    vector <string> vString;
    vString = SplitString(Line, Separator);

    Client.acountNumber = vString[0];
    Client.pinCode = vString[1];
    Client.Name = vString[2];
    Client.phoneNumber = vString[3];
    Client.acountBalance = stoi( vString[4]) ;

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

   cout << "| " << setw(15)<<left << Client.acountNumber;    
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





int main()
{

   
    AddClients();

    vector <stClient> vClient;

   vClient =  LoadDataFromFile(FileName);

    PrintAllClientsData(vClient);

    system("pause>0");
    return 0;
}

