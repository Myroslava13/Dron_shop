#include "CustomerMenu.h"

void CustomerMenu::ShowMainCustomerMenu()
{
	char customerInput;

	do {
		showCustomerMenu();
		cin >> customerInput;
		safeHandleCustomerInput(customerInput);

		cout << endl;
	} while (customerInput != '0');
}

void CustomerMenu::showCustomerMenu()
{
	cout << "\nYou are a customer select an option\n";
	cout << "1: Get most popular Dron make\n";
	cout << "2: Get most popular Dron model\n";
	cout << "3: Get price of the cheapest Dron\n";
	cout << "4: Get price of the most expensive Dron\n";
	cout << "p: Print all Drons to console\n";
	cout << "0: Exit customer Menu\n\n";
}


void CustomerMenu::MakeMostmakeMenu()
{
	cout << "Most popular make: " << customer.GetMostPopularDronmake() << endl;
}

void CustomerMenu::makeMostmodelMenu()
{
	cout << "Most popular model: " << customer.mostPopularmodeldron() << endl;
}

void CustomerMenu::makeLeastMenu()
{
	cout << "The cheapest Dron costs " << customer.GetTheLeastPrice() << " $" << endl;
}

void CustomerMenu::makeMostPriceMenu()
{
	cout << "The most expensive Dron costs " << customer.GetTheMostPrice() << " $" << endl;
}

void CustomerMenu::handleCustomerInput(char customerInput)
{
	switch (customerInput)
	{
	
	case '1':
		MakeMostmakeMenu();
		break;
	case '2':
		makeMostmodelMenu();
		break;
	case '3':
		makeLeastMenu();
		break;
	case '4':
		makeMostPriceMenu();
		break;
	case 'p':
		Customer::Options.PrintDrons();
		cout << endl;
		break;
	case '0':
		break;
	default:
		cout << "Wrong Options selected\n";
		break;
	}
}

void CustomerMenu::safeHandleCustomerInput(char customerInput)
{
	try
	{
		handleCustomerInput(customerInput);
	}
	catch (Error& error)
	{
		/*ofstream fout("errors.txt");
		fout << error.ToString();
		fout.close();*/

		cout << "Error occured: " << error.ToString() << endl;
	}
	catch (...)
	{
		cout << "Some error occured" << endl;
	}
}