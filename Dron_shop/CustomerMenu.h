#ifndef CUSTOMERMenu_H
#define CUSTOMERMenu_H

#include "Customer.h"

class CustomerMenu
{
public:
	void ShowMainCustomerMenu();
private:
	Customer customer;
	void showCustomerMenu();

	

	void MakeMostmakeMenu();
	void makeMostmodelMenu();
	void makeLeastMenu();
	void makeMostPriceMenu();

	void handleCustomerInput(char customerInput);
	void safeHandleCustomerInput(char customerInput);
};

#endif // !CUSTOMERMenu_H

