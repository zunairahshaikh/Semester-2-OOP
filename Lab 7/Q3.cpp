/*Envision creating a robust application for a global finance firm that needs to handle and compute multiple currencies with real-time conversion capabilities.
This system is built on a base class called Currency, which contains core data members such as amount, currencyCode, currencySymbol, and an optional exchangeRate.
It provides functions like convertToBase() for converting the amount into a common base currency, convertTo(targetCurrency) for converting between currencies, and
displayCurrency() for showcasing currency details.

Derived classes like Dollar, Euro, and Rupee extend this foundation by introducing currency-specific details and overriding convertToBase() and displayCurrency() to
reflect the exchange rates and regional currency formats dynamically.*/

#include <iostream>
using namespace std;

class Currency {
    public:
        double amount;
        string currencyCode;
        string currencySymbol;
        double exchangeRate;
 
        Currency(double a, string c, string s, double e = 1.0) : amount(a), currencyCode(c), currencySymbol(s), exchangeRate(e) {}

        virtual void convertToBase() = 0;

        virtual void convertTo(Currency* targetCurrency) = 0;

        virtual void displayCurrency() = 0;
};

class Dollar : public Currency {
    public:
        Dollar(double a, double e = 1.0) : Currency(a, "USD", "$", e) {}

        void convertToBase() override {
            amount /= exchangeRate;
        }

        void convertTo(Currency* targetCurrency) override {
            targetCurrency->convertToBase();
            amount *= targetCurrency->exchangeRate;
        }

        void displayCurrency() override {
            cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

class Euro : public Currency {
    public:
        Euro(double a, double e = 1.92) : Currency(a, "EUR", "€", e) {}

        void convertToBase() override {
            amount /= exchangeRate; // Convert to USD
        }

        void convertTo(Currency* targetCurrency) override {
            targetCurrency->convertToBase();
            amount *= targetCurrency->exchangeRate;
        }

        void displayCurrency() override {
            cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

class Rupee : public Currency {
    public:
        Rupee(double a, double e = 0.0036 ) : Currency(a, "PKR", "Rs", e) {}

        void convertToBase() override {
            amount /= exchangeRate;
        }

        void convertTo(Currency* targetCurrency) override {
            targetCurrency->convertToBase();
            amount *= targetCurrency->exchangeRate;
        }

        void displayCurrency() override {
            cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

int main() {
    Currency* currencies[3];
    currencies[0] = new Dollar(100);
    currencies[1] = new Euro(100);
    currencies[2] = new Rupee(100);

    for (int i = 0; i < 3; i++) {
        currencies[i]->convertTo(currencies[(i + 1) % 3]); // Convert to the next currency in the array
        currencies[i]->displayCurrency();
        cout << endl;
    }

    return 0;
}