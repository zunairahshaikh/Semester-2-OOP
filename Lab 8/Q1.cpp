/*in a modern smart home, different devices such as lights, fans, air conditioners, and security systems are controlled through a central automation hub. The system must manage various electronic appliances,
allowing authorized users to monitor and control their power consumption, adjust settings, and schedule automated tasks. However, sensitive security system controls should not be accessible to regular users
and must only be accessed by authorized maintenance staff via a special diagnostic tool. The system should also be capable of calculating the power consumption of each appliance based on usage duration and
device type.
Attributes & Functionality Requirements

1. Device Management
Each device should have:
Device ID (string) – A unique identifier for each appliance.
Device Type (string) – Specifies if it is a light, fan, AC, or security system.
Power Rating (double) – Power consumption per hour in watts.
Status (bool) – Whether the device is ON or OFF.
A function void turnOn() to turn the device ON.
A function void turnOff() to turn the device OFF.
A function double calculatePowerUsage(int hours) to compute energy consumption:
Lights consume energy based on simple multiplication: powerRating * hours.
Fans have variable speed settings affecting power consumption (powerRating * hours * speedFactor).
Air Conditioners adjust power dynamically based on room temperature (powerRating * hours * (1 - (currentTemp - desiredTemp) / 100)).
Security Systems have fixed power consumption, but should include a security status check in power calculation.

2.User Management
Each user should have:
User ID (string) – A unique identifier for each person.
User Role (string) – Defines if the user is a Regular User or Maintenance Staff.
Access Level (int) – Determines whether they can view/edit security devices.
A function void viewAccessibleDevices() – Displays only the devices they are allowed to control.

3. Special Security Controls
Security system details (such as camera status and intrusion alerts) should not be accessible to regular users.
Only maintenance staff should have access through a friend function:
void accessSecurityLogs() – Allows authorized personnel to check security status.

Function Prototypes and Overriding Requirement
1. void turnOn() and void turnOff() should be present in all devices but should:
Lights & Fans: Simple ON/OFF state change.
ACs: Also adjust the temperature settings.
Security Systems: Require authorization check before turning OFF.

2. double calculatePowerUsage(int hours) should be overridden:
Lights: powerRating * hours.
Fans: powerRating * hours * speedFactor.
ACs: powerRating * hours * (1 - (currentTemp - desiredTemp) / 100).
Security Systems: Fixed consumption + log security status.

3. Friend Function: void accessSecurityLogs()
Allows only maintenance staff to view logs and system diagnostics.
Regular users cannot see logs even if they try.

4. Friend Class: MaintenanceTool
Friend of Security Systems, allowing maintenance personnel to reset security.*/

#include <iostream>
using namespace std;

class DeviceManagement{
    protected:
        string deviceID;
        string deviceType;
        double powerRating;
        bool status;
    public:
        DeviceManagement(string id, string dt, double pr, bool s) : deviceID(id), deviceType(dt), powerRating(pr), status(s){}

        virtual void turnOn(){
            status = true;
        }
        virtual void turnOff(){
            status = false;
        }
        virtual double calculatePowerUsage(int hours) = 0;

        string getDeviceID() const { return deviceID; }
        string getDeviceType() const { return deviceType; }
        bool getStatus() const { return status; }
};

class Lights : public DeviceManagement{
    public:
        Lights(string id, string t, double pr, bool s) : DeviceManagement(id, t, pr, s){}

        double calculatePowerUsage(int hours) override {
            return powerRating * hours;
        }   

        void turnOn() override{
            status = true;
        }

        void turnOff() override{
            status = false;
        }
};

class Fans : public DeviceManagement{
    double speedFactor;
    public:
        Fans(string id, string t, double pr, bool s, double sf) : DeviceManagement(id, t, pr, s), speedFactor(sf){}

        double calculatePowerUsage(int hours) override {
            return powerRating * hours * speedFactor;
        }

        void turnOn() override{
            status = true;
        }

