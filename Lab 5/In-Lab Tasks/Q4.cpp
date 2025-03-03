/*Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber, accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account details (accountNumber, accountHolderName, and balance).
Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if sufficient funds are available.
• display(): Displays the account details including the account number, account holder name, and balance.
In the main() function, create an array accounts of BankAccount objects. The array contains three elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder name, and initial balance.*/

#include <iostream>
using namespace std;

class BankAccount{
        int accountNumber;
        string accountHolderName;
        double balance;
    public:
        BankAccount(int accountNumber, string accountHolderName, double balance){
            this->accountNumber = accountNumber;
            this->accountHolderName = accountHolderName;
            this->balance = balance;
        }
        void deposit(double amount){
            balance += amount;
        }
        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
            }
            else{
                cout << "Insufficient funds" << endl;
            }
        }
        void display() const {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder Name: " << accountHolderName << endl;
            cout << "Balance: $" << balance << endl;
        }
};

int main(){
    BankAccount accounts[3] = {
        BankAccount(12345, "Laiba Khan", 1000),
        BankAccount(54321, "Aamna Rizwan", 2000),
        BankAccount(67890, "Abeeha binte aamer", 3000)
    };

    cout << "Account Details: \n" << endl;
    for(int i = 0; i < 3; i++){
        accounts[i].display();
        cout << endl;
    }

    return 0;
}
