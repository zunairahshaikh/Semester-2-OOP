#include <iostream>
using namespace std;

class Account
{
protected:
    string accNum;
    string accHolder;
    double balance;

public:
    Account(string num, string holder, double bal) : accNum(num), accHolder(holder), balance(bal) {}
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "insufficient Balance" << endl;
        }
    }

    Account operator+(const Account &a)
    {
        return Account(accNum, accHolder, balance + a.balance);
    }

    Account operator-=(double amount)
    {
        return Account(accNum, accHolder, balance -= amount);
    }

    bool operator>(const Account &a)
    {
        return balance > a.balance;
    }

    friend ostream &operator<<(ostream &os, const Account &a);
};

ostream &operator<<(ostream &os, const Account &a)
{
    os << a.accHolder << endl;
    os << a.accNum << endl;
    os << a.balance << endl;
    return os;
}

int main()
{
    Account acc1("12345", "Zunairah", 1000.0);
    Account acc2("67890", "Aamna", 2000.0);

    cout << "Initial Account Details:" << endl;
    cout << "Account 1: " << acc1 << endl;
    cout << "Account 2: " << acc2 << endl;

    // Deposit money into Account 1
    acc1.deposit(500.0);
    cout << "\nAfter depositing 500 into Account 1:" << endl;
    cout << "Account 1: " << acc1 << endl;

    // Withdraw money from Account 2
    acc2.withdraw(300.0);
    cout << "\nAfter withdrawing 300 from Account 2:" << endl;
    cout << "Account 2: " << acc2 << endl;

    // Add balances of two accounts
    Account acc3 = acc1 + acc2;
    cout << "\nAfter adding balances of Account 1 and Account 2:" << endl;
    cout << "New Account (Account 3): " << acc3 << endl;

    // Transfer money from Account 1
    acc1 -= 200.0;
    cout << "\nAfter transferring 200 from Account 1:" << endl;
    cout << "Account 1: " << acc1 << endl;

    cout << "\nComparing balances of Account 1 and Account 2:" << endl;
    if (acc1 > acc2)
    {
        cout << "Account 1 has a higher balance than Account 2." << endl;
    }
    else
    {
        cout << "Account 2 has a higher balance than Account 1." << endl;
    }

    return 0;
}