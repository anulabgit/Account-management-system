#include "pch.h"
#include "BankAccountManager.h"

BankAccountManager::BankAccountManager()
{

}

void BankAccountManager::addAccount(const Account& acc) {
	accounts.push_back(acc);
}

void BankAccountManager::deposit(int accountNum, double amount) {
	for (auto& acc : accounts) {
		if (acc.getAccountNum() == accountNum) {
			acc.deposit(amount);
			cout << "�Ա� �Ϸ�: " << amount << ", �ܾ�: " << acc.getBalance() << endl;
			return;
		}
	}
	cout << "���¸� ã�� �� �����ϴ�." << endl;
	return;
}

void BankAccountManager::withdraw(int accountNum, double amount) {
	for (auto& acc : accounts) {
		if (acc.getAccountNum() == accountNum) {
			acc.withdraw(amount);
			cout << "��� �Ϸ�: " << amount << ", �ܾ�: " << acc.getBalance() << endl;
			return;
		}
	}
	cout << "���¸� ã�� �� �����ϴ�." << endl;
	return;
}

void BankAccountManager::printAccountInfo(int accountNum) {
	for (const auto& acc : accounts) {
		if (acc.getAccountNum() == accountNum) {
			cout << acc << endl;
			return;
		}
	}
	cout << "���¸� ã�� �� �����ϴ�." << endl;
	return;
}

void BankAccountManager::saveToFile(const string& filename) {
	ofstream file(filename);
	for (const auto& acc : accounts) {
		file << acc.getName() << "," << acc.getAccountNum() << "," << acc.getBalance() << endl;
	}
	file.close();
}

void BankAccountManager::loadFromFile(const string& filename) {
	ifstream file(filename);
	string line;
	char delimiter;
	while (getline(file, line)) {
		istringstream iss(line);
		string name;
		int num;
		double bal;
		getline(iss, name, ',');
		iss >> num >> delimiter >> bal;
		addAccount(Account(name, num, bal));
	}
	file.close();
}
