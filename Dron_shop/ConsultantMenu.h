#ifndef ConsultantMenu_H
#define ConsultantMenu_H

#include <memory>
#include "Consultant.h"

class ConsultantMenu
{
public:
	void ShowConsultantMenu();
private:
	Consultant Consultant;
	void showConsultantMenu();

	void makeAddingDron();
	void makeMutipleDrons();
	void makeRemoveDrons();
	void executeRemoveBymakeMenu();
	void executeRemoveByModelMenu();
	void makeReplaceDronMenu();
	void makeSellDronMenu();
	void makeMoneyMenu();

	void handleConsultantInput(char ConsultantInput);
	void safeHandleConsultantInput(char ConsultantInput);
};

#endif // !ConsultantMenu_H

