#include "Dron.h"
#include <string>
#include <typeinfo>	
using namespace std;


Dron::Dron(string make, string model, double price)
{
	this->make = make;
	this->model = model;

	if (price < 0)
		throw Error(ErrorCode::NegativePrice);

	this->price = price;
}

Dron::Dron(const Dron& other)
{
	this->make = other.make;
	this->model = other.model;
	this->price = other.price;
}

Dron& Dron::operator=(const Dron& other)
{
	this->make = other.make;
	this->model = other.model;
	this->price = other.price;

	return *this;
}

bool Dron::operator==(const Dron& other)
{
	return (this->make == other.make) && (this->model == other.model) && (this->price == other.price);
}

ostream& operator<<(ostream& out, Dron& Dron)
{
	out << Dron.make + "," + Dron.model + "," + to_string(Dron.price);
	return out;
}

istream& operator>>(istream& in, Dron& Dron)
{
	string make, model;
	double price;

	cout << "\nmake:\n";
	in.ignore();
	getline(in, make);
	cout << "Model:\n";
	getline(in, model);
	cout << "Price:\n";
	in >> price;

	Dron = Dron(make, model, price);
	return in;
}

string Dron::ToString()
{
	return "Dron: " + make + " " + model + " " + to_string(price) + " $";
}

string Dron::Getmake()
{
	return make;
}

string Dron::GetModel()
{
	return model;
}

double Dron::GetPrice()
{
	return price;
}