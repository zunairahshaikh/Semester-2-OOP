#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileOpenException : public exception {
public:
    const char* what() const throw() {
        return "Error: Failed to open file!";
    }
};

class MemoryAllocationException : public exception {
public:
    const char* what() const throw() {
        return "Error: Memory allocation failed!";
    }
};

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
    virtual void login() = 0;
    virtual string getUserType() const = 0;

    void updatePickupStop(string stop) {
        pickupStop = stop;
        cout << "Pickup stop updated successfully.\n";
    }

    void updateDropOffStop(string stop) {
        dropOffStop = stop;
        cout << "Drop off stop updated successfully.\n";
    }

    int getID() const { return userID; }
    string getName() const { return name; }
    string getPickupStop() const { return pickupStop; }
    string getDropOffStop() const { return dropOffStop; }
    bool getCardStatus() const { return isCardActive; }
    
    virtual void saveToFile() = 0;
};

class Student : public TransportUser {
    bool attendance[31];
    string password;

public:
    Student(int id, string n, string pick, string drop, string pass = "student123")
        : TransportUser(id, n, pick, drop), password(pass) {
        for (int i = 0; i < 31; i++) 
            attendance[i] = false;
    }

    void payFees() override {
        isCardActive = true;
        cout << name << " paid semester fees successfully.\n";
    }

    void login() override {
        string inputPass;
        cout << "Enter password for student " << name << ": ";
        cin >> inputPass;
        
        if (inputPass == password) {
            cout << "Login successful for student " << name << ".\n";
        } else {
            cout << "Login failed. Incorrect password.\n";
        }
    }

    string getUserType() const override {
        return "Student";
    }

