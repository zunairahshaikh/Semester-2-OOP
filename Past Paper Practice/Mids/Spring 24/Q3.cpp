#include <iostream>
#include <string>
#include <ctime>

class Insurance {
private:
    double premiumRate;

public:
    Insurance(double rate) : premiumRate(rate) {
        std::cout << "Insurance Constructor\n";
    }

    ~Insurance() {
        std::cout << "Insurance Destructor\n";
    }

    double calculatePremium(double balance) const {
        return balance * premiumRate;
    }
};

class Account {
protected:
    double balance;
    std::string creationDate;
    double lastWithdrawalAmount;

public:
    Account(double initialBalance) : balance(initialBalance), lastWithdrawalAmount(0) {
        time_t now = time(0);
        creationDate = ctime(&now);
        std::cout << "Account Constructor\n";
    }

    virtual ~Account() {
        std::cout << "Account Destructor\n";
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            lastWithdrawalAmount = amount;
        } else {
            std::cout << "Insufficient funds\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    std::string getCreationDate() const {
        return creationDate;
    }

    double getLastWithdrawalAmount() const {
        return lastWithdrawalAmount;
    }
};

class SavingsAccount : public Account {
private:
    Insurance* insurance;

public:
    SavingsAccount(double initialBalance, double premiumRate) 
        : Account(initialBalance), insurance(new Insurance(premiumRate)) {
        std::cout << "SavingsAccount Constructor\n";
    }

    ~SavingsAccount() {
        delete insurance;
        std::cout << "SavingsAccount Destructor\n";
    }

    double calculateInsurancePremium() const {
        return insurance->calculatePremium(balance);
    }

    void donate() {
        if (balance >= 500 && lastWithdrawalAmount >= 0 && lastWithdrawalAmount <= 50) {
            balance -= 50; // Assuming a fixed donation amount
            std::cout << "Donation successful\n";
        } else {
            std::cout << "Donation criteria not met\n";
        }
    }
};

class BasicAccount : public Account {
public:
    BasicAccount(double initialBalance) : Account(initialBalance) {
        std::cout << "BasicAccount Constructor\n";
    }

    ~BasicAccount() {
        std::cout << "BasicAccount Destructor\n";
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double initialBalance) : Account(initialBalance) {
        std::cout << "CheckingAccount Constructor\n";
    }

    ~CheckingAccount() {
        std::cout << "CheckingAccount Destructor\n";
    }
};

int main() {
    SavingsAccount savings(1000, 0.01);
    savings.deposit(500);
    savings.withdraw(30);
    std::cout << "Insurance Premium: " << savings.calculateInsurancePremium() << std::endl;
    savings.donate();

    BasicAccount basic(500);
    basic.deposit(200);
    basic.withdraw(100);

    CheckingAccount checking(1500);
    checking.deposit(300);
    checking.withdraw(200);

    return 0;
}
