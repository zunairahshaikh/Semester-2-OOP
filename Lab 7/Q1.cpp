/*Imagine developing a comprehensive banking system simulator for a prominent financial institution. In this system, a base class called Account encapsulates essential
data members such as accountNumber, balance, accountHolderName, and optionally accountType. It offers member functions like deposit(amount) to add funds, withdraw(amount) to
remove funds with proper error checking, calculateInterest() to compute interest based on varying rules, printStatement() to output detailed transaction histories, and
getAccountInfo() to retrieve general account details.

Derived classes like SavingsAccount, CheckingAccount, and FixedDepositAccount extend this structure by incorporating specialized data members--such as interestRate and
minimumBalance for SavingsAccount or maturityDate and fixedInterestRate for FixedDepositAccount. These derived classes override key functions like calculateInterest() and
printStatement() to provide account-type-specific functionalities. Additionally, the withdraw() function is overridden in specific accounts to apply different transaction rules, 
ensuring that each account type follows realistic banking policies while maintaining polymorphic behavior.*/

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;
    string accountType;

public:
    Account(int an, string ahn, double b, string at = "")
        : accountNumber(an), accountHolderName(ahn), balance(b), accountType(at) {}

    void deposit(double amount) {
        balance += amount;
        cout << "$" << amount << " deposited successfully!" << endl;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully!" << endl;
        } else {
            cout << "Balance insufficient!" << endl;
        }
    }

    void getAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
    }

    virtual void calculateInterest() = 0;

    virtual void printStatement() {
        cout << "Account Statement for " << accountHolderName << " (Account Number: " << accountNumber << "): Balance = " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate, minimumBalance;

public:
    SavingsAccount(int an, string ahn, double b, string at = "Savings", double rate = 0.0, double minBal = 0.0)
        : Account(an, ahn, b, at), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest calculated: " << interest << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount < minimumBalance) {
            cout << "Withdrawal not allowed. Minimum balance requirement not met." << endl;
        } else {
            Account::withdraw(amount);
        }
    }

    void printStatement() override {
        cout << "Savings Account Statement for " << accountHolderName << endl;
        Account::printStatement();  // Call the base class printStatement
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int an, string ahn, double b, string at = "Checking") : Account(an, ahn, b, at) {}

    void calculateInterest() override {
        cout << "No interest in checking account" << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(int an, string ahn, double b, string at = "Fixed Deposit", double rate = 0.0, string date = "0000-00-00")
        : Account(an, ahn, b, at), fixedInterestRate(rate), maturityDate(date) {}

    void calculateInterest() override {
        cout << "Fixed deposit interest will be paid at maturity on " << maturityDate << endl;
        double interest = balance * fixedInterestRate / 100;
        balance += interest;
        cout << "Interest calculated: $" << interest << ", New Balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity date: " << maturityDate << endl;
    }

    void printStatement() override {
        cout << "Fixed Deposit Account Statement for " << accountHolderName << endl;
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }
};

int main() {
    Account* acc1 = new SavingsAccount(1001, "Abeeha", 5000, "Savings", 5.0, 1000);
    acc1->deposit(1000);
    acc1->withdraw(2000);
    acc1->calculateInterest();
    acc1->printStatement();
    cout << endl;

    Account* acc2 = new CheckingAccount(1002, "Laiba", 2000, "Checking");
    acc2->deposit(500);
    acc2->withdraw(1000);
    acc2->calculateInterest();
    acc2->printStatement();
    cout << endl;

    Account* acc3 = new FixedDepositAccount(1003, "Aamna", 10000, "Fixed Deposit", 8.0, "2022-12-31");
    acc3->deposit(2000);
    acc3->withdraw(5000);
    acc3->calculateInterest();
    acc3->printStatement();
    cout << endl;

    return 0;
}
