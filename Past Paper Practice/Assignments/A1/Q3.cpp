/*Imagine you are developing a vehicle rental application that allows users to register, update their details, and rent vehicles based on certain eligibility criteria. The rental system must consider
different types of users and vehicles. Users will provide their personal information, including details such as their age, contact number, and license type, while the system will offer a range of
vehicles with varying rental conditions. The application needs to handle user registration, allowing them to update their details as needed, and rent vehicles by checking eligibility based on their license type.
Once a user is registered, they can view a list of available vehicles and choose one to rent. The system should check the user’s eligibility to rent a specific vehicle based on their license type, 
and it should ensure users can only rent vehicles they are qualified for. You are asked to create a vehicle rental system where users can register with their details, update their personal information,
and rent vehicles. The vehicles will have different types and rental conditions, and users will be restricted from renting vehicles they are not qualified for.
The system will manage the following:
1. Users can register and provide information such as:
o Age
o License type (e.g., Learner, Intermediate, Full)
o Contact information
o User ID
2. Once registered, users can update their details, including their name, age, and license type, which will be stored in the system.
3. The system will display a list of available vehicles, with attributes such as:
o Model
o Rental price per day
o Eligibility for different license types (e.g., Learners can only rent certain vehicles
4. The system will check if the user meets the requirements to rent a specific vehicle based on their license type.
5. If the user is eligible for a vehicle, they can proceed with the rental; otherwise, they will be informed that they cannot rent that particular vehicle.

To store the available vehicles, a pointer array will be used. This allows for dynamic management of vehicle objects, providing flexibility for adding or removing vehicles as needed without resizing fixed arrays.
The vehicle objects should be created dynamically using pointers, and the array will store the addresses of these objects. The system will access and modify vehicle details using these pointers.
By using a pointer array, the system ensures efficient memory usage and the ability to scale the number of vehicles as needed.

Task:
• Allow the user to register with their information, including personal details and license type.
• Implement functionality for users to update their information at any time.
• Create a dynamic array of pointers for vehicles. Each pointer in the array will point to a dynamically allocated vehicle object.
• For each vehicle, specify eligibility requirements based on license type (e.g., Learners, Full license).
• Based on the user’s license type, check if they are eligible to rent a vehicle.
• Ensure that users with different license types (e.g., Learner, Intermediate, Full) have access to different vehicle options.
• If eligible, allow users to rent a vehicle, displaying the rental details and the vehicle they have selected.
• If not eligible, inform the user that they cannot rent that vehicle*/

#include <iostream>
#include <string>
using namespace std;

class User {
    int UserID;
    string name;
    int age;
    string license;
    string contact;

public:
   User(){
    UserID = 0;
    name = "";
    age = 0;
    string license = "";
    string contact = "";
   }

   ~User(){}

    void registerUser() {
        cout << "Enter User ID: ";
        cin >> UserID;
        
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: ";
        while (!(cin >> age) || age <= 0) {
            cout << "Invalid input! Enter a valid age: ";
            cin.clear();    //If the user enters invalid input (like "abc" instead of a number), cin goes into a fail state. cin.clear() resets the fail state so we can take input again.
            cin.ignore(1000, '\n');    //f invalid input is entered (like "abc"), it leaves garbage characters in the input buffer. cin.ignore(1000, '\n'); clears the leftover characters (up to 1000 characters or until a newline '\n' is found).
        }

        cout << "Enter Contact Number: ";
        cin >> contact;

        cout << "Enter License Type (L - Learner, I - Intermediate, F - Full): ";
        cin >> license;
        if (license == "l" || license == "i" || license == "f") {
            license[0] = toupper(license[0]);
        }
    }

    void updateDetails() {
        cout << "Update Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Update Age: ";
        while (!(cin >> age) || age <= 0) {
            cout << "Invalid input! Enter a valid age: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Update License Type (L - Learner, I - Intermediate, F - Full): ";
        cin >> license;
        if (license == "l" || license == "i" || license == "f") {
            license[0] = toupper(license[0]);
        }

        cout << "Update Contact Number: ";
        cin >> contact;
    }

    string getLicense(){
        return license;
    }
};

class Vehicle {
    string model;
    double price;
    string* allowedLicenses;
    int licenseCount;
public:
    Vehicle(string m, double p, string* licenses, int count) : model(m), price(p), licenseCount(count) {
        allowedLicenses = new string[licenseCount];
        for (int i = 0; i < licenseCount; i++) {
            allowedLicenses[i] = licenses[i];
        }
    }

    ~Vehicle() {
        delete[] allowedLicenses;
    }

    bool canRent(string l) {
        for (int i = 0; i < licenseCount; i++) {
            if (allowedLicenses[i] == l) return true;
        }
        return false;
    }

    string getModel(){
        return model;
    }

    double getPrice(){
        return price;
    }
};

int main() {

    cout <<"Zuniarh Aziz Shaikh 24k-0986" << endl;

    cout << endl;

    int vehicleCount = 3;
    Vehicle** vehicles = new Vehicle*[vehicleCount];

    string licenses1[] = {"F", "I"};
    vehicles[0] = new Vehicle("Toyota Corolla", 50, licenses1, 2);

    string licenses2[] = {"F"};
    vehicles[1] = new Vehicle("Honda Civic", 30, licenses2, 1);

    string licenses3[] = {"L", "I", "F"};
    vehicles[2] = new Vehicle("Suzuki Swift", 20, licenses3, 3);

    User user;
    user.registerUser();

    cout << "Available Vehicles:\n";
    for (int i = 0; i < vehicleCount; i++) {
        cout << i + 1 << ". " << vehicles[i]->getModel() << " - $" << vehicles[i]->getPrice() << " per day\n";
    }

    int choice;
    cout << "Select a vehicle to rent (Enter number): ";
    while (!(cin >> choice) || choice < 1 || choice > vehicleCount) {
        cout << "Invalid choice! Please enter a number between 1 and " << vehicleCount << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    if (vehicles[choice - 1]->canRent(user.getLicense())) {
        cout << "Rental successful! You have rented " << vehicles[choice - 1]->getModel()<< " for $" << vehicles[choice - 1]->getPrice() << " per day.\n";
    }
    else {
        cout << "Sorry, you are not eligible to rent this vehicle.\n";
    }

    for (int i = 0; i < vehicleCount; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;

    return 0;
}
