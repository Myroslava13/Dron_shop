#include "Options.h"

Options::Options(int maxCapacity) : DronRepository(maxCapacity) { }

Options::~Options() { }

int Options::GetSize()
{
	return DronRepository.GetSize();
}

int Options::GetMaxCapacity()
{
	return DronRepository.GetMaxCapacity();
}

void Options::AddDron(Dron& Dron)
{
	DronRepository.Add(Dron);
}

void Options::RemoveDron(int idx)
{
	DronRepository.Remove(idx);
}

void Options::ReplaceDron(Dron& Dron, int idx)
{
	DronRepository.Replace(Dron, idx);
}

void Options::PrintDrons()
{
	DronRepository.Print();
}

Dron& Options::operator[](int idx)
{
	return DronRepository[idx];
}

string Options::GetDronmake(int idx)
{
	return DronRepository.GetDronmake(idx);
}

string Options::GetDronModel(int idx)
{
	return DronRepository.GetDronModel(idx);
}

double Options::GetDronPrice(int idx)
{
	return DronRepository.GetDronPrice(idx);
}

string Options::GetDronInfoByIndex(int idx)
{
	return DronRepository.GetDronInfoByIndex(idx);
}

void Options::AddDronToSoldDrons(int idx)
{
	DronRepository.AddDronToSoldDrons(idx);
}

vector<Dron>::iterator Options::GetIteratorToBegin()
{
	return DronRepository.GetIteratorToBegin();
}

vector<Dron>::iterator Options::GetIteratorToEnd()
{
	return DronRepository.GetIteratorToEnd();
}