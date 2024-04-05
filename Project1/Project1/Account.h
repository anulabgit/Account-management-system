#pragma once
class Account
{
public:
	Account(string n, int num, double bal);
public:
	void deposit(double amount);
	void withdraw(double amount);
	int getAccountNum() const;
	double getBalance() const;
	string getName() const;

	friend ostream& operator<<(ostream& os, const Account& acc);
private:
	string name;
	int accountNum;
	double balance;
};

