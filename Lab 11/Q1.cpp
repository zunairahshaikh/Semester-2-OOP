/*Create a custom exception class InvalidValueException that inherits from std::exception.  
Override the what() method to return a meaningful error message. Use this exception in a function
validateAge(int age) that throws it if age is negative or greater than 120.

Requirements:
- Inherit from std::exception.
- Use const char* what() const noexcept override to provide error messages.
- Handle the exception in main().

Sample Input/Output:
Enter age: -5

Error: InvalidValueException - Age cannot be negative or exceed 120.*/

#include <iostream>
#include <exception>
using namespace std;

class InvalidValueException : public std::exception{
    public:
        const char* what() const noexcept override {
                return "Age is invalid. It has to be between 0 to 120.";
        }
};

void validateAge(int age){
                if(age < 0 || age > 120)
                    throw InvalidValueException();
}

int main(){

    try{
        int userAge;

        cout << "Enter age: ";
        cin >> userAge;

        validateAge(userAge);
    }
    catch(const InvalidValueException& e){
        cout << e.what() << endl;
    }

}
