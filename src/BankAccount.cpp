#include "BankAccount.h"
#include <vector>
#include <sstream>

namespace bankAcc
{
        //function to generate a random number

    void BankAccount::alloc(const string& PassWord)
    {
		PasswordManager objTemp(PassWord,_strHolderName);
        _AccPasswordInfo = objTemp;
    }
    int BankAccount::randNumgen()
    {
        int intRandnum = rand() % 10;
        return intRandnum;
    }

    //function to generate accountnumber
    void BankAccount::genrandAccountNUm()
    {
       /*for(int i = 0; i < AccountNumSize; i++)
        {
           _intAccounNo[i] = randNumgen();
        }*/
		static constexpr char charset[] = "0123456789";
		string temp = "";
		for(int i = 0; i < 9;i++)
		{
			 temp += charset[rand()% (sizeof(charset) - 1)];
		}
		_strAccounNo = temp;
    }


    BankAccount::BankAccount(string strUserName, string strPassword)
    {
        //iinitialize the holder name with the user's name
        _strHolderName = strUserName;
        //set the password
	    alloc(strPassword);
        //initialize the balance to zero
        _flBalance = 0.0;
        //generate a random 9 digit account number
        genrandAccountNUm();
        //ask the user to set a password
    }
	
	BankAccount::BankAccount(string strUserName,string strAccountNumber,float flBalance,string strPassHash,string strPassSalt)
	{
		_strHolderName = strUserName;
		_strAccounNo = strAccountNumber;
		_flBalance = flBalance;
		_AccPasswordInfo.setHash(strPassHash);
		_AccPasswordInfo.setSalt(strPassSalt);
		_AccPasswordInfo.setName(strUserName);
	}

    //constructor chaining
    BankAccount::BankAccount() : BankAccount("NONAME","1234567")
    {
    }

    void BankAccount::deposit(double dblAmaunt)
    {
        _flBalance += dblAmaunt;
    }

    void BankAccount::withdraw(double dblAmount)
    {
        _flBalance -= dblAmount;
    }

    float BankAccount::getbalance() const
    {
        return _flBalance;
    }

    string BankAccount::getUserName() const
    {
        return _strHolderName;
    }

    string BankAccount::getAccNumber() const
    {
        //print the account number
      //  for(int i =0 ; i < 9; i++)
      //  {
      //      cout << _intAccounNo[i]<<' ';
       // }
	   return _strAccounNo;
    }

    /*BankAccount::~BankAccount()
    {
        delete _AccPasswordInfo;
    }
	*/


	 string BankAccount::toString() const
	 {
		stringstream ss;
		ss << _strHolderName << "|" //user name
		   << getAccNumber() << "|" //account number
		   << _flBalance << "|" //balance
		   << _AccPasswordInfo.getHash() << "|" //hash
		   << _AccPasswordInfo.getSalt(); // salt
		
		return ss.str();
	 }
	 
	 //static don't appear in deffinition only in declaration
	BankAccount BankAccount::fromString(const string& data)
	 {
		BankAccount objAccount;
        
		   // Split the string by '|'
        vector<string> parts;
        stringstream ss(data);
        string part;
        
        while(getline(ss, part, '|')) {
            parts.push_back(part);
        }
        
        // Should have at least 4 parts: name, account#, balance, password hash
        if(parts.size() >= 5) {
            string strHolderName = parts[0];
            string AccountNumber = (parts[1]);
            float flBalance = stof(parts[2]);  // Convert string to float
            string PasswordHash = (parts[3]);   
			string PasswordSalt = (parts[4]);
			
			//instantiate a new object
			BankAccount tempAccount(strHolderName,AccountNumber,flBalance,PasswordHash,PasswordSalt);
			objAccount = tempAccount;
        }
		return objAccount;
		
	 }
	 
	 bool BankAccount::verPassword(const string& strPassKey)
	 {
		return _AccPasswordInfo.verifyPassword(strPassKey);
	 }

}
