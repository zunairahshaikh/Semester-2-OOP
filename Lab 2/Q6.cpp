/*You are tasked with implementing a simple Student Registration System in C++. Define two structures,
Register and Student, where Register contains attributes courseId and courseName, and Student inherits
from Register while having additional attributes such as studentId, firstName, lastName, cellNo, and
email. Your goal is to create an array of Student structures to store information for five students. Write a
C++ program that accomplishes the following tasks:
 Implement the Register and Student structures.
 Inherit the Register structure in the Student structure.
 Create an array of Student structures to store information for 5 students.
 Take input for each student, including their courseId, courseName, studentId, firstName,
lastName, cellNo, and email.
 Display the information for all 5 students.*/

#include <iostream>
#include <string>
using namespace std;

struct Register {
   int courseID;
   string courseName;
};

struct Student : public Register {
   int studentID;
   string firstName;
   string lastName;
   string cellNo;
   string email;
};

int main() {
    Student students[5];

    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";

        cout << "Enter course ID: ";
        cin >> students[i].courseID;
        cin.ignore();

        cout << "Enter course name: ";
        getline(cin, students[i].courseName);

        cout << "Enter student ID: ";
        cin >> students[i].studentID;
        cin.ignore();

        cout << "Enter first name: ";
        getline(cin, students[i].firstName);

        cout << "Enter last name: ";
        getline(cin, students[i].lastName);

        cout << "Enter cell number: ";
        getline(cin, students[i].cellNo);

        cout << "Enter email: ";
        getline(cin, students[i].email);

        cout << endl;
    }

    cout << "\nStudent Information:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "\nDetails for student " << i + 1 << ":\n";
        cout << "Course ID: " << students[i].courseID << endl;
        cout << "Course Name: " << students[i].courseName << endl;
        cout << "Student ID: " << students[i].studentID << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "Cell Number: " << students[i].cellNo << endl;
        cout << "Email: " << students[i].email << endl;
    }
}
