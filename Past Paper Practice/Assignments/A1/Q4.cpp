/*FAST’s transportation system currently has a troublesome process for student registration, semester payments, and to verify it manually on points. They want you to automate the entire
process to streamline the system.
The system should
• Allow students to register for the transportation service.
• Enable students to pay semester fees to keep their transportation cards active.
• Manage routes, including pick-up and drop-off stops for students.
• Record attendance automatically when students tap their cards on the bus.
• Manage bus routes with stops and assign students to appropriate stops.

Identify the required classes, their data members, and member functions. Then, create a class diagram to represent the system. Based on your class diagram, write a C++ program to implement the system.

You must follow all the OOP rules learned up to the 5th week. This means using proper getters and setters, constructors, destructors, and making use of constant and static variables where needed.*/

#include <iostream>
using namespace std;

class Student {
    int studentID;
    string name;
    string pickupStop, dropOffStop;
    bool isCardActive;
    bool attendance[31];

public:
    Student(int id, string n, string pick, string drop) : studentID(id), name(n), pickupStop(pick), dropOffStop(drop), isCardActive(true) {
        for (int i = 0; i < 31; i++) 
            attendance[i] = false;
    }

    ~Student() {}

    void payFees() {
        isCardActive = true;
        cout << "Fees paid successfully." << endl;
    }

    void updatePickupStop(string stop) {
        pickupStop = stop;
        cout << "Pickup stop updated successfully. " << endl;
    }

    void updateDropOffStop(string stop) {
        dropOffStop = stop;
        cout << "Drop off stop updated successfully." << endl;
    }

    void recordAttendance(int day) {
        if (day < 1 || day > 31) {
            cout << "Invalid day. Please enter a day between 1 and 30." << endl;
            return;
        }

        if (isCardActive) {
            attendance[day - 1] = true;
            cout << "Attendance recorded for " << name << " on day " << day << "." << endl;
        } else {
            cout << "Card inactive for " << name << ". Please pay fees." << endl;
        }
    }

    void displayAttendance() const {
        cout << "\nAttendance for " << name << ":\n";
        for (int i = 0; i < 31; i++) {
            cout << "Day " << (i + 1) << ": " << (attendance[i] ? "Present" : "Absent") << endl;
        }
    }

    void displayDetails() const {
        cout << "\nStudent Details\n";
        cout << "ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Pickup Stop: " << pickupStop << endl;
        cout << "Drop off Stop: " << dropOffStop << endl;
        cout << "Card Active: " << (isCardActive ? "Yes" : "No") << endl;
    }

    int getID() const{
        return studentID;
    }

    string getPickupStop() const{
        return pickupStop;
    }

    string getDropOffStop() const{
        return dropOffStop;
    }
};

class Bus {
    string busID;
    string busRouteName;
    string* routeStops;
    int maxStops;
    int currentStops;

public:
    Bus(string id, string name, int ms) 
        : busID(id), busRouteName(name), maxStops(ms), currentStops(0) {
        routeStops = new string[maxStops];
    }

    ~Bus(){
        delete[] routeStops;
    }

    void addStop(string stopName) {
        if (currentStops < maxStops) {
            routeStops[currentStops++] = stopName;
            cout << "Stop " << stopName << " added successfully to " << busRouteName << "." << endl;
        } else {
            cout << "Cannot add more stops to " << busRouteName << ". Maximum limit reached!" << endl;
        }
    }

    void removeStop(string stopName){
        for (int i = 0; i < currentStops; i++) {
            if (routeStops[i] == stopName) {
                for (int j = i; j < currentStops - 1; j++) 
                    routeStops[j] = routeStops[j + 1];
                currentStops--;
                cout << "Stop " << stopName << " removed successfully from " << busRouteName << "." << endl;
                return;
            }
        }
        cout << "Stop " << stopName << " not found in " << busRouteName << "." << endl;
    }

