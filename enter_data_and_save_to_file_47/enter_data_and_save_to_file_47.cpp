// enter_data_and_save_to_file_47.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string ClientsFileName = "exampleFile.txt";

struct stClient {
    string acountNumber;
    string pinCode;
    string name;
    string phoneNumber;
   double acountBalance;
};

stClient ReadClient() {
    stClient  Client;

   
        cout << "enter acount number : \n";
        getline ( cin >> ws, Client.acountNumber);
        cout << "enter pin code : \n"; \
        getline( cin , Client.pinCode);
        cout << "enter your name : \n";
        getline(cin , Client.name);
        cout << "enter phone number : \n";
        getline(cin , Client.phoneNumber);
        cout << "enter acount balance : \n";
        cin >> Client.acountBalance;
    
    return Client;

}

string convertDataToLine(stClient Client , string separator = "#//#") {

   string  stClientLine = "";

   stClientLine += Client.acountNumber + separator;
   stClientLine += Client.pinCode + separator;
   stClientLine += Client.name + separator;
   stClientLine += Client.phoneNumber + separator;
   stClientLine += to_string( Client.acountBalance );

   return  stClientLine;
   }

void AddDataLineToFile(string FileName , string DataLine) {

    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open()) {

            MyFile << DataLine << endl;
            MyFile.close();
        }

}


void AddNewClient() {
    stClient Client = ReadClient();
    AddDataLineToFile(ClientsFileName, convertDataToLine(Client));
}


void AddClients() {
    char AddMore = 'Y';

    do {
        system("cls");
        cout << "Adding New Client:\n\n";
        AddNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');

}

int main()
{
  
    AddClients();

    system("pause>0");
    }

   
   


