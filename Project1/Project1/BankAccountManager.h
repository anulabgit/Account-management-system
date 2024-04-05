#pragma once

class BankAccountManager
{
public:
	BankAccountManager();
public:
	// 회원 입력
	void addAccount(const Account& acc);
	// 이체
	void deposit(int accountNum, double amount);
	// 출금
	void withdraw(int accountNum, double amount);
	// 금액 확인
	void printAccountInfo(int accountNum);
	// 회원 불러오기
	void saveToFile(const string& filename);
	// 회원 저장
	void loadFromFile(const string& filename);
private:
	vector<Account> accounts;
};

