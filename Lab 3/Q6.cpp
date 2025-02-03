/*Create a class called Smartphone with the following attributes:
 Company
 Model
 Display Resolution
 RAM
 ROM
 Storage

Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
For example:
1. Make a phone call
2. Send a message
3. Connect to the wifi
4. Browse the internet

Create different smartphone objects. Set their attributes using the setter functions and display their attributes after
using the getter functions to fetch the attributes.*/

#include <iostream>
using namespace std;

class Smartphone{
    string company;
    string model;
    string displayRes;
    int RAM;
    int ROM;
    int storage;

    public:
     string getCompany(){
        return company;
    }

    string getModel(){
        return model;
    }

    string getDisplayResolution(){
        return displayRes;
    }

    int getRAM(){
        return RAM;
    }

    int getROM(){
        return ROM;
    }

    int getStorage(){
        return storage;
    }

    void setCompany(string comp){
        company = comp;
    }

    void setModel(string m){
        model = m;
    }

    void setDisplayResolution(string dr){
        displayRes = dr;
    }

    void setRAM(int ram){
        RAM = ram;
    }

    void setROM(int rom){
        ROM = rom;
    }

    void setStorage(int sto){
        storage = sto;
    }

     void makePhoneCall(const string& number) {
        cout << "Making a call to " << number << "...\n";
    }

    void sendMessage(const string& number, const string& message) {
        cout << "Sending message to " << number << ": " << message << endl;
    }

    void connectToWifi(const string& wifiName) {
        cout << "Connecting to Wi-Fi network: " << wifiName << "...\n";
    }

    void browseInternet(const string& website) {
        cout << "Browsing website: " << website << "...\n";
    }

};

int main() {
    Smartphone phone1;

    phone1.setCompany("Apple");
    phone1.setModel("iPhone 13");
    phone1.setDisplayResolution("2532 x 1170");
    phone1.setRAM(4);
    phone1.setROM(128);
    phone1.setStorage(256);

    cout << "Smartphone Details:\n";
    cout << "Company: " << phone1.getCompany() << endl;
    cout << "Model: " << phone1.getModel() << endl;
    cout << "Display Resolution: " << phone1.getDisplayResolution() << endl;
    cout << "RAM: " << phone1.getRAM() << " GB\n";
    cout << "ROM: " << phone1.getROM() << " GB\n";
    cout << "Storage: " << phone1.getStorage() << " GB\n";

    phone1.makePhoneCall("123-456-7890");
    phone1.sendMessage("123-456-7890", "Hello! How are you?");
    phone1.connectToWifi("Home_Wifi");
    phone1.browseInternet("www.google.com");
}