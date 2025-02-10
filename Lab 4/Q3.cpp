/*You are building a bank account management system. Create a class `Account` to manage bank
accounts.
Requirements:
1. Attributes:
 `accountNumber` (string)
 `accountHolderName` (string)
 `balance` (double)
2. Define a default constructor that initializes `balance` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `deposit(double amount)`: Adds the amount to the balance.
 `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are
available).
 `checkBalance()`: Displays the current balance.
5. Create a few `Account` objects and test the methods.*/

#include <iostream>
using namespace std;

class Account {
    string accountNumber;
    string accountHolderName;
    double balance;

    public:
        Account() : accountNumber("NULL"), accountHolderName("Unknown"), balance(0.0) {};
        Account(string num, string name, double b) : accountNumber(num), accountHolderName(name), balance(b) {}

        void deposit(double amount){
            this->balance += amount;
            cout << "\nSuccessfully Deposited " << amount;
        }

        void withdraw(double amount){
            if (this->balance >= amount){
                this->balance -= amount;
                cout << "\nSuccessfully Withdrawn " << amount;
                cout << "\nRemaining balance: " << this->balance;
            }
            else{
                cout << "\nInsufficient Balance";
            }
        }
        
        void checkBalance(){
            cout << "\nCurrent balance: " << this->balance;
        }
};

int main()
{
    Account a1;
    cout << "Account 1:";
    a1.checkBalance();

    cout << "\nAccount 2:";
    Account a2("PK1234567891234", "Laiba Khan", 40000);
    a2.checkBalance();
    a2.withdraw(20000);
    a2.deposit(13000);
    a2.checkBalance();
    return 0;
}