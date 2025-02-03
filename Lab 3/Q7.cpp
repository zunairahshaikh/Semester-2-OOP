/*Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of
strings), and another list with the prices of the items (hint: array of prices).
Create a menu-driven program to:
1. Allow the shop owner to add the items and their prices.
2. Fetch the list of items
3. Edit the prices of the items
4. View all the items and their prices
Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the
shopkeeper inputs the items and their amounts bought by the customer.*/

#include <iostream>
#include <string>
using namespace std;

class StationaryShop {
  string items[100];
  double prices[100];
  int itemCount;

public:
    StationaryShop() : itemCount(0) {}

    void addItem(const string& item, double price) {
        items[itemCount] = item;
        prices[itemCount] = price;
        itemCount++;
    }

    void editPrice(int index, double newPrice) {
        if (index >= 0 && index < itemCount) {
            prices[index] = newPrice;
        }
    }

    void showItems() const {
        for (int i = 0; i < itemCount; ++i) {
            cout << i + 1 << ". " << items[i] << " - $" << prices[i] << endl;
        }
    }

    void generateReceipt(int itemIndexes[], int quantities[], int numItems) {
        double total = 0.0;
        cout << "\nReceipt\n";
        cout << "----------------------------------\n";
        for (int i = 0; i < numItems; ++i) {
            int index = itemIndexes[i] - 1;
            double price = prices[index];
            int quantity = quantities[i];
            double itemTotal = price * quantity;
            cout << items[index] << " x " << quantity << " - $" << itemTotal << endl;
            total += itemTotal;
        }
        cout << "----------------------------------\n";
        cout << "Total: $" << total << endl;
    }
};

int main() {
    StationaryShop shop;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add an item\n";
        cout << "2. Edit item price\n";
        cout << "3. Show items\n";
        cout << "4. Generate receipt\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            double price;
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, item);
            cout << "Enter item price: $";
            cin >> price;
            shop.addItem(item, price);
        } 
        else if (choice == 2) {
            int index;
            double newPrice;
            cout << "Enter item index to edit: ";
            cin >> index;
            cout << "Enter new price: $";
            cin >> newPrice;
            shop.editPrice(index - 1, newPrice);
        } 
        else if (choice == 3) {
            shop.showItems();
        } 
        else if (choice == 4) {
            shop.showItems();
            int itemIndexes[100], quantities[100];
            int numItems;
            cout << "Enter the number of items bought: ";
            cin >> numItems;
            for (int i = 0; i < numItems; ++i) {
                cout << "Enter item index and quantity: ";
                cin >> itemIndexes[i] >> quantities[i];
            }
            shop.generateReceipt(itemIndexes, quantities, numItems);
        }
    } while (choice != 5);

}
