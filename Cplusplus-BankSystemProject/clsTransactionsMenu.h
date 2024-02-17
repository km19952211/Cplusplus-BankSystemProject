#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawalScreen.h"

class clsTransactionsMenu : protected clsScreen
{
private :
	static  void _GoBackToTransactionsMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menu...\n";

		system("pause>0");
		ShowTransactionsMenue();
	}

	static short ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 4, "Enter Number between 1 to 4? ");
		return Choice;
	}
	enum _enTransactionsMenuOptions {
		enDeposit = 1 , enWithdraw = 2 , enBalance = 3 
	};
	static void _ShowDepositScreen() {
		clsDepositScreen::DepositScreen();
		
	}
	static void _ShowWithdrawScreen() {
		clsWithdrawalScreen::WithdrawalScreen();
	}
	static void _ShowBalanceScreen() {
		cout << "Nothing Here Yet!";
	}
	static void _ShowSelectedOptionScreen(_enTransactionsMenuOptions enTransaction) {
		switch (enTransaction)
		{
		case clsTransactionsMenu::enDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsTransactionsMenu::enWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsTransactionsMenu::enBalance:
			system("cls");
			_ShowBalanceScreen();
			_GoBackToTransactionsMenu();
			break;
		default:
			break;
		}
	}
public:

	static void ShowTransactionsMenue()
	{


		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_ShowSelectedOptionScreen((_enTransactionsMenuOptions)ReadTransactionsMenueOption());
	}


	
};

