#ifndef DRON_H
#define DRON_H

#include <iostream>
#include <string>
#include "Error.h"
using namespace std;

class Dron
{
private:
	string make;
	string model;
	double price;
public:
	Dron(string make = "", string model = "", double price = 0);
	Dron(const Dron& other);
	Dron& operator=(const Dron& other);
	bool operator==(const Dron& other);

	friend ostream& operator<<(ostream& out, Dron& Dron);
	friend istream& operator>>(istream& in, Dron& Dron);

	string ToString();
	string Getmake();
	string GetModel();
	double GetPrice();
};

#endif // !Dron_H

