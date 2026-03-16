#include "BankDataBase.h"
#include <iostream>



namespace dataBase
{
	BankDataBase::BankDataBase()
	{
		 // Use forward slashes or double backslashes to avoid escape sequences
		_strDataFilePath = "../data/data_file.dat";
		 // Alternative: _strDataFilePath = "..\\bin\\data_file.dat"
	}
	
	
	void BankDataBase::addAccount(const BankAccount& acc)
	{
		_vecAccounts.push_back(acc);
		//save all the accounts everytime a new account is added
		saveAllAccounts();
	}
	
	void BankDataBase::saveAllAccounts()
	{
		//open the file to store all accounts if the file does not exist create that file
		ofstream out;
		out.open(_strDataFilePath,ios::out | ios::binary);
		// handle exceptions if the file fails to open
		
		//write number of accounts
		size_t  numOfAccounts = _vecAccounts.size();
		out.write(reinterpret_cast<char*>(&numOfAccounts),sizeof(BankAccount));
		//code to handle the exception if we fail to write to file
		
		//write each account on a separate line
		for(const auto& acc : _vecAccounts)
		{
			out << acc.toString() << "\n";
		}
		out.close();
	}
	
	void BankDataBase::loadAllAccounts()
	{
		ifstream in;
		in.open(_strDataFilePath, ios::in | ios::binary);
		//handle an exception where the file fails to open
		
		string line;
        int count = 0;
        
		//to avoid duplicate accounts during reloading when the program is runnning
		if(!_vecAccounts.empty())
			{
                cout << "Warning: Clearing " << _vecAccounts.size(); 
                cout << " existing accounts to load from file.\n";
                 _vecAccounts.clear();
            }
		
        while(getline(in, line)) {
            if(!line.empty()) {
                BankAccount account = BankAccount::fromString(line);  // Static factory method - returns BankAccount object
                _vecAccounts.push_back(account);
                count++;
            }
        }
		
		in.close();
        cout << "Loaded " << count << " accounts from " << _strDataFilePath << "\n";
	}
	
	BankAccount* BankDataBase::findAccount(const string& accNum)
	{
		for(auto& account : _vecAccounts) {
            if(account.getAccNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
	}
}