/*You are building a car rental system. Create a class `Car` to manage cars available for rent.
Requirements:
1. Attributes:
 `carID` (int)
 `model` (string)
 `year` (int)
 `isRented` (bool)
2. Define a default constructor that initializes `isRented` to `false`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:

 `rentCar()`: Marks the car as rented.
 `returnCar()`: Marks the car as available.
 `isVintage()`: Returns `true` if the car's year is before 2000.

5. Create a few `Car` objects and test the methods.*/

#include <iostream>
using namespace std;

class Car{
    int carID;
    string model;
    int year;
    bool isRented;

    public:
        Car(): carID(0), model(""), year(0), isRented(false){}
        Car(int id, string m, int y, bool ir) : carID(id), model(m), year(y), isRented(ir){}

        void rentCar(){
            if(!isRented){
                isRented = true;
                cout << "Car rented successfully" << endl;
            }
            else{
                cout << "Car already rented" << endl;
            }
        }

        bool returnCar(){
            if(isRented){
                isRented = false;
                cout << "Car returned successfully" << endl;
            }
            else{
                cout << "Error: car  had not been rented" << endl;
            }
        }

        bool isVintage() const {
            if(year < 2000)
                return true;
            else
                return false;
        }
};

int main() {
    Car car1(1, "Toyota Corolla", 1995, true);
    Car car2(2, "Honda Civic", 2015, true);
    Car car3(3, "Ford Mustang", 1965, true);


    car1.rentCar();
    car2.rentCar();
    car3.rentCar();

    cout << endl;

    car1.returnCar();
    car2.returnCar();
    car3.returnCar();

    cout << "Is car1 vintage? " << (car1.isVintage() ? "Yes" : "No") << endl;
    cout << "Is car2 vintage? " << (car2.isVintage() ? "Yes" : "No") << endl;
    cout << "Is car3 vintage? " << (car3.isVintage() ? "Yes" : "No") << endl;

    return 0;
}