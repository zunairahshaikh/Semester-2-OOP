/*Q1. Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor
should initialize this data to 0, and another should initialize it to fixed values. Another member function should
display it, in 11:59:59 format. The final member function should add two objects of type time passed as
arguments.
A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized.
Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should
display the value of this third variable. Make appropriate member functions const.*/

#include <iostream>
#include <iomanip>
using namespace std;

class Time{
    int hours;
    int minutes;
    int seconds;

    public:
        Time() : hours(0), minutes(0), seconds(0) {}
        Time(int hrs, int mins, int secs) : hours(hrs), minutes(mins), seconds(secs) {}

        void displayTime() const {
            cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
        }

        Time addTime(const Time& otherValue){
             int total_seconds = (hours * 3600 + minutes * 60 + seconds) + 
                            (otherValue.hours * 3600 + otherValue.minutes * 60 + otherValue.seconds);

            int new_hours = total_seconds / 3600;
            total_seconds %= 3600;
            int new_minutes = total_seconds / 60;
            int new_seconds = total_seconds % 60;

            return Time(new_hours, new_minutes, new_seconds);
        }
};

int main(){
    Time t1(9,2,45);
    Time t2(3,5,7);
    Time t3;

    t3 = t1.addTime(t2);
    cout << "New time is: ";
    t3.displayTime();
}
