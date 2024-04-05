#include "pch.h"
#include "BankAccountManager.h"
#include "BankSystemInterface.h"



int main() {
	string option;
	BankSystemInterface IManager;
	while (1) {
		cout << "----------------------------" << endl;
		cout << "��ȸ, ��ü, ���, ����, ����" << endl;
		cout << "----------------------------" << endl;

		cin >> option;
		if (option == "��ȸ") {
			IManager.IPrintAccountInfo();
		}
		else if (option == "��ü") {
			IManager.IDeposit();
		}
		else if (option == "���") {
			IManager.IWithdraw();
		}
		else if (option == "����") {
			IManager.IAddAccount();
		}
		else if (option == "����") {
			break;
		}
		else {
			cout << "�ɼ��� ������ �ּ���." << endl;
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
	cout << "���¹�ȣ�� 9�ڸ� �����մϴ�." << endl;
	cout << "����," << " ���� ���¹�ȣ" << endl;
	cin >> name >> accountNum ;
	_manager.addAccount(Account(name, accountNum, 0));
}

void BankSystemInterface::IDeposit()
{
	cout << "��ü ��� ���¹�ȣ," << " ��ü �ݾ�" << endl;
	cin >> accountNum >> balance;
	_manager.deposit(accountNum, balance);
}

void BankSystemInterface::IWithdraw()
{
	cout << "��� ��� ���¹�ȣ," << " ��� �ݾ�" << endl;
	cin >> accountNum >> balance;
	_manager.withdraw(accountNum, balance);
}

void BankSystemInterface::IPrintAccountInfo()
{
	cout << "���¹�ȣ" << endl;
	cin >> accountNum;
	_manager.printAccountInfo(accountNum);
}
