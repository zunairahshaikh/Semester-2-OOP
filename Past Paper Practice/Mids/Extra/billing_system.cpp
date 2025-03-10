/*A power distribution company wants to automate its billing system. The company supplies electricity to residential, commercial, and industrial consumers.
The billing system should calculate the monthly electricity bill based on different tariff rates for each consumer type.

Problem Statement:
The company has consumers who are categorized as follows:
1. Residential Consumers: Charged at $0.12 per unit.
2. Commercial Consumers: Charged at $0.20 per unit.
3. Industrial Consumers: Charged at $0.30 per unit.
Additionally:
 If a residential consumer consumes more than 500 units, a surcharge of 5% is applied.
 If a commercial consumer consumes more than 1000 units, a surcharge of 10% is applied.
 If an industrial consumer consumes more than 2000 units, a surcharge of 15% is applied.

The system should allow:
 Registering a consumer (with details like consumer name, ID, and units consumed).
 Displaying the total bill based on category-wise calculations.

Implementation Requirements:
 Create a base class Consumer with attributes like name, consumerID, and unitsConsumed.
 Create derived classes ResidentialConsumer, CommercialConsumer, and IndustrialConsumer which inherit from Consumer.
 Each derived class should have a method to calculate the bill based on the unit consumption and applicable surcharge.
 Create a main() function to allow user input and display the calculated bill*/

#include <iostream>
using namespace std;

class Consumer{
    protected:
        string name, consumerID;
        int unitsConsumed;

    public:
        Consumer() {
            name = "";
            consumerID = "";
            unitsConsumed = 0;
        }

        void Register(string id, string Cname){
            name = Cname;
            consumerID = id;
            cout << "Consumer registered successfully" << endl;
        }
};

class ResidentialConsumer : public Consumer{
    public:
        void displayBill(int units){
            double bill = units * 0.12;

            if(units > 500){
                bill += (bill*0.05);
            }

            cout << "\nBill Details\n";
            cout << "ID: " << consumerID << endl << "Units consumed: " << units << endl << "Total Bill: $" << bill << endl;
            cout << endl;
        }
};

class CommercialConsumer : public Consumer{
    public:
        void displayBill(int units){
            double bill = units * 0.2;

            if(units > 1000){
                bill += (bill*0.1);
            }

            cout << "\nBill Details\n";
            cout << "ID: " << consumerID << endl << "Units consumed: " << units << endl << "Total Bill: $" << bill << endl;
            cout << endl;
        }
};

class IndustrialConsumer : public Consumer{
    public:
        void displayBill(int units){
            double bill = units * 0.30;

            if(units > 2000){
                bill += (bill*0.15);
            }

            cout << "\nBill Details\n";
            cout << "ID: " << consumerID << endl << "Units consumed: " << units << endl << "Total Bill: $" << bill << endl;
            cout << endl;
        }
};

int main(){
    ResidentialConsumer house;
    CommercialConsumer mall;
    IndustrialConsumer factory;

    house.Register("RC1001", "AA");
    house.displayBill(60);

    mall.Register("CC1001", "Moooo");
    mall.displayBill(5842);

}
