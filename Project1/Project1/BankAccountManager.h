#pragma once

class BankAccountManager
{
public:
	BankAccountManager();
public:
	// ȸ�� �Է�
	void addAccount(const Account& acc);
	// ��ü
	void deposit(int accountNum, double amount);
	// ���
	void withdraw(int accountNum, double amount);
	// �ݾ� Ȯ��
	void printAccountInfo(int accountNum);
	// ȸ�� �ҷ�����
	void saveToFile(const string& filename);
	// ȸ�� ����
	void loadFromFile(const string& filename);
private:
	vector<Account> accounts;
};