    void recordAttendance(int day) {
        if (day < 1 || day > 31) {
            cout << "Invalid day! Please enter between 1 and 31.\n";
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
    
    void saveToFile() override {
        try {
            ofstream outFile("students.txt", ios::app);
            if (!outFile) {
                throw FileOpenException();
            }
            
            outFile << userID << "|" << name << "|" << pickupStop << "|" << dropOffStop << "|" 
                   << (isCardActive ? "1" : "0") << "|" << password << "|";
            
            for (int i = 0; i < 31; i++) {
                outFile << (attendance[i] ? "1" : "0");
            }
            outFile << "#\n";
            
            outFile.close();
            cout << "Student data saved to file.\n";
        } catch (const FileOpenException& e) {
            cout << e.what() << endl;
        }
    }
    
    static void loadFromFile(Student**& students, int& count) {
        try {
            ifstream inFile("students.txt");
            if (!inFile) {
                throw FileOpenException();
            }
            
            students = new (nothrow) Student*[10];
            if (!students) {
                throw MemoryAllocationException();
            }
            
            count = 0;
            string line;
            
            while (getline(inFile, line) && count < 10) {
                if (line.empty()) continue;
                
                size_t pos = 0;
                string token;
                string tokens[7];
                int tokenCount = 0;
                
                while ((pos = line.find('|')) != string::npos && tokenCount < 7) {
                    token = line.substr(0, pos);
                    tokens[tokenCount++] = token;
                    line.erase(0, pos + 1);
                }
                
                string attendanceStr = line.substr(0, line.find('#'));
                
                if (tokenCount >= 6) {
                    int id = stoi(tokens[0]);
                    string name = tokens[1];
                    string pickup = tokens[2];
                    string dropoff = tokens[3];
                    bool cardActive = (tokens[4] == "1");
                    string password = tokens[5];
                    
                    students[count] = new Student(id, name, pickup, dropoff, password);
                    students[count]->isCardActive = cardActive;
                    
                    for (int i = 0; i < 31 && i < attendanceStr.length(); i++) {
                        students[count]->attendance[i] = (attendanceStr[i] == '1');
                    }
                    
                    count++;
                }
            }
            
            inFile.close();
            cout << count << " student records loaded from file.\n";
        } catch (const FileOpenException& e) {
            cout << e.what() << endl;
        } catch (const MemoryAllocationException& e) {
            cout << e.what() << endl;
        }
    }
};

class Teacher : public TransportUser {
    string otp;

public:
    Teacher(int id, string n, string pick, string drop, string otpValue = "1234")
        : TransportUser(id, n, pick, drop), otp(otpValue) {}

    void payFees() override {
        isCardActive = true;
        cout << name << " paid monthly transport fees successfully.\n";
    }

    void login() override {
        string inputOTP;
        cout << "Enter OTP for teacher " << name << ": ";
        cin >> inputOTP;
        
        if (inputOTP == otp) {
            cout << "Login successful for teacher " << name << ".\n";
        } else {
            cout << "Login failed. Incorrect OTP.\n";
        }
    }

    string getUserType() const override {
        return "Teacher";
    }
    
    void saveToFile() override {
        try {
            ofstream outFile("teachers.txt", ios::app);
            if (!outFile) {
                throw FileOpenException();
            }
            
            outFile << userID << "|" << name << "|" << pickupStop << "|" << dropOffStop << "|" 
                   << (isCardActive ? "1" : "0") << "|" << otp << "#\n";
            
            outFile.close();
            cout << "Teacher data saved to file.\n";
        } catch (const FileOpenException& e) {
            cout << e.what() << endl;
        }
    }
    
    static void loadFromFile(Teacher**& teachers, int& count) {
        try {
            ifstream inFile("teachers.txt");
            if (!inFile) {
                throw FileOpenException();
            }
            
            teachers = new (nothrow) Teacher*[10];
            if (!teachers) {
                throw MemoryAllocationException();
            }
            
            count = 0;
            string line;
            
            while (getline(inFile, line) && count < 10) {
                if (line.empty()) continue;
                
                size_t pos = 0;
                string token;
                string tokens[6];
                int tokenCount = 0;
                
                while ((pos = line.find('|')) != string::npos && tokenCount < 6) {
                    token = line.substr(0, pos);
                    tokens[tokenCount++] = token;
                    line.erase(0, pos + 1);
                }
                
                if (tokenCount >= 5) {
                    int id = stoi(tokens[0]);
                    string name = tokens[1];
                    string pickup = tokens[2];
                    string dropoff = tokens[3];
                    bool cardActive = (tokens[4] == "1");
                    string otp = tokens[5].substr(0, tokens[5].find('#'));
                    
                    teachers[count] = new Teacher(id, name, pickup, dropoff, otp);
                    teachers[count]->isCardActive = cardActive;
                    count++;
                }
            }
            
            inFile.close();
            cout << count << " teacher records loaded from file.\n";
        } catch (const FileOpenException& e) {
            cout << e.what() << endl;
        } catch (const MemoryAllocationException& e) {
            cout << e.what() << endl;
        }
    }
};

class Staff : public TransportUser {
    string staffID;

public:
    Staff(int id, string n, string pick, string drop, string sID = "STAFF123")
        : TransportUser(id, n, pick, drop), staffID(sID) {}

    void payFees() override {
        isCardActive = true;
        cout << name << " (Staff) paid transport fees successfully.\n";
    }

    void login() override {
        string inputID;
        cout << "Enter Staff ID for " << name << ": ";
        cin >> inputID;
        
        if (inputID == staffID) {
            cout << "Login successful for staff member " << name << ".\n";
        } else {
            cout << "Login failed. Incorrect Staff ID.\n";
        }
    }

    string getUserType() const override {
        return "Staff";
    }
    
    void saveToFile() override {
        try {
            ofstream outFile("staff.txt", ios::app);
            if (!outFile) {
                throw FileOpenException();
            }
            
            outFile << userID << "|" << name << "|" << pickupStop << "|" << dropOffStop << "|" 
                   << (isCardActive ? "1" : "0") << "|" << staffID << "#\n";
            
            outFile.close();
            cout << "Staff data saved to file.\n";
        } catch (const FileOpenException& e) {
            cout << e.what() << endl;
        }
    }
    
    static void loadFromFile(Staff**& staff, int& count) {
        try {
            ifstream inFile("staff.txt");
            if (!inFile) {
                throw FileOpenException();
            }
            
            staff = new (nothrow) Staff*[10];
            if (!staff) {
                throw MemoryAllocationException();
            }
            
            count = 0;
            string line;
            
            while (getline(inFile, line) && count < 10) {
                if (line.empty()) continue;
                
                size_t pos = 0;
                string token;
                string tokens[6];
                int tokenCount = 0;
                
                while ((pos = line.find('|')) != string::npos && tokenCount < 6) {
                    token = line.substr(0, pos);
                    tokens[tokenCount++] = token;
                    line.erase(0, pos + 1);
                }
                
                if (tokenCount >= 5) {
                    int id = stoi(tokens[0]);
                    string name = tokens[1];
                    string pickup = tokens[2];
                    string dropoff = tokens[3];
                    bool cardActive = (tokens[4] == "1");
                    string staffID = tokens[5].substr(0, tokens[5].find('#'));
                    
                    staff[count] = new Staff(id, name, pickup, dropoff, staffID);
                    staff[count]->isCardActive = cardActive;
                    count++;
                }
            }
            
            inFile.close();
            cout << count << " staff records loaded from file.\n";
        } catch (const FileOpenException& e) {
            cout << e.what() << endl;
        } catch (const MemoryAllocationException& e) {
            cout << e.what() << endl;
        }
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
        try {
            routeStops = new string[maxStops];
            if (!routeStops) {
                throw MemoryAllocationException();
            }
        } catch (const bad_alloc& e) {
            throw MemoryAllocationException();
        }
    }

    ~Bus() {
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

    bool operator==(const Bus &other) const {
        if (currentStops != other.currentStops) return false;
        for (int i = 0; i < currentStops; i++) {
            if (routeStops[i] != other.routeStops[i]) return false;
        }
        return true;
    }

    void displayRoute() const {
        cout << "\nBus: " << busRouteName << " (ID: " << busID << ")\nStops: ";
        for (int i = 0; i < currentStops; i++)
            cout << routeStops[i] << " -> ";
        cout << "FAST\n";
    }

    string getID() const { return busID; }
    string getRouteName() const { return busRouteName; }
    
    void saveToFile() {
        try {
            ofstream outFile("buses.txt", ios::app);
            if (!outFile) {
                throw FileOpenException();
            }
            
            outFile << busID << "|" << busRouteName << "|" << maxStops << "|" << currentStops;
            
            for (int i = 0; i < currentStops; i++) {
                outFile << "|" << routeStops[i];
            }
            outFile << "#\n";
            
            outFile.close();
            cout << "Bus data saved to file.\n";
        } catch (const FileOpenException& e) {
            cout << e.what() << endl;
        }
    }
    
    static void loadFromFile(Bus**& buses, int& count) {
        try {
            ifstream inFile("buses.txt");
            if (!inFile) {
                throw FileOpenException();
            }
            
            buses = new (nothrow) Bus*[10];
            if (!buses) {
                throw MemoryAllocationException();
            }
            
            count = 0;
            string line;
            
            while (getline(inFile, line) && count < 10) {
                if (line.empty()) continue;
                
                size_t pos = 0;
                string token;
                string tokens[20]; // Assuming maximum 16 stops (4 base fields + 16 stops)
                int tokenCount = 0;
                
                while ((pos = line.find('|')) != string::npos && tokenCount < 20) {
                    token = line.substr(0, pos);
                    tokens[tokenCount++] = token;
                    line.erase(0, pos + 1);
                }
                
                if (!line.empty()) {
                    size_t hashPos = line.find('#');
                    if (hashPos != string::npos) {
                        tokens[tokenCount++] = line.substr(0, hashPos);
                    } else {
                        tokens[tokenCount++] = line;
                    }
                }
                
                if (tokenCount >= 4) {
                    string busID = tokens[0];
                    string busName = tokens[1];
                    int maxStops = stoi(tokens[2]);
                    int currentStops = stoi(tokens[3]);
                    
                    buses[count] = new Bus(busID, busName, maxStops);
                    
                    for (int i = 0; i < currentStops && i + 4 < tokenCount; i++) {
                        buses[count]->addStop(tokens[i + 4]);
                    }
                    
                    count++;
                }
            }
            
            inFile.close();
            cout << count << " bus records loaded from file.\n";
        } catch (const FileOpenException& e) {
            cout << e.what() << endl;
        } catch (const MemoryAllocationException& e) {
            cout << e.what() << endl;
        }
    }
};

template <class T>
class UserStats {
private:
    T totalUsers;
    T activeUsers;
    string userType;

public:
    UserStats(T total, T active, string type) 
        : totalUsers(total), activeUsers(active), userType(type) {}
    
    void displayStats() {
        cout << "\nStatistics for " << userType << ":\n";
        cout << "Total users: " << totalUsers << endl;
        cout << "Active users: " << activeUsers << endl;
        cout << "Inactive users: " << (totalUsers - activeUsers) << endl;
    }
    
    T getTotal() { return totalUsers; }
    T getActive() { return activeUsers; }
};

class TransportSystem {
    TransportUser** users;
    int userCount;
    Bus** buses;
    int busCount;
    static int totalUsers;

public:
    TransportSystem(int maxUsers, int maxBuses) {
        try {
            users = new TransportUser*[maxUsers];
            buses = new Bus*[maxBuses];
            if (!users || !buses) {
                throw MemoryAllocationException();
            }
            userCount = 0;
            busCount = 0;
            
            loadDataFromFiles();
        } catch (const bad_alloc& e) {
            throw MemoryAllocationException();
        }
    }

    ~TransportSystem() {
        saveAllData();
        
        for (int i = 0; i < userCount; i++) 
            delete users[i];
        delete[] users;

        for (int i = 0; i < busCount; i++) 
            delete buses[i];
        delete[] buses;
    }
    
    void loadDataFromFiles() {
        Bus::loadFromFile(buses, busCount);
        
        Student** students = nullptr;
        Teacher** teachers = nullptr;
        Staff** staffMembers = nullptr;
        int studentCount = 0, teacherCount = 0, staffCount = 0;
        
        Student::loadFromFile(students, studentCount);
        Teacher::loadFromFile(teachers, teacherCount);
        Staff::loadFromFile(staffMembers, staffCount);
        
        for (int i = 0; i < studentCount; i++) {
            users[userCount++] = students[i];
            totalUsers++;
        }
        
        for (int i = 0; i < teacherCount; i++) {
            users[userCount++] = teachers[i];
            totalUsers++;
        }
        
        for (int i = 0; i < staffCount; i++) {
            users[userCount++] = staffMembers[i];
            totalUsers++;
        }
        
        delete[] students;
        delete[] teachers;
        delete[] staffMembers;
    }
    
    void saveAllData() {
        cout << "\nSaving all data before exit...\n";
        
        ofstream clearStudents("students.txt", ios::trunc);
        clearStudents.close();
        
        ofstream clearTeachers("teachers.txt", ios::trunc);
        clearTeachers.close();
        
        ofstream clearStaff("staff.txt", ios::trunc);
        clearStaff.close();
        
        ofstream clearBuses("buses.txt", ios::trunc);
        clearBuses.close();
        
        for (int i = 0; i < userCount; i++) {
            users[i]->saveToFile();
        }
        
        for (int i = 0; i < busCount; i++) {
            buses[i]->saveToFile();
        }
    }

    void registerUser(int id, string name, string pick, string drop, string type) {
        try {
            if (type == "student") {
                users[userCount++] = new Student(id, name, pick, drop);
            } else if (type == "teacher") {
                users[userCount++] = new Teacher(id, name, pick, drop);
            } else if (type == "staff") {
                users[userCount++] = new Staff(id, name, pick, drop);
            }
            
            if (!users[userCount-1]) {
                throw MemoryAllocationException();
            }
            
            totalUsers++;
            cout << name << " registered successfully for transport!\n";
            
            users[userCount-1]->saveToFile();
        } catch (const bad_alloc& e) {
            throw MemoryAllocationException();
        }
    }

    void addBus(string id, string name, int maxStops) {
        try {
            buses[busCount] = new Bus(id, name, maxStops);
            if (!buses[busCount]) {
                throw MemoryAllocationException();
            }
            busCount++;
            cout << "Bus " << name << " added successfully!\n";
            
            buses[busCount-1]->saveToFile();
        } catch (const bad_alloc& e) {
            throw MemoryAllocationException();
        }
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
        
        selectedBus->saveToFile();
    }

    void displayAllBuses() const {
        for (int i = 0; i < busCount; i++)
            buses[i]->displayRoute();
    }

    TransportUser* getUser(int ID) {
        if (ID >= 0 && ID < userCount) {
            return users[ID];
        } else {
            cout << "Invalid user IDq.\n";
            return nullptr;
        }
    }
    
    void loginUser(int userID) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getID() == userID) {
                users[i]->login();
                return;
            }
        }
        cout << "User ID not found!\n";
    }
    
