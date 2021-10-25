#include "ConsultantMenu.h"

void ConsultantMenu::ShowConsultantMenu()
{
	char ConsultantInput;

	do {
		showConsultantMenu();
		cin >> ConsultantInput;
		safeHandleConsultantInput(ConsultantInput);

		cout << endl;
	} while (ConsultantInput != '0');
}

void ConsultantMenu::showConsultantMenu()
{
	cout << "\n You are consultant choose an option.\n";
	cout << "1: Add new Dron\n";
	cout << "2: Add some new ones Drons\n";
	cout << "3: Remove now the Dron\n";
	cout << "4: Remove Drons of the same make\n";
	cout << "5: Remove Drons of the same model\n";
	cout << "6: Replace an existing Dron\n";
	cout << "s: Sell particular Dron\n";
	cout << "p: Print all Drons to console\n";
	cout << "0: Exit Consultant Menu\n\n";
}

void ConsultantMenu::makeAddingDron()
{
	Dron Dron(Consultant.CreateAndReturnDron());
	Consultant::Options.AddDron(Dron);

	cout << "\nDron was successfully added!\n\n";
}

void ConsultantMenu::makeMutipleDrons()
{
	int quantity;
	cout << "\nHow many Drons do you need to add?\n";
	cin >> quantity;

	Dron Dron;
	cin >> Dron;

	Consultant.AddSeveralDrons(Dron, quantity);

	cout << "\nSeveral identical Drons were successfully added!\n\n";
}

void ConsultantMenu::makeRemoveDrons()
{
	int idx;
	cout << "\nEnter Dron id:\n";
	cin >> idx;

	Consultant::Options.RemoveDron(idx);
	cout << "\nDron was successfully removed\n\n";
}


void ConsultantMenu::executeRemoveBymakeMenu()
{
	string make;
	cout << "\nEnter the make:\n";
	cin.ignore();
	getline(cin, make);

	if (Consultant.makeIsInStock(make))
	{
		Consultant.RemoveDronsBymake(make);
		cout << "\nDrons of make " << make << " were successfully removed\n\n";
	}
	else
	{
		throw Error(ErrorCode::Unknownmake);
	}
}

void ConsultantMenu::executeRemoveByModelMenu()
{
	string model;
	cout << "\nEnter the model:\n";
	cin.ignore();
	getline(cin, model);

	if (Consultant.ModelIsInStock(model))
	{
		Consultant.RemoveDronsByModel(model);
		cout << "\nDrons of model " << model << " were successfully removed\n\n";
	}
	else
	{
		throw Error(ErrorCode::UnknownModel);
	}
}

void ConsultantMenu::makeReplaceDronMenu()
{
	int idx;
	cout << "\nEnter id of the Dron you want to replace:\n";
	cin >> idx;

	Dron Dron(Consultant.CreateAndReturnDron());
	Consultant.ReplaceDron(Dron, idx);
}

void ConsultantMenu::makeSellDronMenu()
{
	int idx;
	cout << "\nEnter Dron id:\n";
	cin >> idx;

	cout << Consultant::Options.GetDronInfoByIndex(idx) << " was successfully sold!\n";
	Consultant.SellDron(idx);
	makeMoneyMenu();
}

void ConsultantMenu::makeMoneyMenu()
{
	cout << "\nThe amount of money in the money register: " << Consultant.GetCurrentAmountOfMoney() << " $" << endl;
}

void ConsultantMenu::handleConsultantInput(char ConsultantInput)
{
	switch (ConsultantInput)
	{
	case '1':
		makeAddingDron();
		break;
	case '2':
		makeMutipleDrons();
		break;
	case '3':
		makeRemoveDrons();
		break;
	
	case '4':
		executeRemoveBymakeMenu();
		break;
	case '5':
		executeRemoveByModelMenu();
		break;
	case '6':
		makeReplaceDronMenu();
		break;
	case 's':
		makeSellDronMenu();
		break;
	case 'p':
		Consultant::Options.PrintDrons();
		cout << endl;
		break;
	case '0':
		break;
	default:
		cout << "Wrong Options selected.\n";
		break;
	}
}

void ConsultantMenu::safeHandleConsultantInput(char ConsultantInput)
{
	try
	{
		handleConsultantInput(ConsultantInput);
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