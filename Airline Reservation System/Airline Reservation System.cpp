// Airline Reservation System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Airline.h"
#include "Database.h"

using namespace std;
using namespace  AirlineReservationSystem;

int displayMenu();
void doAddFlight(DatatbaseFlight& db);
void doAddPassenger(Database& db);
void doCancle(DatatbaseFlight& db);


int main()
	{
	Database AirlineDB;
	DatatbaseFlight AirlineDBF;

		while (true) {
			int selection = displayMenu();
			switch (selection) {
			case 0:
				return 0;
			case 1:
				doAddFlight(AirlineDBF);
				break;
			case 2:
				doAddPassenger(AirlineDB);
				break;
			case 3:
				AirlineDB.displayAll();
				break;
			case 4:
				AirlineDBF.displayAllFlight();
				break;
			case 5:
				AirlineDB.displayCurrent();
				break;
			case 6:
				doCancle(AirlineDBF);
				break;
			default:
				cerr << "Unknown command." << endl;
				break;
			}
		}

	return 0;
}

int displayMenu() 
{
			int selection;

			cout << "*********************************************************************\n";
			cout << "..............Welcome to the Selam Airline Services ............\n";
			cout << "*********************************************************************\n";
			cout << "Please pick an option from the menu below. \n";
			cout << "1. Add new flights \n";
			cout << "2. Add new passenger \n";
			cout << "3. Display flight schedule \n";
			cout << "4. Display flight details \n";
			cout << "5. Display passenger personal info \n";
			cout << "6. Cancel flight\n";
			cout << "0. Exit \n\n";
			cin >> selection;
			return selection;	
}
void doAddPassenger(Database& db)
{
	string firstName;
	string lastName;
	int passportNumber;
	int dateOfBirth;

	cout << "First name? ";
	cin >> firstName;
	cout << "Last name? ";
	cin >> lastName;
	cout << "Date of birth?";
	cin >> dateOfBirth;
	cout << "Passport Numbe?";
	cin >> passportNumber;

	db.addPassenger(firstName, lastName, passportNumber, dateOfBirth);
}
void doAddFlight(DatatbaseFlight& db)
{
	string startingFrom;
	string to;
	cout << "Starting from? ";
	cin >> startingFrom;
	cout << "To where? ";
	cin >> to;
	
}
void doCancle(DatatbaseFlight& db)
{
	int flightNumber;

	cout << "Flight number? ";
	cin >> flightNumber;

	try {
		Flight& fly = db.getFlight(flightNumber);
		fly.cancleFlight();
		cout << "Flight " << flightNumber << " cancled." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to cancle flight: " << exception.what() << endl;
	}

}



