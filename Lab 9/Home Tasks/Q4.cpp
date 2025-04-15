/*Task 04
Problem: An e-commerce platform aims to support multiple payment methods (credit
cards, digital wallets) to attract global customers. The payment system must validate
transactions securely and allow new payment options (e.g., cryptocurrency) to be added
without rewriting existing code.
Classes and Structure:

• Abstract Class PaymentMethod:
o Member Function:
▪ processPayment(double amount): Pure virtual function to handle
transactions.

• Derived Class CreditCard:
o Data Members:
▪ cardNumber (string): Stores the card number.
o Implements processPayment() to validate and process payments.

• Derived Class DigitalWallet:
o Data Members:
▪ balance (double): Tracks available funds.
o Implements processPayment() to deduct balance.

Flow:
• Create CreditCard and DigitalWallet objects.
• Simulate payments and check for success/failure.*/

#include <iostream>
using namespace std;

class PaymentMethod{
public:
    virtual bool processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod{
protected:
    string cardNumber;

public:
    CreditCard(string c) : cardNumber(c) {}
    bool processPayment(double amount) override {
        if (cardNumber.length() != 16){
            cout << "Invalid credit card number. It must be 16 digits." << endl;
            return false;
        }
        cout << "Processing credit card payment of $" << amount << " using card number: " << cardNumber << endl;
        return true;
    }
};

class DigitalWallet : public PaymentMethod{
protected:
    double balance;

public:
    DigitalWallet(double b) : balance(b) {}

    bool processPayment(double amount) override{
        if (balance < amount){
            cout << "Insufficient Balance!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Processing Digital Wallet payment of $" << amount << "\nNew Balance: " << balance << endl;
        return true;
    }
};

int main(){
    CreditCard cc("1234567890123456");
    DigitalWallet wallet(500.0);

    cout << "Payment attempt 1: CreditCard" << endl;
    if (!cc.processPayment(100.0)){
        cout << "Payment failed!" << endl;
    }
    else{
        cout << "Payment successful!" << endl;
    }

    cout << "\nPayment attempt 2: DigitalWallet" << endl;
  
    if (!wallet.processPayment(200.0)){
        cout << "Payment failed!" << endl;
    }
    else{
        cout << "Payment successful!" << endl;
    }

    cout << "\nPayment attempt 3: DigitalWallet" << endl;
  
    if (!wallet.processPayment(400.0)){
        cout << "Payment failed!" << endl;
    }
    else{
        cout << "Payment successful!" << endl;
    }

    return 0;
}
