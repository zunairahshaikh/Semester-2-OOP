/*Implement a restaurant ordering system that holds information about the restaurant’s menus, menu items, orders, and payments. Identify the relationship between the five entities mentioned. Keep in
mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functions to add and remove items, or display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. The order class consists of one or more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay.This is generated when the order is placed.*/

#include <iostream>
using namespace std;

class MenuItem{
        string foodName;
        float foodPrice;
    public:
        MenuItem(){
            foodName = "";
            foodPrice = 0;
        }

        MenuItem(string foodName, float foodPrice){
            this->foodName = foodName;
            this->foodPrice = foodPrice;
        }

        string getFoodName(){
            return foodName;
        }

        float getFoodPrice(){
            return foodPrice;
        }

        void setFoodName(string foodName){
            this->foodName = foodName;
        }

        void setFoodPrice(float foodPrice){
            this->foodPrice = foodPrice;
        }
};

class Menu{
        MenuItem *menuItems;
        int size;
    public:
        Menu(){
            menuItems = new MenuItem[10];
            size = 0;
        }
        void addMenuItem(MenuItem mi){
            menuItems[size++] = mi;
        }
        void removeMenuItem(string foodName){
            for(int i = 0; i < size; i++){
                if(menuItems[i].getFoodName() == foodName){
                    for(int j = i; j < size - 1; j++){
                        menuItems[j] = menuItems[j + 1];
                    }
                    size--;
                    break;
                }
            }
        }
        void displayMenu(){
            for(int i = 0; i < size; i++){
                cout << "Food Name: " << menuItems[i].getFoodName() << endl;
                cout << "Food Price: $" << menuItems[i].getFoodPrice() << endl;
            }
        }
};

class Order{
        MenuItem *menuItems;
        int size;
        float payment;
    public:
        Order(){
            menuItems = new MenuItem[10];
            size = 0;
            payment = 0;
        }
        void addMenuItem(MenuItem mi){
            menuItems[size++] = mi;
            payment += mi.getFoodPrice();
        }
        void displayOrder(){
            cout << "Order Details:\n" << endl;
            for(int i = 0; i < size; i++){
                cout << "Food Name: " << menuItems[i].getFoodName() << endl;
                cout << "Food Price: $" << menuItems[i].getFoodPrice() << endl << endl;
            }
            cout << "Payment: $" << payment << endl;
        }
};

class Payment{
        float amount;
    public:
        Payment(){
            amount = 0;
        }

        Payment(float amt) : amount(amt) {}

        float getAmount(){
            return amount;
        }

        void setAmount(float amount){
            this->amount = amount;
        }
};

class RestaurantOrderingSystem{
        Menu menu;
    public:
        RestaurantOrderingSystem(){
            menu = Menu();
        }
        void addMenuItem(MenuItem mi){
            menu.addMenuItem(mi);
        }
        void removeMenuItem(string foodName){
            menu.removeMenuItem(foodName);
        }
        void displayMenu(){
            menu.displayMenu();
        }
        void placeOrder(Order o){
            o.displayOrder();
        }
};

int main(){
    MenuItem mi1("Burger", 5.99);
    MenuItem mi2("Pizza", 7.99);
    MenuItem mi3("Pasta", 9.99);

    RestaurantOrderingSystem ros;
    ros.addMenuItem(mi1);
    ros.addMenuItem(mi2);
    ros.addMenuItem(mi3);

    ros.displayMenu();

    Order o;
    o.addMenuItem(mi1);
    o.addMenuItem(mi2);
    o.addMenuItem(mi3);

    Payment p(23.97);

    ros.placeOrder(o);

    return 0;
}