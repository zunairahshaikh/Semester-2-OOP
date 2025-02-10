/*You are building a student management system. Create a class `Student` to manage student records.
Requirements:
1. Attributes:
 `studentID` (int)
 `name` (string)
 `age` (int)
 `grade` (char)
2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
 `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
 `displayDetails()`: Displays the student's details.
5. Create a few `Student` objects and test the methods.*/

#include <iostream>
using namespace std;

class Student{
    int studentID;
    string name;
    int age;
    char grade;

    public:
        Student(): studentID(0), name(""), age(0), grade('N'){}
        Student(int id, string n, int a,char gr) : studentID(id), name(n), age(a), grade(gr){}

        void promoteStudent(){
            if (grade == 'A') {
            cout << "Student is already at the highest grade." << endl;
        } else if (grade == 'B') {
            grade = 'A';
        } else if (grade == 'C') {
            grade = 'B';
        } else if (grade == 'D') {
            grade = 'C';
        } else if(grade == 'N'){ 
            cout << "Assign a grade first";
        } else {
            cout << "Invalid grade to promote." << endl;
        }
        }

        bool isEligibleForScholarship(){
            if(grade == 'A')
                return true;
            else
                return false;
        }

        void displayDetails() const{
            cout << "\nStudent " << name << "'s details:\n";
            cout << "ID: " << studentID << endl << "Name: " << name << endl << "Age" << age << endl << "Grade: " << grade << endl;
        }
};

int main(){
    Student student1(001, "Hasan", 18, 'B');
    Student student2(002, "Sarah", 19, 'A');

    student1.displayDetails();

    student2.displayDetails();


    student1.promoteStudent();
    cout << "Student 1 after promotion:" << endl;
    student1.displayDetails();
    cout << endl;

    cout << "Is Student 2 eligible for scholarship? " << (student2.isEligibleForScholarship() ? "Yes" : "No") << endl;
}
