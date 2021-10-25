#ifndef Options_H
#define Options_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "Dron.h"
#include "Error.h"
#include "Money.h"
#include "DronRepository.h"

class Options
{
public:
	Options(int maxCapacity = 10000);
	~Options();

	int GetSize();
	int GetMaxCapacity();

	void AddDron(Dron& Dron);
	void RemoveDron(int idx);
	void ReplaceDron(Dron& Dron, int idx);
	void PrintDrons();
	Dron& operator[](int idx);

	string GetDronmake(int idx);
	string GetDronModel(int idx);
	double GetDronPrice(int idx);
	string GetDronInfoByIndex(int idx);
	void AddDronToSoldDrons(int idx);

	vector<Dron>::iterator GetIteratorToBegin();
	vector<Dron>::iterator GetIteratorToEnd();

private:
	DronRepository DronRepository;
};

#endif // !Options_H