        void turnOff() override{
            status = false;
        }
};

class AC : public DeviceManagement{
    double currentTemp, desiredTmp;

    public:
        AC(string id, string t, double pr, bool s, double ct, double dt) : DeviceManagement(id, t, pr, s), currentTemp(ct), desiredTmp(dt){}

        double calculatePowerUsage(int hours) override{
            return powerRating * hours * (1 - (currentTemp - desiredTmp) / 100);
        }

        void turnOn() override {
            if(desiredTmp < currentTemp){
                currentTemp = desiredTmp;
            }
            status = true;
        }

        void turnOff() override {
            if(currentTemp > desiredTmp){
                currentTemp = desiredTmp;
            }
            status = false;
        }
};

class SecuritySystem : public DeviceManagement{
    string password;
    public:
        SecuritySystem(string id, string t, double pr, bool s, string pw) : DeviceManagement(id, t, pr, s), password(pw){}

        double calculatePowerUsage(int hours) override {
            if(status){
                return 100 * hours; // Fixed consumption of 100 watts per hour
            }
            return 0;
        }

        void turnOff() override {
             string p;
            cout << "Enter password to turn off security system: ";
            cin >> p;
            if(p == password){
                status = false;
            }
        }

        friend void accessSecurityLogs(SecuritySystem &ss);
        friend class MaintenanceTool;
};

class UserManagement{
    protected:
        string userID;
        string userRole;
        int accessLevel;
    public:
        UserManagement(string id, string ur, int al) : userID(id), userRole(ur), accessLevel(al){}

        virtual void viewAccessibleDevices() = 0;

        string getUserID() const { return userID; }
        string getUserRole() const { return userRole; }
        int getAccessLevel() const { return accessLevel; }
};

class RegularUser : public UserManagement{
    public:
        RegularUser(string id, string ur, int al) : UserManagement(id, ur, al){}

        void viewAccessibleDevices() override {
            cout << "Regular User can view Lights, Fans, and ACs." << endl;
        }
};

class MaintenanceStaff : public UserManagement{
    public:
        MaintenanceStaff(string id, string ur, int al) : UserManagement(id, ur, al){}

        void viewAccessibleDevices() override {
            cout << "Maintenance Staff can view all devices including Security Systems." << endl;
        }
};

class MaintenanceTool{
    public:
        void resetSecurity(SecuritySystem &ss){
            ss.status = false;
            cout << "Security System Reset by Maintenance Tool." << endl;
        }

        void accessSecurityLogs(SecuritySystem &ss){
            cout << "Security System Logs Accessed by Maintenance Tool." << endl;
        }
};

void accessSecurityLogs(SecuritySystem &ss){
    cout << "Accessing Security Logs..." << endl;
}

int main() {
    Lights light1("L1", "Light", 50, false);
    Fans fan1("F1", "Fan", 75, false, 1.5);
    AC ac1("A1", "AC", 1000, false, 30, 25);
    SecuritySystem ss1("S1", "SecuritySystem", 100, true, "admin123");


    RegularUser regularUser("U1", "Regular User", 1);       //regular users have access level 1
    MaintenanceStaff maintenanceStaff("U2", "Maintenance Staff", 2);        //staff have access level 2

    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    ss1.turnOff(); 

    cout << "Light Power Usage: " << light1.calculatePowerUsage(5) << " watts" << endl;
    cout << "Fan Power Usage: " << fan1.calculatePowerUsage(5) << " watts" << endl;
    cout << "AC Power Usage: " << ac1.calculatePowerUsage(5) << " watts" << endl;
    cout << "Security System Power Usage: " << ss1.calculatePowerUsage(5) << " watts" << endl;

    regularUser.viewAccessibleDevices();
    maintenanceStaff.viewAccessibleDevices();

    MaintenanceTool tool;
    tool.resetSecurity(ss1);
    tool.accessSecurityLogs(ss1);

    accessSecurityLogs(ss1);

    return 0;
}
