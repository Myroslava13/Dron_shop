#ifndef CONSULTANT_H
#define CONSULTANT_H

#include "Options.h"
#include "Money.h"

class Consultant
{
	friend class ConsultantMenu2;
private:
	static Options Options;
	Money money;
public:
	double GetCurrentAmountOfMoney();

	void AddSeveralDrons(Dron& Dron, int quanity);
	void RemoveSeveralLastDrons(int quantity);
	void RemoveDronsBymake(string make);
	void RemoveDronsByModel(string model);
	void ReplaceDron(Dron& Dron, int idx);

	const Dron CreateAndReturnDron();

	bool makeIsInStock(string make);
	bool ModelIsInStock(string model);
	void SellDron(int idx);
};

#endif // !Consultant_H

