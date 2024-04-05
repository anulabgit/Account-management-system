#include "pch.h"
#include "BankAccountManager.h"
#include "BankSystemInterface.h"



int main() {
	string option;
	BankSystemInterface IManager;
	while (1) {
		cout << "----------------------------" << endl;
		cout << "조회, 이체, 출금, 가입, 종료" << endl;
		cout << "----------------------------" << endl;

		cin >> option;
		if (option == "조회") {
			IManager.IPrintAccountInfo();
		}
		else if (option == "이체") {
			IManager.IDeposit();
		}
		else if (option == "출금") {
			IManager.IWithdraw();
		}
		else if (option == "가입") {
			IManager.IAddAccount();
		}
		else if (option == "종료") {
			break;
		}
		else {
			cout << "옵션을 선택해 주세요." << endl;
		}
	}
	
	return 0;
}

BankSystemInterface::BankSystemInterface()
{
	_manager.loadFromFile("accounts.txt");
}

BankSystemInterface::~BankSystemInterface()
{
	_manager.saveToFile("accounts.txt");
}

void BankSystemInterface::IAddAccount()
{
	cout << "계좌번호는 9자만 가능합니다." << endl;
	cout << "성함," << " 개설 계좌번호" << endl;
	cin >> name >> accountNum ;
	_manager.addAccount(Account(name, accountNum, 0));
}

void BankSystemInterface::IDeposit()
{
	cout << "이체 대상 계좌번호," << " 이체 금액" << endl;
	cin >> accountNum >> balance;
	_manager.deposit(accountNum, balance);
}

void BankSystemInterface::IWithdraw()
{
	cout << "출금 대상 계좌번호," << " 출금 금액" << endl;
	cin >> accountNum >> balance;
	_manager.withdraw(accountNum, balance);
}

void BankSystemInterface::IPrintAccountInfo()
{
	cout << "개좌번호" << endl;
	cin >> accountNum;
	_manager.printAccountInfo(accountNum);
}
