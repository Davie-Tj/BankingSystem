#include "PasswordManager.h"

namespace PassManager
{//class definition
    string PasswordManager::generateSalt()
    {
        //character set: didgits + uppercase + lowercase letters
    static constexpr char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#$%^&*()_+}{[],./<>?-";
        //empty string for the salt
        string salt = "";
        //generate length random characters
        for(int i = 0; i < intSaltLength; i++)
        {
            salt += charset[rand()% (sizeof(charset) - 1)]; // to return a random index
        }
        _recStoredPassword.strSalt = salt;
        return salt;
    }

    string PasswordManager::generateHash(const string& strInput)
    {
        unsigned long Lhash = 5381; //Magic number

        for(char c : strInput)
        {
            //(hash << 5) means "shift bits left 5positions" = multiplyt by 32
            // + hash adds originals hash = multiply by 33 total
            Lhash = ((Lhash << 5) + Lhash) + static_cast<unsigned char>(c);
        }
		
		//convert long to hex string
		stringstream ss;
		ss << hex << Lhash;

        return ss.str();
    }

    PasswordManager::PasswordManager(const string &strPassword, const string &strUserName)
    {
        _recStoredPassword.strUserName = strUserName;
        _recStoredPassword.strSalt = generateSalt();
        _recStoredPassword.strPasswordHash = generateHash(strPassword + _recStoredPassword.strSalt);
    }
	
	PasswordManager::PasswordManager() : PasswordManager("123456","Noname") //constructor chaingning
	{
	}
	
	string PasswordManager::getHash() const
	{
		return _recStoredPassword.strPasswordHash;
	}
	
	string PasswordManager::getSalt() const
	{
		return _recStoredPassword.strSalt;
	}
	
	bool PasswordManager::verifyPassword(const string& strPassword)
	{
		string tempHash = generateHash(strPassword + _recStoredPassword.strSalt);
		if(tempHash == _recStoredPassword.strPasswordHash)
		{
			return true;
		}else{
			return false;
		}
		
	}
	
	void PasswordManager::setHash(const string& Hash)
	{
		_recStoredPassword.strPasswordHash = Hash;
	}
	
	void PasswordManager::setSalt(const string& Salt)
	{
		_recStoredPassword.strSalt = Salt;
	}
	
	void PasswordManager::setName(const string& Name)
	{
		_recStoredPassword.strUserName = Name;
	}
	
}

