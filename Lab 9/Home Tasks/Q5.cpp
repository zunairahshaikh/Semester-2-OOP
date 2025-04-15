/*Problem: A fitness app wants to help users track calories burned during activities like running and cycling.
Each activity requires unique calculations (e.g., distance vs. speed), but the app must present results consistently.
The system should allow adding new activities (e.g., swimming) in the future.

Classes and Structure:
• Abstract Class Activity:
o Member Function:
▪ calculateCaloriesBurned(): Pure virtual function to compute calories.

• Derived Class Running:
o Data Members:
▪ distance (double): Stores distance in kilometers.
▪ time (double): Stores duration in minutes.
o Implements calculateCaloriesBurned() for running.

• Derived Class Cycling:
o Data Members:
▪ speed (double): Stores speed in km/h.
▪ time (double): Stores duration in hours.
o Implements calculateCaloriesBurned() for cycling.

Flow:
• Create Running and Cycling objects.
• Display calories burned for each activity.*/


#include <iostream>
using namespace std;

class Activity{
    public:
    virtual  double calculateCaloriesBurned() = 0;
};

class Running : public Activity{
    double distance, time;

    public:
    Running(double d, double t) : distance(d), time(t) {}

    double calculateCaloriesBurned() override{
        return distance * time * 0.2; // Assuming 0.2 calories burned per km per hour
    }
};

class Cycling : public Activity{
    double speed, time;

    public:
    Cycling(double s, double t) : speed(s), time(t) {}

    double calculateCaloriesBurned() override{
        return speed * 50; // Assuming 20 calories burned per km/h
    }
};

int main() {
    Running myRun(5.0, 3.5);
    Cycling myCycling(15.0, 1.5);

    cout << "Calories burned while running: " << myRun.calculateCaloriesBurned() << " calories" << endl;
    cout << "Calories burned while cycling: " << myCycling.calculateCaloriesBurned() << " calories" << endl;

    return 0;
}