    void displayRoute() const {
        cout << "\nBus: " << busRouteName << endl << "Stops: ";
        for (int i = 0; i < currentStops; i++)
            cout << routeStops[i] << " -> ";
        cout << "FAST" << endl;
    }

    bool isStopValid(string stop) const {
        for (int i = 0; i < currentStops; i++) {
            if (routeStops[i] == stop)
                return true;
        }
        return false;
    }

    string getID() const {
        return busID;
    }
};

class TransportSystem {
    Student** students;
    int studentCount;
    Bus** buses;
    int busCount;
    static int totalStudents;

public:
    TransportSystem(int maxStudents, int maxBuses) {
        students = new Student*[maxStudents];
        buses = new Bus*[maxBuses];
        studentCount = 0;
        busCount = 0;
    }

    ~TransportSystem() {
        for (int i = 0; i < studentCount; i++) 
            delete students[i];
        delete[] students;

        for (int i = 0; i < busCount; i++) 
            delete buses[i];
        delete[] buses;
    }

    void registerStudent(int id, string name, string pick, string drop) {
        students[studentCount++] = new Student(id, name, pick, drop);
        totalStudents++;
        cout << name << " registered successfully for transport!\n";
    }

    void addBus(string id, string name, int maxStops) {
        buses[busCount++] = new Bus(id, name, maxStops);
        cout << "Bus " << name << " added successfully!\n";
    }
    
    void defineRoute() { // Now part of TransportSystem
        string busID;
        int numStops;

        cout << "Enter Bus ID to define route: ";
        cin >> busID;

        Bus* selectedBus = nullptr;
        for (int i = 0; i < busCount; i++) {
            if (buses[i]->getID() == busID) {
                selectedBus = buses[i];
                break;
            }
        }

        if (!selectedBus) {
            cout << "Bus ID not found!" << endl;
            return;
        }

        cout << "Enter number of stops: ";
        cin >> numStops;

        for (int i = 0; i < numStops; i++) {
            string stop;
            cout << "Enter stop " << (i + 1) << ": ";
            cin >> stop;
            selectedBus->addStop(stop);
        }

        cout << "Route successfully defined for bus " << busID << "!" << endl;
    }


    void assignStopToBus(string busID, string stop) {
        for (int i = 0; i < busCount; i++) {
            if (buses[i]->getID() == busID) {
                buses[i]->addStop(stop);
                return;
            }
    }
    cout << "No bus with ID " << busID << " found!\n";
    }

    void markAttendance(int studentID, int day) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == studentID) {
                students[i]->recordAttendance(day);
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void displayStudentAttendance(int studentID) const {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == studentID) {
                students[i]->displayAttendance();
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void displayAllStudents() const {
        cout << "\nTotal Students: " << totalStudents << endl;
        for (int i = 0; i < studentCount; i++)
            students[i]->displayDetails();
    }

    void displayAllBuses() const {
        for (int i = 0; i < busCount; i++)
            buses[i]->displayRoute();
    }
};

int TransportSystem::totalStudents = 0;

int main() {
    cout <<"Zuniarh Aziz Shaikh 24k-0986" << endl;

    cout << endl;

    cout << "FAST Transport System" << endl;
    TransportSystem transport(10, 5);

    transport.registerStudent(1, "Zunairah", "Five_Star", "Five_Star");
    transport.registerStudent(2, "Duaa", "Imtiaz", "Imtiaz");
    
    cout << endl;

    transport.addBus("5b", "5b", 5);
    
    cout << endl;
    
    transport.addBus("8", "8", 4);
    
    cout << endl;
    
    transport.defineRoute();
    
    cout << endl;

    transport.assignStopToBus("5b", "Five_Star");
    transport.assignStopToBus("5b", "Imtiaz");
    
    cout << endl;

    transport.markAttendance(1, 1);
    transport.markAttendance(1, 2);
    transport.markAttendance(2, 3);
    transport.markAttendance(2, 5);

    transport.displayAllStudents();

    return 0;
}
