/*Q2: Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F*/

#include <iostream>
using namespace std;

int main(){
    int totStd;
    float eng, mth, sci, totMarks =0.0, avgMarks=0.0, perc;
    char grade;

    cout << "Enter total number of students: ";
    cin >> totStd;

    for(int i = 0; i < totStd; i++){
        cout << "Enter marks for english of student: ";
        cin >> eng;
        cout << "Enter marks for math of student: ";
        cin >> mth;
        cout << "Enter marks for science of student: ";
        cin >> sci;
        totMarks = eng + mth + sci;
        avgMarks = totMarks/3;
        perc = totMarks/300*100;
        if(perc >= 90)
            grade = 'A';
        else if(perc >= 80 && perc <= 89)
            grade = 'B';
        else if(perc >= 70 && perc <= 79)
            grade = 'C';
        else if(perc >= 60 && perc <= 69)
            grade = 'D';
        else if(perc < 60)
            grade = 'F';

        cout << "Total Marks: " << totMarks <<"/300" << endl << "Average Marks: " << avgMarks << endl << "Grade: " << grade << endl;
        cout << endl;
    }
}

