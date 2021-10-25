#ifndef REPOSITORY_H
#define REPOSITORY_H

#include"Error.h"
#include<iostream>
#include<fstream>
#include <vector>

using namespace std;

template <class T>
class Repository
{
	vector<T> entities;
	vector<T> soldEntities;
	int maxCapacity;

public:
	Repository(int maxCapacity = 10000)
	{
		this->maxCapacity = maxCapacity;
	}

	~Repository() {}

	int GetSize() { return entities.size(); }

	int GetMaxCapacity() { return maxCapacity; }

	void Add(T& item)
	{
		if (entities.size() >= maxCapacity)
			throw Error(ErrorCode::MaxSizeReached);

		entities.push_back(item);
	}

	void AddToSoldItems(T& item)
	{
		if (soldEntities.size() >= maxCapacity)
			throw Error(ErrorCode::MaxSizeReached);

		soldEntities.push_back(item);
	}

	void Remove(int idx)
	{
		if (idx < 0 || idx >= entities.size())
			throw Error(ErrorCode::IndexOutsideLimit);

		for (int i = idx; i < (entities.size() - 1); i++)
			entities[i] = entities[i + 1];

		entities.pop_back();
	}

	void Replace(T& item, int idx)
	{
		if (idx < 0 || idx >= entities.size())
			throw Error(ErrorCode::IndexOutsideLimit);

		entities[idx] = item;
	}

	void Print()
	{
		cout << GetTitle() << endl;
		for (int i = 0; i < entities.size(); i++)
		{
			cout << i << " - " << entities[i].ToString() << endl;
		}
	}

	Repository& operator=(const Repository& repository)
	{
		if (this == &repository)
			return *this;

		this->entities = repository.entities;
		this->soldEntities = repository.soldEntities;
		this->maxCapacity = repository.maxCapacity;

		return *this;
	}

	Repository& operator+(T item)
	{
		if (entities.size() >= maxCapacity)
			throw Error(ErrorCode::MaxSizeReached);

		entities.push_back(item);

		return *this;
	}

	Repository& operator-(int quantity)
	{
		for (int i = 0; i < quantity; i++)
		{
			if (!entities.empty())
				entities.pop_back();
		}
		return *this;
	}

	T& operator[](int idx)
	{
		if (idx < 0 || idx >= entities.size())
			throw Error(ErrorCode::IndexOutsideLimit);

		return this->entities[idx];
	}

	typename vector<T>::iterator GetIteratorToBegin()
	{
		return entities.begin();
	}

	typename vector<T>::iterator GetIteratorToEnd()
	{
		return entities.end();
	}

protected:
	virtual string GetTitle() { return ""; }
	virtual string GetFileName() { return ""; }
	virtual string GetSoldItemsFileName() { return ""; }

	virtual void ReadFromFile() { }

	void WriteToFile()
	{
		ofstream fout(GetFileName());
		for (int i = 0; i < entities.size(); i++)
		{
			fout << entities[i] << endl;
		}
		fout.close();
	}

	void WriteSoldItemsToFile()
	{
		ofstream fout(GetSoldItemsFileName());
		for (int i = 0; i < soldEntities.size(); i++)
		{
			fout << soldEntities[i] << endl;
		}
		fout.close();
	}
};

#endif // !REPOSITORY_H
