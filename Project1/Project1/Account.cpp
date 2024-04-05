#include "pch.h"
Account::Account(string n, int num, double bal) : name(n), accountNum(num), balance(bal) { }

void Account::deposit(double amount) {
	balance += amount;
}

void Account::withdraw(double amount) {
	if (balance >= amount) {
		balance -= amount;
	}
	else {
		cout << "�ܾ��� �����մϴ�." << endl;
	}
}

int Account::getAccountNum() const { return accountNum; }
double Account::getBalance() const { return balance; }
string Account::getName() const { return name; }

ostream& operator<<(ostream& os, const Account& acc) {
	os << "�̸�: " << acc.name << ", ���¹�ȣ: " << acc.accountNum << ", �ܾ�: " << acc.balance;
	return os;
}
