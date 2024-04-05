#pragma once
class BankSystemInterface
{
public:
	BankSystemInterface();
	~BankSystemInterface();
	void Init();
	void IAddAccount();
	void IDeposit();
	void IWithdraw();
	void IPrintAccountInfo();
protected:
	BankAccountManager _manager;
	string name;
	int accountNum;
	double balance;
};


