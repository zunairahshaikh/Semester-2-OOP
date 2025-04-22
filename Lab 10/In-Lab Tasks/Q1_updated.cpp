#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

int main() {
    Student students[5];

    ofstream studentsFile("students.txt", ios::out);
    if (!studentsFile) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        cout << "Enter details for student " << (i + 1) << endl;
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "GPA: ";
        cin >> students[i].gpa;

        studentsFile << students[i].id << " " << students[i].name << " " << students[i].gpa << endl;
        cout << endl;
    }
    studentsFile.close();

    Student newStudent;
    cout << "Enter details for the additional student" << endl;
    cout << "ID: ";
    cin >> newStudent.id;
    cout << "Name: ";
    cin >> newStudent.name;
    cout << "GPA: ";
    cin >> newStudent.gpa;

    studentsFile.open("students.txt", ios::app);
    if (!studentsFile) {
        cout << "Error opening file for appending." << endl;
        return 1;
    }
    studentsFile << newStudent.id << " " << newStudent.name << " " << newStudent.gpa << endl;
    students[5] = newStudent;  // Add new student to the array
    studentsFile.close();

    ifstream readFile("students.txt", ios::in);
    if (!readFile) {
        cout << "Error opening file for reading." << endl;
        return 1;
    }

    cout << "Existing records of all students: \n";
    for (int i = 0; i < 6; i++) {
        readFile >> students[i].id >> students[i].name >> students[i].gpa;
        cout << "ID: " << students[i].id << " Name: " << students[i].name << " GPA: " << students[i].gpa << endl;
    }
    readFile.close();

    cout << "\nReading from the start of the file:\n";
    for (int i = 0; i < 6; i++) {
        cout << "ID: " << students[i].id << " Name: " << students[i].name << " GPA: " << students[i].gpa << endl;
    }

    cout << "\nReading from the middle of the file:\n";
    int middleIndex = 3;  // Middle index for 6 students
    for (int i = middleIndex; i < 6; i++) {
        cout << "ID: " << students[i].id << " Name: " << students[i].name << " GPA: " << students[i].gpa << endl;
    }

    cout << "\nReading from the end of the file:\n";
    if (6 > 0) {
        cout << "ID: " << students[5].id << " Name: " << students[5].name << " GPA: " << students[5].gpa << endl;
    }

    return 0;
}
