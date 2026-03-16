#ifndef BANKDATABASE_H_INCLUDED
#define BANKDATABASE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include "BankAccount.h"

using namespace bankAcc;
using namespace std;

namespace dataBase
{
	class BankDataBase
	{
		public:
		BankDataBase();
		void addAccount(const BankAccount& acc); //add account to data base
		void saveAllAccounts(); //save all accounts to a file
		void loadAllAccounts(); //load all accounts from a file
		BankAccount* findAccount(const string& accNum); // find a specific account by account number
		
		private:
		//state variables
		vector<BankAccount> _vecAccounts; //vector structure holding all user accounts existing within the bank
		string _strDataFilePath;
	};
}


#endif // BANKDATABASE_H_INCLUDED