/*
Created by: Joshua Ball
A simple Address book that contains the LAST,FIRST name, street, city, house number, state, phone number and zip code of entries.
*/

using namespace std;
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <windows.h>

//This also *works* with .csv file extension, but formating needs work.
string Fname = "book.txt";

//Writes the header to the top of the file at start of program or creation of a file.
void headerWrite(string foo) {
	ofstream ofs(Fname);
	ofs << "***A simple Address book that contains the LAST,FIRST name, street, city, house number, state, phone number and zip code of entries.***";
	ofs << endl;
	ofs.close();
}

struct AddressBook {
	char Name[100];
	char Street[50];
	char City[50];
	char State[50];
	char HouseNumber[100];
	char PhoneNumber[100];
	char ZipCode[6];
};

void prompt(int &selection);
void select(int &selection);
bool inFile(string &name);
bool NewContact(int &selection);
bool WriteInfo(AddressBook &entry);
bool CreateBook(int &selection);

int main() {
	string foo;
	headerWrite(foo);

	int selection = -1;
	select(selection);
	return 0;
}

//Asks the user for their selection in the menu
void prompt(int &selection) {
	string name;
	if (selection == 0) {
		char var;
		cout << "Are you sure you want to exit?" << endl;
		cout << "Y/N: ";
		cin >> var;
		if (var == 'N') {
			system("CLS");
			select(selection);
		}
		else if (var == 'Y') {
			exit(0);
		}
	}
		else if (selection == 1) {
			cout << "Please enter your LAST,FIRST name: ";
			cin >> name;
			inFile(name);
	}
		else if (selection == 2) {
			NewContact(selection);
		}
		else if (selection == 3) {
			CreateBook(selection);
		}
}
	//Outputs the main menu
	void select(int &selection) {
		cout << "Hello and welcome to Joshua Ball's Address Book" << endl;
		cout << endl;
		Sleep(500);
		cout << "Please make your selection below" << endl;
		cout << "(1) Check if you are in the database" << endl;
		cout << "(2) Enter a new contact" << endl;
		cout << "(3) Create a new Address Book" << endl;
		cout << "(0) Exit the program" << endl;
		cout << "Selection: ";
		cin >> selection;
		system("CLS");
		prompt(selection);

	}
	//Creates a new AddressBook if requested by the user
	bool CreateBook(int &selection) {
		string foo;
		ofstream ofs(Fname);
		if (!ofs) {
			return 0;
		}
		if (ofs) {
			cout << "Address book created as " << Fname << endl;
			headerWrite(foo);
			select(selection);
			return 1;
		}
		ofs.close();
		return 1;
	}

	//Checks if the user is in the AddressBook
	bool inFile(string &name) {
		unsigned int curLine = 0;
		string line;
		int foo = 0;
		ifstream ifs(Fname);
		while (getline(ifs,line)) {
			curLine++;
			if (line.find(name,0) != string::npos) {
				cout << "You are in the address book as " << name << endl;
				select(foo);
				return 1;
			}
		}
		char choice;
	
		cout << name << " not found in data base, would you like to add yourself?" << endl;
		cout << "Y/N: ";
		cin >> choice;
		NewContact(foo);
		ifs.close();
		return 0;
	}

	//Takes in information from the user to make a new contact
	bool NewContact(int &selection) {
		AddressBook entry1;
		char choice;

		system("CLS");
		cout << "You have chosen to enter a new contact" << endl;
		cout << "Please enter your name in LAST,FIRST format: ";
		cin >> entry1.Name;
		system("CLS");
		cout << "You have chosen to enter a new contact" << endl;
		cout << "Please enter your Street name: ";
		cin >> entry1.Street;
		system("CLS");
		cout << "You have chosen to enter a new contact" << endl;
		cout << "Please enter your house number: ";
		cin >> entry1.HouseNumber;
		system("CLS");
		cout << "You have chosen to enter a new contact" << endl;
		cout << "Please enter your City name: ";
		cin >> entry1.City;
		system("CLS");
		cout << "You have chosen to enter a new contact" << endl;
		cout << "Please enter your State of residence: ";
		cin >> entry1.State;
		system("CLS");
		cout << "You have chosen to enter a new contact" << endl;
		cout << "Please enter your phone number(no spaces): ";
		cin >> entry1.PhoneNumber;
		system("CLS");
		cout << "You have chosen to enter a new contact" << endl;
		cout << "Please enter your zip code: ";
		cin >> entry1.ZipCode;

		cout << "You have entered the following data: " << endl;
		cout << "Name: "<< entry1.Name << endl;
		cout << "Street: " << entry1.Street << endl;
		cout << "House Number: " << entry1.HouseNumber << endl;
		cout << "City: " << entry1.City << endl;
		cout << "State: " << entry1.State << endl;
		cout << "Phone number: " << entry1.PhoneNumber << endl;
		cout << "Zip code: " << entry1.ZipCode << endl;
		cout << "Is this information correct?" << endl;
		cout << "Y/N: ";
		cin >> choice;

		if (choice == 'Y') {
			WriteInfo(entry1);
			return 1;
		}
		else if (choice == 'N') {
			NewContact(selection);
			return 0;
		}
		return 1;
	}
	
	//Writes the information from NewContact to file
	bool WriteInfo(AddressBook &entry) {
		ofstream ofs(Fname,ios::app);
		char line = ' ';
		int foo = 0;
		if (!ofs) {
			cout << "Error opening " << Fname << endl;
			return 0;
		}
		int count = 0;
		while (count < 7) {
			ofs << endl;
			ofs << "Name: ";
			ofs << entry.Name;
			ofs << endl;
			count++;
			ofs << "Street: ";
			ofs << entry.Street;
			ofs << endl;
			count++;
			ofs << "City: ";
			ofs << entry.City;
			ofs << endl;
			count++;
			ofs << "House Number: ";
			ofs << entry.HouseNumber;
			ofs << endl;
			count++;
			ofs << "State: ";
			ofs << entry.State;
			ofs << endl;
			count++;
			ofs << "Phone Number: ";
			ofs << entry.PhoneNumber;
			ofs << endl;
			count++;
			ofs << "Zip Code: ";
			ofs << entry.ZipCode;
			ofs << endl;
			count++;
		}
		system("CLS");
		cout << "Creation Successful!" << endl;
		select(foo);
		ofs.close();
		return 1;
	}