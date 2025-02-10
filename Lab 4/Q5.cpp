/*You are building an employee management system. Create a class `Employee` to manage employee
records.
Requirements:
1. Attributes:
 `employeeID` (int)
 `name` (string)
 `department` (string)
 `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
 `isManager()`: Returns `true` if the employee's department is "Management".
 `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods.*/

#include <iostream>
using namespace std;

class Employee{
    int employeeID;
    string name;
    string department;
    double salary;

    public:
        Employee() : employeeID(0), name(""), department(""), salary(0.0) {};
        Employee(int id, string n, string d, double s) : employeeID(id), name(n), department(d), salary(s) {}

        void giveBonus(double amount){
            salary+= amount;
            cout << "Bonus granted!" << endl;
        }

        bool isManager(){
            if(department == "Management")
                return true;
            else
                return false;
        }

        void displayDetails() const{
            cout << "\nEmployee details:\n";
            cout << "ID: " << employeeID << endl << "Name: " << name << endl << "Department: " << department << endl << "Salary " << salary<< endl;
        }

        string getName(){
            return name;
        }
};

int main(){
    Employee emp1(101, "Danish", "Management", 23000.0);
    Employee emp2(102, "Rabia", "IT", 34000.0);
    Employee emp3(103, "Kashif", "Sales", 27000.0);

    emp2.displayDetails();
    cout << endl;
    emp2.giveBonus(3487.45);
    emp2.displayDetails();
    cout << endl;

    cout << "Is " << emp1.getName() << " a manager? " << (emp1.isManager() ? "Yes" : "No") << endl;
}