    template <typename T>
    void generateStats() {
        int total = 0;
        int active = 0;
        string type = "";
        
        for (int i = 0; i < userCount; i++) {
            T* user = dynamic_cast<T*>(users[i]);
            if (user) {
                type = user->getUserType();
                total++;
                if (user->getCardStatus()) {
                    active++;
                }
            }
        }
        
        UserStats<int> stats(total, active, type);
        stats.displayStats();
    }

    static int getTotalUsers() {
        return totalUsers;
    }
};

int TransportSystem::totalUsers = 0;

int main() {
    cout << "Zuniarh Aziz Shaikh 24k-0986\n";
    cout << "FAST Transport System\n";
    cout << "=====================\n\n";
    
    try {
        TransportSystem transport(10, 5);
        
        int choice;
        do {
            cout << "\n=== MAIN MENU ===\n";
            cout << "1. Register New User\n";
            cout << "2. Add New Bus\n";
            cout << "3. Define Bus Route\n";
            cout << "4. Display All Buses\n";
            cout << "5. Update User Stop\n";
            cout << "6. Record Student Attendance\n";
            cout << "7. Pay Transport Fees\n";
            cout << "8. Login User\n";
            cout << "9. Generate Statistics\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch(choice) {
                case 1: {
                    int id;
                    string name, pickup, dropoff, type;
                    cout << "\nEnter User ID: ";
                    cin >> id;
                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Pickup Stop: ";
                    getline(cin, pickup);
                    cout << "Enter Drop-off Stop: ";
                    getline(cin, dropoff);
                    cout << "Enter User Type (student/teacher/staff): ";
                    cin >> type;
                    
                    transport.registerUser(id, name, pickup, dropoff, type);
                    break;
                }
                case 2: {
                    string id, name;
                    int maxStops;
                    cout << "\nEnter Bus ID: ";
                    cin >> id;
                    cout << "Enter Bus Route Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Maximum Stops: ";
                    cin >> maxStops;
                    
                    transport.addBus(id, name, maxStops);
                    break;
                }
                case 3:
                    transport.defineRoute();
                    break;
                case 4:
                    transport.displayAllBuses();
                    break;
                case 5: {
                    int userID;
                    string newStop;
                    char stopType;
                    
                    cout << "\nEnter User ID: ";
                    cin >> userID;
                    
                    TransportUser* user = transport.getUser(userID);
                    if (!user) {
                        cout << "Invalid user ID!\n";
                        break;
                    }
                    
                    cout << "Update (P)ickup or (D)rop-off stop? ";
                    cin >> stopType;
                    cout << "Enter new stop name: ";
                    cin.ignore();
                    getline(cin, newStop);
                    
                    if (toupper(stopType) == 'P') {
                        user->updatePickupStop(newStop);
                    } else if (toupper(stopType) == 'D') {
                        user->updateDropOffStop(newStop);
                    } else {
                        cout << "Invalid stop type selection!\n";
                    }
                    break;
                }
                case 6: {
                    int userID, day;
                    cout << "\nEnter Student ID: ";
                    cin >> userID;
                    
                    Student* student = dynamic_cast<Student*>(transport.getUser(userID));
                    if (!student) {
                        cout << "Invalid student ID or user is not a student!\n";
                        break;
                    }
                    
                    cout << "Enter Day (1-31): ";
                    cin >> day;
                    student->recordAttendance(day);
                    student->displayAttendance();
                    break;
                }
                case 7: {
                    int userID;
                    cout << "\nEnter User ID: ";
                    cin >> userID;
                    
                    TransportUser* user = transport.getUser(userID);
                    if (user) {
                        user->payFees();
                    } else {
                        cout << "Invalid user ID!\n";
                    }
                    break;
                }
                case 8: {
                    int userID;
                    cout << "\nEnter User ID: ";
                    cin >> userID;
                    transport.loginUser(userID);
                    break;
                }
                case 9: {
                    int statType;
                    cout << "\nGenerate Statistics for:\n";
                    cout << "1. Students\n";
                    cout << "2. Teachers\n";
                    cout << "3. Staff\n";
                    cout << "Enter choice: ";
                    cin >> statType;
                    
                    switch(statType) {
                        case 1:
                            transport.generateStats<Student>();
                            break;
                        case 2:
                            transport.generateStats<Teacher>();
                            break;
                        case 3:
                            transport.generateStats<Staff>();
                            break;
                        default:
                            cout << "Invalid statistics type!\n";
                            break;
                    }
                    cout << "\nTotal Users in System: " << TransportSystem::getTotalUsers() << endl;
                    break;
                }
                case 0:
                    cout << "\nExiting FAST Transport System. Goodbye!\n";
                    break;
                default:
                    cout << "\nInvalid choice. Please try again.\n";
            }
        } while(choice != 0);
    } catch (const FileOpenException& e) {
        cout << e.what() << endl;
        cout << "Program will now exit due to file handling error.\n";
        return 1;
    } catch (const MemoryAllocationException& e) {
        cout << e.what() << endl;
        cout << "Program will now exit due to memory allocation error.\n";
        return 2;
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
        cout << "Program will now exit.\n";
        return 3;
    }
    
    return 0;
}
