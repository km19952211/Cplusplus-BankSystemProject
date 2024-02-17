#pragma once
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsTransactionsMenu.h"
class clsDepositScreen:protected clsScreen
{
private:
public:
	static void DepositScreen() {
		_DrawScreenHeader("\tDeposit Screen");
		cout << "Please Enter Account Number" << endl;
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nWrong Number , Please Enter Correct Account Number" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}
		float amount = 0; 
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Print();
		cout << "\nEnter Amount To Deposit : " << endl;
	    amount = clsInputValidate::ReadFloatNumber(); 
		cout << "\nAre you sure you want to make the Deposit ? " << endl;
		char a ;
		cin >> a; 
		if (a == 'Y' || a == 'y') {
			Client.Deposit(amount);
			cout << "\nSuccseful Deposit " << endl;
			cout << "\nNew Balance is :  " << Client.AccountBalance << endl;
		}
		else {
			cout << "Operation Was Cancelled. \n"; 
		}
		


	}

};

