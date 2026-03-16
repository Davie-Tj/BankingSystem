#include <iostream>
#include "LibFunctions.h"
#include "BankAccount.h"
#include "BankDataBase.H"
#include <ctime>

using namespace std;
using namespace functionSpace;
using namespace bankAcc;
using namespace dataBase;

int main()
{
	//seed random number generator functionSpace
	srand(time(nullptr));
	
    bool blnCondition = true;
	int intInput = '0';
	//instantiate the bank account object
	BankAccount objBankAccount;
	
	//instantiate the data base
	BankDataBase objDataBase;
	//load all account to the program
	objDataBase.loadAllAccounts();

	do{
		//clear the screen
		system("cls");
		//print the bank menu system
		printMenu();
		cin >> intInput;
		while(cin.fail() || intInput <0)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Invalid Input, Try again an option from the menu :";
			cin >> intInput;
		}
		switch(intInput){

			case 1 :{ //create new acc
			//promt the user for their infomation
			string strFirstName = "";
			string strLastName = "";
			string strPassword = "";
			string strComfirm = "";
			cout << "Enter your first name :";
			cin >> strFirstName;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout << " Invalid input, Enter First Name again :";
				cin >> strFirstName;
			}
			strFirstName += " ";
			cout << "Enter your last name :";
			cin >> strLastName;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout << "Invalid Input, Enter Last Name again :";
				cin >> strLastName;
			}
			//ask the user to create a strong passwords
			cout << "Create a password that contains characters,numbers,Upper & Lower case letters :";
			cin >> strPassword;
			//check if the password is strong
			while(IsPassordStrong(strPassword) == false)
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout << "Password is too weak, try knew Password :";
				cin >> strPassword;
			}
			cout << "Password is strong" << endl;
			cout << "Comfirm Password :";
			cin >> strComfirm;
			while(strComfirm != strPassword)
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout << "Passwords are different, try to enter password same as the first :";
				cin >> strComfirm;
			}
			cout << "--Password-Created-Successfully--" << endl;
			//instantiate the account with the infomation provided
			string strFullNames = strFirstName + strLastName;
			BankAccount objUserBankAccount(strFullNames,strPassword);
			objBankAccount = objUserBankAccount;
			//show the user their account number
			cout << "Account Number :" << objBankAccount.getAccNumber() <<endl;
			//add the account to the data base 
			objDataBase.addAccount(objBankAccount);
			break;
			}
			case 2 :{ // log in
				// testing methods
				string strAccNum = "";
				char chInput;
				bool blnContinue = true;
				//promt the user to enter the account number
				cout << "Enter B to go back or Enter Account number :" << endl;
				cin >> strAccNum;
				if(strAccNum == "B")
				{
					//write code to exit this case
					break;
				}
				cout << endl;
				//try to find the account using account number
				BankAccount* ptrObjAcc = objDataBase.findAccount(strAccNum);
				//chechk if the account was found
				do{
					//clear screen
					system("cls");
					if(ptrObjAcc == nullptr)
					{
						cout << "Account was not Found" <<endl;
						cout << "Press C to try again E to Exit and continue" << endl;
						
						//print a mini menu
						cout << "E : EXIT and CONTINUE" << endl;
						cout << "C : CONTINUE Trying To find Account" << endl;
						cout << "Enter Choice :";
						cin >> chInput;
						
						switch(toupper(chInput)){
							case 'C':
							{
								cout <<"Enter Account number :";
								cin >> strAccNum;
								BankAccount* ptrObjAcc = objDataBase.findAccount(strAccNum);
								break;
							}
							case 'E':
							{
								blnContinue = false;
								break;
							}
						}
					}else if(ptrObjAcc->getAccNumber() == strAccNum)
					{
						cout << "Account found you shall continue" << endl;
						//variable to store the password from the user locally
						string strPassWord = "";
						//promt the user for their password
						cout << "Enter Your Password :";
						//read input from the user
						cin >> strPassWord;
						//verify the user details
						if(ptrObjAcc->verPassword(strPassWord) == true)
						{
							cout << "Password Correct, login Successful" << endl;
							objBankAccount = *ptrObjAcc;
							//print the inside menu of the accoount
							printAccountMenu(objBankAccount);
							//variable to store user imput
							char userChoice='\0';
							//promt the user for their choice
							cout << "What do you wish to do :";
							//read user input
							cin >> userChoice;
							cout << endl;
							//implement a function to delegate all the methods the user wish to peform
							//the function must take user choice and an object reference as parameters

							
						//if the password is wrong give the user 3 chances to re enter their password
						}else{
							int count = 3;
							cout << "Wrong Password,2 tries remaining" << endl;
							while(count >0)
							{
								cin.clear();
								cin.ignore(1000,'\n');
								cout << "Passwords are different, try to enter password same as the first :";
								cin >> strPassWord;
								if(ptrObjAcc->verPassword(strPassWord) == true)
									{
										cout << "Password Correct, login Successful" << endl;
										objBankAccount = *ptrObjAcc;
										//print the inside menu of the account
										printAccountMenu(objBankAccount);
										//variable to store user imput
										char userChoice='\0';
										//promt the user for their choice
										cout << "What do you wish to do :";
										//read user input
										cin >> userChoice;
										cout << endl;
										//implement a function to delegate all the methods the user wish to peform
										
										
										
										
									}
									count--;
							}
						}
					}	
				}while(blnContinue && (ptrObjAcc == nullptr));  	
			}
				
				/*if(ptrObjAcc->getAccNumber() == strAccNum)
				{
					//verify the user 
					string strPassWord = "";
					cout << "Enter Your Password :";
					cin >> strPassWord;
					if(ptrObjAcc->verPassword(strPassWord) == true)
					{
						cout << "Password Correct, login Successful" << endl;
						objBankAccount = *ptrObjAcc;
						//return;
					}else{
							int count = 3;
							cout << "Wrong Password,2 tries remaining" << endl;
							while(count >0)
							{
								cin.clear();
								cin.ignore(1000,'\n');
								cout << "Passwords are different, try to enter password same as the first :";
								cin >> strPassWord;
								if(ptrObjAcc->verPassword(strPassWord) == true)
									{
										cout << "Password Correct, login Successful" << endl;
										objBankAccount = *ptrObjAcc;
										//return;
									}
									count--;
							}
						}  
				
				objBankAccount.getAccNumber();
				cout << endl;
				float balance = objBankAccount.getbalance();
				cout << "balance :" << balance << endl;
				string userName = objBankAccount.getUserName();
				cout << "UserName :" << userName << endl;
				 break;
			 	}
			    break;
			}*/
			case 3 :{ //exit menu
			cout <<"------bye bye-----"<< endl;
			blnCondition = false;

			break;
			}
			default :
			cout << " Invalid option " <<endl;

		}


		//pause the screen
		system("pause");
	}while(blnCondition);

    return 0;
}


//fix the log in logic after the account is found
//fix the databaase, seems to not loading and saving accounts from or to files
//fix the screen
