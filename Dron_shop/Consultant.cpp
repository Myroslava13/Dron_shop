#include "Consultant.h"

Options Consultant::Options = {};

double Consultant::GetCurrentAmountOfMoney()
{
	return money.Getmoney();
}

void Consultant::AddSeveralDrons(Dron& Dron, int quanity)
{
	for (int i = 0; i < quanity; i++)
	{
		Options.AddDron(Dron);
	}
}


void Consultant::RemoveDronsBymake(string make)
{
	for (int i = 0; i < Options.GetSize(); i++)
	{
		if (Options.GetDronmake(i) == make)
		{
			Options.RemoveDron(i);
			i--;
		}
	}
}

void Consultant::RemoveDronsByModel(string model)
{
	for (int i = 0; i < Options.GetSize(); i++)
	{
		if (Options.GetDronModel(i) == model)
		{
			Options.RemoveDron(i);
			i--;
		}
	}
}

void Consultant::ReplaceDron(Dron& Dron, int idx)
{
	if (idx < 0 || idx >= Options.GetSize())
		throw Error(ErrorCode::IndexOutsideLimit);

	Options.ReplaceDron(Dron, idx);
}

const Dron Consultant::CreateAndReturnDron()
{
	Dron Dron;
	cin >> Dron;

	return Dron;
}

bool Consultant::makeIsInStock(string make)
{
	for (int i = 0; i < Options.GetSize(); i++)
	{
		if (Options.GetDronmake(i) == make)
			return true;
	}
	return false;
}

bool Consultant::ModelIsInStock(string model)
{
	for (int i = 0; i < Options.GetSize(); i++)
	{
		if (Options.GetDronModel(i) == model)
			return true;
	}
	return false;
}

void Consultant::SellDron(int idx)
{
	money.AddTomoney(Options.GetDronPrice(idx));
	Options.AddDronToSoldDrons(idx);
	Options.RemoveDron(idx);
}