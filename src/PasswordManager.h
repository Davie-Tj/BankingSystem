#ifndef PASSWORDMANAGER_H_INCLUDED
#define PASSWORDMANAGER_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace PassManager
{
    struct PasswordINFO
    {
        string strUserName;
        string strPasswordHash;
        string strSalt; //random characters to be combined with the password to streanghin the hash
    };

    //Class to manage password infomation
    class PasswordManager
    {
        public:
        PasswordManager();
        PasswordManager(const string &strPassword, const string &strUserName);
		//PasswordManager(const string& strPassword);
		bool verifyPassword(const string& strPassword);
        virtual ~PasswordManager() = default;
		
		//mutators
		void setHash(const string& Hash);
		void setSalt(const string& Salt);
		void setName(const string& Name);
		
		//accessors
		string getHash() const;
		string getSalt() const;
        //constants
        static constexpr int intSaltLength = 7;
		

        private:
        //state variables
		PasswordINFO _recStoredPassword;
        
		//bool _blVerification;

        //Utility functionns
        string generateSalt();
        string generateHash(const string& strInput);

    };
}

#endif // PASSWORDMANAGER_H_INCLUDED
