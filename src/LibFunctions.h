#ifndef LIBFUNCTIONS_H_INCLUDED
#define LIBFUNCTIONS_H_INCLUDED

#include <iostream>
#include <string>
#include "BankAccount.h"

using namespace bankAcc;
namespace functionSpace
{
    void printMenu();
    bool IsPassordStrong(const std::string& Password);
	void printAccountMenu(const BankAccount& objAcc);
}


#endif // LIBFUNCTIONS_H_INCLUDED
