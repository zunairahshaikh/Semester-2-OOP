/*Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber, accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account details (accountNumber, accountHolderName, and balance).
Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if sufficient funds are available.
• display(): Displays the account details including the account number, account holder name, and balance.
In the main() function, create an array accounts of BankAccount objects. The array contains three elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder name, and initial balance.
Perform following operations:
• Iterate through each account in the accounts array.
• For each account, display the account details using the display() function.
• Perform Two Transactions:
• Deposits 500.0 rupees into the account.
• Withdraws 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance.*/

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
        }
        void display() const{
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder Name: " << accountHolderName << endl;
            cout << "Balance: $" << balance << endl;
        }
};

int main(){
    BankAccount accounts[3] = {
        BankAccount(12345, "Laiba Khan", 1000.0),
        BankAccount(54321, "Aamna Rizwan", 2000.0),
        BankAccount(98765, "Abeeha binte Aamer", 3000.0)
    };

    for(int i = 0; i < 3; i++){
        accounts[i].display();
    }

    accounts[0].deposit(500.0);
    accounts[0].display();

    accounts[0].withdraw(200.0);
    accounts[0].display();

    return 0;
}
