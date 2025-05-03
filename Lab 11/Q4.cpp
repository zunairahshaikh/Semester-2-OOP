#include <iostream>
#include <cmath>
#include <exception>
using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "Input must be non-negative";
    }
};

class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Non-numeric type detected";
    }
};

template<typename T>
T sqrt_safe(T num) {
    if (typeid(num) != typeid(int) && typeid(num) != typeid(float) && typeid(num) != typeid(double) && typeid(num) != typeid(long) && typeid(num) != typeid(long double)) {
        throw InvalidTypeException();
    }

    if (num < 0) {
        throw NegativeNumberException();
    }
    return sqrt(num);
}

int main() {
    try {
        cout << "sqrt(16) = " << sqrt_safe(16) << endl;
        cout << "sqrt(-4) = " << sqrt_safe(-4) << endl;
    }
    catch (const NegativeNumberException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown error: " << e.what() << endl;
    }
    
    return 0;
}
