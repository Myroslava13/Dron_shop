#ifndef MENU1_H
#define MENU1_H

#include "ConsultantMenu.h"
#include "CustomerMenu.h"

class Menu : public ConsultantMenu, public CustomerMenu
{
public:
	void ShowMenu();
private:
	void showConsultantOrCustomerMenu();
	void handleUserInput(char userInput);
};

#endif // !Menu1_H

