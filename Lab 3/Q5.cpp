/*Q5. Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that
stores information about the current year. The user is allowed to store their tasks to do against each day. Assume
only one entry is needed per day.
Create the following methods for your class:
 Add a task. This function accepts three parameters: task details, date and month. It should add a task on the day specified.
 Remove a task. Accepts the date and month as a parameter to remove the task from.
 Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how
you’ll remove a task, and display the updated task list.*/

#include <iostream>
using namespace std;

class Calendar {
    string tasks[12][31];  // 12 months, 31 days for each month
    int currentYear; 
    
    public:

        Calendar(int year) {
            currentYear = year;
            
            for (int month = 0; month < 12; ++month) {
                for (int day = 0; day < 31; ++day) {
                    tasks[month][day] = "";
                }
            }
        }
        
        void addTask(const string& taskDetails, int day, int month) {
            if (day < 1 || day > 31 || month < 1 || month > 12) {
                cout << "Invalid day or month." << endl;
                return;
            }
            
            tasks[month - 1][day - 1] = taskDetails; // subtracting 1 because zero index arrays
        }
        
        void removeTask(int day, int month) {
            if (day < 1 || day > 31 || month < 1 || month > 12) {
                cout << "Invalid day or month." << endl;
                return;
            }
            
            tasks[month - 1][day - 1] = "";
        }
        
        void showTasks() const {
            cout << "Tasks for year " << currentYear << ":" << endl;
            
            for (int month = 0; month < 12; ++month) {
                cout << "\nMonth " << month + 1 << ":" << endl;
                for (int day = 0; day < 31; ++day) {
                    if (!tasks[month][day].empty()) {
                        cout << "Day " << day + 1 << ": " << tasks[month][day] << endl;
                    }
                }
            }
        }
};

int main() {
    
    Calendar calendar(2025);
    
    calendar.addTask("First Day of classes", 20, 1);    
    calendar.addTask("Doctor Appointment", 5, 2);    
    calendar.addTask("Mid 1", 22, 2);     
    calendar.addTask("Birthday Party", 10, 3);     
    calendar.addTask("Assignment Submission", 22, 3); 

    cout << "\nInitial Task List:" << endl;
    calendar.showTasks();
    
    calendar.removeTask(5, 2);
    
    cout << "\nUpdated Task List:" << endl;
    calendar.showTasks();
    
}
