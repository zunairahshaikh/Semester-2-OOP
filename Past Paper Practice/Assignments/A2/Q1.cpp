/*We’re gonna be picking up where we left off in the last assignment: FAST’s Transportation
System.
For this scenario, you are required to revisit the system, and update it according to the newer
concepts that we have discussed. It should include the following concepts: Inheritance,
Constructor Chaining, Polymorphism (static/dynamic), Operator Overloading, etc.
Things to consider:
Introduce new classes, such as teacher and staff members who can also avail the transport. Is
there a parent class that can encompass some of the functionalities for students, teachers and
staff members? Are some functionalities different between users? For example, students pay on
a semester-by-semester basis, and teachers pay on a monthly basis.
Can you perform operator overloading to verify if two objects are the same or not? If so,
demonstrate it in your classes. For example; are two routes the same?
Feel free to refer to the question # 4 from the previous assignment for functionalities that you
have used.*/

#include <iostream>
using namespace std;

class TransportUser {
protected:
    int userID;
    string name;
    string pickupStop, dropOffStop;
    bool isCardActive;

public:
    TransportUser(int id, string n, string pick, string drop)
        : userID(id), name(n), pickupStop(pick), dropOffStop(drop), isCardActive(true) {}

    virtual ~TransportUser() {}

    virtual void payFees() = 0;

    void updatePickupStop(string stop) {
        pickupStop = stop;
        cout << "Pickup stop updated successfully.\n";
    }

    void updateDropOffStop(string stop) {
        dropOffStop = stop;
        cout << "Drop off stop updated successfully.\n";
    }

    int getID() const { return userID; }
    string getPickupStop() const { return pickupStop; }
    string getDropOffStop() const { return dropOffStop; }
};

class Student : public TransportUser {
    bool attendance[31];

public:
    Student(int id, string n, string pick, string drop)
        : TransportUser(id, n, pick, drop) {
        for (int i = 0; i < 31; i++) 
            attendance[i] = false;
    }

    void payFees() override {
        isCardActive = true;
        cout << name << " paid semester fees successfully.\n";
    }

    void recordAttendance(int day) {
        if (day < 1 || day > 31) {
            cout << "Invalid day! Please enter between 1 and 30.\n";
            return;
        }
        if (isCardActive) {
            attendance[day - 1] = true;
            cout << "Attendance recorded for " << name << " on day " << day << ".\n";
        } else {
            cout << "Card inactive for " << name << ". Please pay fees.\n";
        }
    }

    void displayAttendance() const {
        cout << "\nAttendance for " << name << ":\n";
        for (int i = 0; i < 31; i++) {
            cout << "Day " << (i + 1) << ": " << (attendance[i] ? "Present" : "Absent") << endl;
        }
    }
};

class Teacher : public TransportUser {
public:
    Teacher(int id, string n, string pick, string drop)
        : TransportUser(id, n, pick, drop) {}

    void payFees() override {
        isCardActive = true;
        cout << name << " paid monthly transport fees successfully.\n";
    }
};

class Staff : public TransportUser {
public:
    Staff(int id, string n, string pick, string drop)
        : TransportUser(id, n, pick, drop) {}

    void payFees() override {
        isCardActive = true;
        cout << name << " (Staff) paid transport fees successfully.\n";
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
            cout << "Stop " << stopName << " added to " << busRouteName << ".\n";
        } else {
            cout << "Cannot add more stops. Maximum limit reached!\n";
        }
    }

    bool operator==(const Bus &other) const {       //comparing if two buses have the same route
        if (currentStops != other.currentStops) return false;
        for (int i = 0; i < currentStops; i++) {
            if (routeStops[i] != other.routeStops[i]) return false;
        }
        return true;
    }

    void displayRoute() const {
        cout << "\nBus: " << busRouteName << "\nStops: ";
        for (int i = 0; i < currentStops; i++)
            cout << routeStops[i] << " -> ";
        cout << "FAST\n";
    }

    string getID() const { return busID; }
};

class TransportSystem {
    TransportUser** users;
    int userCount;
    Bus** buses;
    int busCount;
    static int totalUsers;

public:
    TransportSystem(int maxUsers, int maxBuses) {
        users = new TransportUser*[maxUsers];
        buses = new Bus*[maxBuses];
        userCount = 0;
        busCount = 0;
    }

    ~TransportSystem() {
        for (int i = 0; i < userCount; i++) 
            delete users[i];
        delete[] users;

        for (int i = 0; i < busCount; i++) 
            delete buses[i];
        delete[] buses;
    }

    void registerUser(int id, string name, string pick, string drop, string type) {
        if (type == "student") {
            users[userCount++] = new Student(id, name, pick, drop);
        } else if (type == "teacher") {
            users[userCount++] = new Teacher(id, name, pick, drop);
        } else if (type == "staff") {
            users[userCount++] = new Staff(id, name, pick, drop);
        }
        totalUsers++;
        cout << name << " registered successfully for transport!\n";
    }

    void addBus(string id, string name, int maxStops) {
        buses[busCount++] = new Bus(id, name, maxStops);
        cout << "Bus " << name << " added successfully!\n";
    }

    void defineRoute() {
        string busID;
        int numStops;

        cout << "Enter Bus ID: ";
        cin >> busID;

        Bus* selectedBus = nullptr;
        for (int i = 0; i < busCount; i++) {
            if (buses[i]->getID() == busID) {
                selectedBus = buses[i];
                break;
            }
        }

        if (!selectedBus) {
            cout << "Bus ID not found!\n";
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

        cout << "Route successfully defined for bus " << busID << "!\n";
    }

    void displayAllBuses() const {
        for (int i = 0; i < busCount; i++)
            buses[i]->displayRoute();
    }
};

int TransportSystem::totalUsers = 0;

int main() {
    cout << "FAST Transport System\n";
    TransportSystem transport(10, 5);

    transport.registerUser(1, "Zunairah", "Five_Star", "Five_Star", "student");
    transport.registerUser(2, "Duaa", "Imtiaz", "Imtiaz", "teacher");

    transport.addBus("5b", "5b", 5);
    transport.addBus("8", "8", 4);

    transport.defineRoute();
    transport.displayAllBuses();

    return 0;
}
