#include <iostream>
using namespace std;
struct BankAccount {
	long long accountNumber;
	string firstName;
	string lastName;
	double balance;
};
void Open_Account(BankAccount* &accounts, long long& count, long long& size) {
	if (count < size)
	{
		cout << "Enter First Name: \n"; cin >> accounts[count].firstName;
		cout << "Enter Last Name: \n"; cin >> accounts[count].lastName;
		cout << "Enter Initial Balance: \n"; cin >> accounts[count].balance;
		accounts[count].accountNumber = 1000 +count+1;
		cout << "Account Created Successfully. Account No: " << accounts[count].accountNumber << endl;
		count++;
	}
	else if (count == size)
	{
		long long new_size = 2 * size;
		BankAccount* new_accounts = nullptr;
		new_accounts = new BankAccount[new_size];
		for (long long i = 0; i < count; i++) {
			new_accounts[i].firstName = accounts[i].firstName;
			new_accounts[i].lastName = accounts[i].lastName;
			new_accounts[i].balance = accounts[i].balance;
			new_accounts[i].accountNumber = accounts[i].accountNumber;
		}
		delete[]accounts;accounts = new_accounts;
		size = new_size;
		cout << "Enter First Name: \n"; cin >> accounts[count].firstName;
		cout << "Enter Last Name: \n"; cin >> accounts[count].lastName;
		cout << "Enter Initial Balance: \n"; cin >> accounts[count].balance;
		accounts[count].accountNumber = 1000 + count + 1;
		cout << "Account Created Successfully. Account No: " << accounts[count].accountNumber << endl;
		count++;
	}
}
void Balance_Enquiry(long long count, BankAccount*accounts) {
	long long num;
	cout << "Enter Account Number: "; cin >> num; cout << endl;
	bool found = false; long long index_found;
	if(count==0||num<=1000)
		cout << "Account not found.";
	for (long long i = 0; i < count ; i++)
	{
		if (accounts[i].accountNumber == num)
		{
			found = true;
			index_found = i;
			break;
		}
	}if (found)
	{
		cout << "Account Number: " << num << endl;
		cout << "Name: " << accounts[index_found].firstName << ' ' << accounts[index_found].lastName;
		cout << "Balance: " << accounts[index_found].balance;
	}
	else
	{
		cout << "Account not found.\n";
	}
	
}
void Deposit(long long count, BankAccount* accounts) {
	long long num;
	cout << "Enter Account Number: \n"; cin >> num;
	bool found = false; long long index_found;
	if (count == 0 || num <= 1000)
		cout << "Account not found.\n";
	for (long long i = 0; i < count; i++)
	{
		if (accounts[i].accountNumber == num)
		{
			found = true;
			index_found = i;
			break;
		}
	}if (found)
	{
		double amount_to_deposit;
		cout << "Enter amount to deposit: \n"; cin >> amount_to_deposit;
		accounts[index_found].balance = accounts[index_found].balance + amount_to_deposit;
		cout << "Deposited Successfully. New Balance: \n" << accounts[index_found].balance << endl;
	}
	else
	{
		cout << "Account not found.\n";
	}

}
void Withdraw(long long count, BankAccount* accounts) {
	long long num;
	cout << "Enter Account Number: \n"; cin >> num;
	bool found = false; long long index_found;
	if (count == 0 || num <= 1000)
		cout << "Account not found.\n";
	for (long long i = 0; i < count; i++)
	{
		if (accounts[i].accountNumber == num)
		{
			found = true;
			index_found = i;
			break;
		}
	}if (found)
	{
		double amount_to_withdraw;
		cout << "Enter amount to withdraw: \n"; cin >> amount_to_withdraw;
		double after_withdrawal= accounts[index_found].balance- amount_to_withdraw;
		if (after_withdrawal >= 500)
		{
			accounts[index_found].balance = after_withdrawal;
			cout << "Withdrawn Successfully. New Balance: " << accounts[index_found].balance << endl;
		}
		else
			cout << "Insufficient funds. Maintain minimum balance of 500 \n";
	}
	else
	{
		cout << "Account not found.\n";
	}

}
void Close_Account(long long &count, BankAccount* accounts) {
	long long num;
	cout << "Enter Account Number To Close: \n"; cin >> num;
	bool found = false; long long index_found;
	if (count == 0 || num <= 1000)
		cout << "Account not found.\n";
	for (long long i = 0; i < count; i++)
	{
		if (accounts[i].accountNumber == num)
		{
			found = true;
			index_found = i;
			break;
		}
	}if (found)
	{
		for (long long i = index_found; i < count; i++)
		{
			accounts[i].firstName = accounts[i+1].firstName;
			accounts[i ].lastName = accounts[i+1].lastName;
			accounts[i ].balance = accounts[i+1].balance;
			accounts[i ].accountNumber = accounts[i+1].accountNumber;
		}count--;
		cout << "Account Closed Successfully. \n";
	}
	else
	{
		cout << "Account not found.\n";
	}

}
void Show_All_Account(long long count, BankAccount* accounts) {
	if (count == 0)
		cout << "No Account Available. \n";
	else
	{
		for (long long i = 0; i < count; i++)
		{
			cout << "Account Number: " << accounts[i].accountNumber << endl;
			cout << "Name: " << accounts[i].firstName<<' '<<accounts[i].lastName << endl;
			cout << "Balance: " << accounts[i].balance << endl;
		}
	}
}
int main()
{
	BankAccount* accounts = nullptr;
	long long size = 1000;
	long long count = 0;
	accounts = new BankAccount[size];
	int choice;
	while (true) {
		cout << "1.Open Account\n2.Balance Enquiry\n3.Deposit\n4.Withdraw\n5.Close Account\n6.Show All Account\n7.Exit\nEnter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			Open_Account(accounts, count, size);
		}
		else if (choice == 2)
		{
			Balance_Enquiry(count, accounts);
		}
		else if (choice == 3)
		{
			Deposit(count, accounts);
		}
		else if (choice == 4)
		{
			Withdraw(count, accounts);
		}
		else if (choice == 5)
		{
			Close_Account(count, accounts);
		}
		else if (choice == 6)
		{
			Show_All_Account(count, accounts);
		}
		else if (choice == 7)
		{
			cout << "Exiting System....\n";
			break;
		}
		else {
			cout << "Invalid choice. Try again.\n";
		}
		

	}
}