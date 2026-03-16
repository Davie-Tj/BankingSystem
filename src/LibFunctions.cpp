#include "libFunctions.h"

namespace functionSpace
{
  //fuunction emplementation
void printMenu()
{
    std::cout << "Welcome to THEBANK" << std::endl;
	std::cout << "1. Create a new account" << std::endl;
	std::cout << "2. Log into your account" << std::endl;
	std::cout << "3. Exit MENU " << std::endl;
	//promt the user to enter the option of their own from our menu
	std::cout << "Choose an option from the above menu : ";
}


bool IsPassordStrong(const std::string& Password)
  {
	//chceck if the length of the password is at least 8 charaters
	if(Password.length() < 8)
		return false;

	bool blnHasUpper = false;
	bool blnHasLower = false;
	bool blnHasDigit = false;
	bool blnHasSpecial = false;

	for(char c : Password)
	{
		if(isupper(c))
		{
			blnHasUpper = true;
		}else if(islower(c))
		{
			blnHasLower = true;
		}else if(isdigit(c))
		{
			blnHasDigit = true;
		}else{
			blnHasSpecial = true;
		}

	}
	return blnHasUpper && blnHasLower && blnHasDigit && blnHasSpecial;
 }
 
 void printAccountMenu(const BankAccount& objAcc)
 {
	 //variable to store balance locally
	 float balance = objAcc.getbalance();
	 //variable to store user names locally
	 string UserName = objAcc.getUserName();
	 //variable to store account number locally
	 string AccNumber = objAcc.getAccNumber();
	 
	cout << "-------My Accounts-------" <<  endl;
	cout <<"|>>User Name :" << UserName << endl;
	cout << "|>>Account no :" << AccNumber << endl;
	cout <<"|>>Balance :" << balance << endl;
	
	//menu option
	cout << "|>>W.-Withdraw" << endl;
	cout << "|>>D.-Deposit" <<  endl;
 }
 
}
