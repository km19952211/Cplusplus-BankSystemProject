#pragma once
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsTransactionsMenu.h"
class clsWithdrawalScreen :protected clsScreen
{
private:

public:
	static void WithdrawalScreen() {
		_DrawScreenHeader("\Withdrawal Screen");
		cout << "Please Enter Account Number" << endl;
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nWrong Number , Please Enter Correct Account Number" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}
		float amount = 0;
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Print();
		cout << "\nEnter Amount To Withdrawal : " << endl;
		amount = clsInputValidate::ReadFloatNumber();
		cout << "\nAre you sure you want to make the Withdrawal ? " << endl;
		char a;
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			if (Client.Withdraw(amount))
			{
				cout << "\nSuccseful Withdrawal " << endl;
				cout << "\nNew Balance is :  " << Client.AccountBalance << endl;
			}

			else
			{
				cout << "No Enough Balance \n";
			}
			.
		}
		else
		{
			cout << "Operations was cancelled \n"; 
		}
	}

	};


