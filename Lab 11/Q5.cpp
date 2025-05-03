/*Create a template class BankAccount<T> where T is the currency type (e.g., double, int).  
Throw an InsufficientFundsException (class) if a withdrawal exceeds the balance. Include the deficit amount
in the exception message.

Requirements:
- withdraw(T amount) throws the exception if amount > balance.
- Catch the exception and display the deficit.

Sample Input/Output:
Balance: $500.00
Withdraw $600: InsufficientFundsException - Deficit: $100.00*/

#include <iostream>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception {
    double deficit;
    public:
        InsufficientFundsException(double deficit) : deficit(deficit) {}

        const char* what() const noexcept override {
            return "Insufficient funds for withdrawal.";
        }
        double getDeficit() const {
            return deficit;
        }
};

template <typename T>
class BankAccount {
    T balance;
    public:
        BankAccount(T initialBalance) : balance(initialBalance) {}

        void withdraw(T amount) {
            if (amount > balance) {
                throw InsufficientFundsException(amount - balance);
            }
            balance -= amount;
        }

        T getBalance() const {
            return balance;
        }
};

int main() {
    try{
        BankAccount<double> acc(500.0);
        cout << "Balance: $" << acc.getBalance() << endl;
        acc.withdraw(600.0);
    }
    catch (const InsufficientFundsException& e) {
        cout << e.what() << " Deficit: $" << e.getDeficit() << endl;
    }
    catch (const exception& e) {
        cout << "Unknown Error."<< endl;
    }
}