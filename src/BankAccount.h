#ifndef BANKACCOUNT_H_INCLUDED
#define BANKACCOUNT_H_INCLUDED

#include <iostream>
#include "PasswordManager.h"
#include <sstream>
#include <vector>



using namespace std;
using namespace PassManager;

namespace bankAcc
{
    class BankAccount
    {
       public:
       BankAccount(); //defualt constructor
       BankAccount(string strUserName,string strPassword);
	   BankAccount(string strUserName,string strAccountNumber,float flBalance,string strPassHash,string strPassSalt);
       void deposit(double dblAmaunt);
       void withdraw(double dblAmount);
	   string toString() const; //function to convert important information to string for storage
	    // Static factory method - returns BankAccount object
	   static BankAccount fromString(const string& data); // function to convert string to an object for reading files
	   bool verPassword(const string& strPassKey);
      ~BankAccount() = default;
       //accessors
       float getbalance() const;
      string getUserName() const;
      string getAccNumber() const;


    //constants
    static constexpr int AccountNumSize = 9;
    //static constexpr string DEFAULT_NAME = "Noname";


    private:
    //utility/helper functions
    void genrandAccountNUm(); //function to genrate random account number
    int randNumgen(); //function to generate random number
    void alloc(const string& PassWord);

    //state variables
    string _strHolderName;
    string _strAccounNo;
    float _flBalance;
    //password
    PasswordManager _AccPasswordInfo; 
  };
}

#endif // BANKACCOUNT_H_INCLUDED
