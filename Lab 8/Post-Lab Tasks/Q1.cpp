/*A bank provides different types of accounts, such as Savings Account and Current Account.

Each account has a method to calculate the annual interest, but the formula differs for different account types.
Additionally, the bank allows overloading the deposit method to handle different types of
deposits (cash, check, online transfer).

The withdraw method is overridden to implement specific rules for different accounts.
Moreover, the bank maintains customer balances in an object, and it supports operator overloading for addition (+), subtraction (-),
multiplication (*), and division (/) to handle balance calculations efficiently.

Task Requirements:
1. Create a base class BankAccount with attributes like accountNumber, balance, and a virtual function calculateInterest().

2. Implement two derived classes:
o SavingsAccount (Interest: 5% per year)
o CurrentAccount (Interest: No interest)

3. Overload the deposit method in both derived classes to handle:
o Deposit via cash
o Deposit via check
o Deposit via online transfer

4. Override the withdraw method in both derived classes with different rules:
o SavingsAccount: Cannot withdraw if balance is below $500
o CurrentAccount: Allows overdraft up to $1000

5. Implement operator overloading in BankAccount:
o + to add two account balances
o - to subtract an amount from balance
o * to apply interest on balance
o / to calculate equal installment payments from balance

6. Create objects of both SavingsAccount and CurrentAccount, demonstrate method overloading, overriding, and operator overloading with
real transaction examples.*/

#include <iostream>
using namespace std;

class BankAccount{
protected:
    int accountNumber;
    double balance;

public:
    BankAccount(int a, double b) : accountNumber(a), balance(b) {}

    virtual void calculateInterest();

    void deposit(double amount){
        balance += amount;
        cout << "A Cash Amount of Rs " << amount << " Deposited Successfully!\n New balance: Rs " << balance << endl;
    }

    void deposit(double amount, string checkNum){
        balance += amount;
        cout << "An Amount of Rs " << amount << " Deposited Successfully via check: " << checkNum << "\n New balance: Rs " << balance << endl;
    }

    void deposit(double amount, string transferringBank, string accNum){
        balance += amount;
        cout << "An Amount of Rs " << amount << " Deposited Successfully via " << transferringBank << " from Account Number: " << accNum << "\n New balance: Rs " << balance << endl;
    }

    virtual void withdraw(double amount){
        balance -= amount;
        cout << "An amount of Rs " << amount << " withdrawn successfully!\n New balance: Rs " << balance << endl;
    }

    BankAccount operator+(const BankAccount &other){
        return BankAccount(accountNumber, balance + other.balance);
    }

    BankAccount operator-(double amount){
        return BankAccount(accountNumber, balance - amount);
    }

    BankAccount operator*(double interestRate){
        return BankAccount(accountNumber, balance * (1 + interestRate / 100));
    }

    BankAccount operator/(int installments){
        return BankAccount(accountNumber, balance / installments);
    }

    void display() const{
        cout << "Account: " << accountNumber << "\nBalance: Rs " << balance << endl;
    }
};

class SavingsAccount : public BankAccount{

    public:
        SavingsAccount(int a, double b) : BankAccount(a, b) {}

        void calculateInterest() override{
            balance += (balance * 0.05);
            cout << "Interest applied 5%. New Balance: " << balance << endl;
        }

        void withdraw(double amount) override{
            if (balance < 500 || balance - amount < 500){
                cout << "Cannot withdraw when current balance or balance after transaction is less then Rs 500" << endl;
            }
            else{
                BankAccount::withdraw(amount);
            }
        }
};

class CurrentAccount : public BankAccount{

    public:
        CurrentAccount(int a, double b) : BankAccount(a, b) {}

        void calculateInterest() override{
            cout << "No interest applied for Current Account." << endl;
        }

        void withdraw(double amount) override{
            if (balance - amount < -1000){
                cout << "Overdraft limit Exceeded!" << endl;
            }
            else{
                BankAccount::withdraw(amount);
            }
        }
};

int main()
{
    SavingsAccount s1(123456, 4000.24);
    CurrentAccount c1(489562, 3080.85);

    cout << "Savings Account Details: " << endl;
    s1.display();

    cout << "\nCurrent Account Details: " << endl;
    c1.display();

    cout << "\nDepositing Rs 200 in cash into Savings Account:" << endl;
    s1.deposit(200);
    cout << "\nDepositing Rs 300 in Current Account via cheque:" << endl;
    c1.deposit(300, "CHK789");
    cout << "\nDepositing Rs 500 in Current Account via Online transfer:" << endl;
    c1.deposit(500, "JazzCash", "03124567891");

    cout << "\nWithdrawing Rs 600 from Savings Account: " << endl;
    s1.withdraw(600);
    cout << "\nWithdrawing Rs 4000 from Current Account: " << endl;
    c1.withdraw(4000);

    cout << "\nCalculating Interest:" << endl;
    s1.calculateInterest();
    c1.calculateInterest();

    cout << "\nTotal balance in both accounts:" << endl;
    BankAccount totalBalance = s1 + c1;
    totalBalance.display();

    cout << "\nTransferring Rs 200:" << endl;
    BankAccount deductedBalance = s1 - 200;
    deductedBalance.display();

    cout << "\nGiving a reward of 5%:" << endl;
    BankAccount bonusApplied = s1 * 5;
    bonusApplied.display();

    cout << "\nPaying an installment:" << endl;
    BankAccount installmentPayment = s1 / 4;
    installmentPayment.display();

    return 0;
}
