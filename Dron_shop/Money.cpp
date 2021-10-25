#include "Money.h"

Money::Money()
{
	money = 0;
}

double Money::Getmoney()
{
	return money;
}

double Money::AddTomoney(double amount)
{
	this->money += amount;
	return money;
}