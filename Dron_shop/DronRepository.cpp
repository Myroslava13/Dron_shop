#ifndef DronREPOSITORY_H
#define DronREPOSITORY_H

#include"Repository.h"
#include"Dron.h"
#include<string>
using namespace std;

class DronRepository : public Repository<Dron>
{
protected:
	string GetFileName() { return "Drons.txt"; }
	string GetSoldItemsFileName() { return "sold_Drons.txt"; }
	string GetTitle() { return "Drons:"; }

	void ReadFromFile()
	{
		ifstream fin(GetFileName());

		if (fin.fail())
			throw Error(ErrorCode::UnableToOpenFile);

		string make, model;
		double price;

		while (!(fin.eof()))
		{
			getline(fin, make, ',');
			if (make.empty())
				continue;
			getline(fin, model, ',');
			fin >> price;
			fin.get();

			Dron Dron(make, model, price);

			this->Add(Dron);
		}

		fin.close();
	}
public:
	DronRepository(int maxCapacity) : Repository(maxCapacity)
	{
		ReadFromFile();
	}

	~DronRepository()
	{
		WriteToFile();
		WriteSoldItemsToFile();
	}

	string GetDronmake(int idx)
	{
		return this->operator[](idx).Getmake();
	}

	string GetDronModel(int idx)
	{
		return this->operator[](idx).GetModel();
	}

	double GetDronPrice(int idx)
	{
		return this->operator[](idx).GetPrice();
	}

	string GetDronInfoByIndex(int idx)
	{
		return this->operator[](idx).ToString();
	}

	void AddDronToSoldDrons(int idx)
	{
		AddToSoldItems(this->operator[](idx));
	}
};

#endif // !DronREPOSITORY_H