/*Imagine designing a digital management system for a large university that seamlessly integrates academic and administrative operations. At the heart of this system is a Person
class that stores universal data members such as name, id, address, phoneNumber, and email. It provides functions like displayInfo() to show personal details and updateInfo()
to modify them.

Derived classes—Student, Professor, and Staff—extend this system by introducing specific data members:
Student includes coursesEnrolled, GPA, and enrollmentYear, modifying displayInfo() to show academic records.
Professor has department, coursesTaught, and salary, updating displayInfo() to display faculty-specific details.
Staff maintains department, position, and salary, tailoring displayInfo() to reflect administrative roles.

An additional Course class, with attributes like courseld, courseName, credits, instructor, and schedule, provides functions such as registerStudent(student) and
calculateGrades(). This ensures an interactive system where function overrides enable dynamic role-based management.*/

#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
        int id;
        string address;
        string phoneNumber;
        string email;
    public:
        Person(string n, int i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}

        virtual void displayInfo(){
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Email: " << email << endl;
        }

        void updateInfo(string n, int i, string a, string p, string e){
            name = n;
            id = i;
            address = a;
            phoneNumber = p;
            email = e;
        }
};

class Student : public Person{
    private:
        string coursesEnrolled;
        double GPA;
        int enrollmentYear;
    public:
        Student(string n, int i, string a, string p, string e, string ce, double g, int ey) : Person(n, i, a, p, e), coursesEnrolled(ce), GPA(g), enrollmentYear(ey) {}

        void displayInfo() override{
            Person::displayInfo();
            cout << "Courses Enrolled: " << coursesEnrolled << endl;
            cout << "GPA: " << GPA << endl;
            cout << "Enrollment Year: " << enrollmentYear << endl;
        }
};

class Professor : public Person{
    private:
        string department;
        string coursesTaught;
        double salary;
    public:
        Professor(string n, int i, string a, string p, string e, string d, string ct, double s) : Person(n, i, a, p, e), department(d), coursesTaught(ct), salary(s) {}

        void displayInfo() override{
            Person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Courses Taught: " << coursesTaught << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Staff : public Person{
    private:
        string department;
        string position;
        double salary;
    public:
        Staff(string n, int i, string a, string p, string e, string d, string pos, double s) : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}

        void displayInfo() override{
            Person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Position: " << position << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Course{
    private:
        int courseID;
        string courseName;
        int credits;
        string instructor;
        string schedule;
    public:
        Course(int ci, string cn, int c, string i, string s) : courseID(ci), courseName(cn), credits(c), instructor(i), schedule(s) {}

        void registerStudent(Student* student){
            cout << student->name << " registered for " << courseName << endl;
        }

        void calculateGrades(){
            cout << "Grades calculated for " << courseName << endl;
        }
};
