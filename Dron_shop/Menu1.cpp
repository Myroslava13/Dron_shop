#include "Menu1.h"

void Menu::ShowMenu()
{
	char userInput;

	do {
		showConsultantOrCustomerMenu();
		cin >> userInput;
		handleUserInput(userInput);

		cout << endl;
	} while (userInput != '0');
}

void Menu::showConsultantOrCustomerMenu()
{
	cout << "Welcome to the Dron shop!\n";
	cout << "If you are the Consultant, press 1\n";
	cout << "If you are the customer, press 2\n";
	cout << "To exit the program, press 0\n\n";
}

void Menu::handleUserInput(char userInput)
{
	switch (userInput)
	{
	case '1':
		ShowConsultantMenu();
		break;
	case '2':
		ShowCustomerMenu();
		break;
	case '0':
		break;
	default:
		cout << "Wrong Options selected\n";
		break;
	}
}