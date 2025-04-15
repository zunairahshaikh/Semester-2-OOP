/*Problem: A homeowner wants to integrate smart lights and thermostats from different
brands into a single app. The system must provide a unified way to turn devices on/off,
adjust settings, and check statuses without requiring users to interact with brand-specific
interfaces. Future devices (e.g., smart locks) should integrate without altering the core
system.
Classes and Structure:

• Abstract Class SmartDevice:
o Member Functions:
▪ turnOn(): Pure virtual function to activate the device.
▪ turnOff(): Pure virtual function to deactivate the device.
▪ getStatus(): Pure virtual function to return the device’s current state.

• Derived Class LightBulb:
o Data Members:
▪ isOn (bool): Tracks if the light is on/off.
▪ brightness (int): Stores brightness level (0-100%).
o Implements turnOn(), turnOff(), and getStatus() for light control.

• Derived Class Thermostat:
o Data Members:
▪ isOn (bool): Tracks if the thermostat is active.
▪ temperature (double): Stores the current temperature setting.
o Implements turnOn(), turnOff(), and getStatus() for temperature control.

Flow:
• Create LightBulb and Thermostat objects.
• Turn devices on/off and display their statuses.
Device States: For LightBulb and Thermostat, the isOn flag is fine, but the brightness of the light and the temperature of the thermostat are not used in any status message. It would make more sense to return the actual brightness or temperature as part of the status.

Initialization: The isOn flag is uninitialized in both LightBulb and Thermostat. You should initialize it to false by default to ensure proper behavior.

Output Format: The main function prints whether the devices are ON or OFF, but it doesn't print out the brightness for the light or the temperature for the thermostat.*/

#include <iostream>
#include <string>
using namespace std;

class SmartDevice
{
public:
    SmartDevice() {}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
};

class LightBulb : public SmartDevice
{
protected:
    bool isOn;
    int brightness;

public:
    LightBulb(int b) : brightness(b), isOn(false), SmartDevice() {}
    void turnOn() override
    {
        isOn = true;
    }
    void turnOff() override
    {
        isOn = false;
    }
    void getStatus() override
    {
        cout << "Light is " << (isOn ? "ON" : "OFF") << ", Brightness: " << brightness << "%" << endl;
    }
};

class Thermostat : public SmartDevice
{
protected:
    bool isOn;
    double temperature;

public:
    Thermostat(int t) : temperature(t), isOn(true), SmartDevice() {}
    void turnOn() override
    {
        isOn = true;
    }
    void turnOff() override
    {
        isOn = false;
    }
    void getStatus() override
    {
        cout << "Thermostat is " << (isOn ? "ON" : "OFF") << ", Temperature: " << temperature << "°C" << endl;
    }
};

int main()
{
    LightBulb l(75);
    Thermostat t(22.5);

    l.turnOn();
    t.turnOn();

    cout << "Device Statuses:" << endl;
    l.getStatus();
    t.getStatus();

    l.turnOff();
    t.turnOff();

    cout << "\nDevice Statuses After Turn Off:" << endl;
    l.getStatus();
    t.getStatus();
    return 0;
}
