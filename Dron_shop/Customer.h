#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <algorithm>

#include "Options.h"
#include "Predicate.h"

class Customer
{
	friend class CustomerMenu;
private:
	static Options Options;
public:


	string MostPopularmakedron();
	string mostPopularmodeldron();
	double GetTheLeastPrice();
	double GetTheMostPrice();
};

#endif // !CUSTOMER_H

