#include <iostream>
#include <string>
using namespace std;

struct Product {
    int productID;
    string name;
    float price;
    int quantity;
};

void addProduct(Product products[], int &currentProductCount) {
    if (currentProductCount < 10) { 
        cout << "Enter product ID: ";
        cin >> products[currentProductCount].productID;

        cin.ignore();

        cout << "Enter product name: ";
        getline(cin, products[currentProductCount].name);

        cout << "Enter product price: $";
        cin >> products[currentProductCount].price;

        cout << "Enter quantity in stock: ";
        cin >> products[currentProductCount].quantity;

        currentProductCount++;
    } else {
        cout << "Inventory full, can't add more products." << endl;
    }
}

void displayProduct(const Product products[], int currentProductCount, int productID) {
    bool found = false;
    for (int i = 0; i < currentProductCount; ++i) {
        if (products[i].productID == productID) {
            cout << "Product ID: " << products[i].productID << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Price: $" << products[i].price << endl;
            cout << "Quantity in Stock: " << products[i].quantity << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product not found!" << endl;
    }
}

void updateProduct(Product products[], int currentProductCount, int productID) {
    bool found = false;
    for (int i = 0; i < currentProductCount; ++i) {
        if (products[i].productID == productID) {
            cout << "Enter new product name: ";
            cin.ignore();
            getline(cin, products[i].name);

            cout << "Enter new product price: $";
            cin >> products[i].price;

            cout << "Enter new quantity in stock: ";
            cin >> products[i].quantity;

            cout << "Product updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product not found!" << endl;
    }
}

void removeProduct(Product products[], int &currentProductCount, int productID) {
    bool found = false;
    for (int i = 0; i < currentProductCount; ++i) {
        if (products[i].productID == productID) {
            for (int j = i; j < currentProductCount - 1; ++j) {
                products[j] = products[j + 1];
            }
            currentProductCount--;
            cout << "Product removed successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product not found!" << endl;
    }
}

int main() {
    Product products[10];  // Array to hold up to 10 products
    int currentProductCount = 0;
    int choice;
    int productID;

    while (true) {
        cout << "\nProduct Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Display Product\n";
        cout << "3. Update Product\n";
        cout << "4. Remove Product\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(products, currentProductCount);
                break;
            case 2:
                cout << "Enter product ID to display: ";
                cin >> productID;
                displayProduct(products, currentProductCount, productID);
                break;
            case 3:
                cout << "Enter product ID to update: ";
                cin >> productID;
                updateProduct(products, currentProductCount, productID);
                break;
            case 4:
                cout << "Enter product ID to remove: ";
                cin >> productID;
                removeProduct(products, currentProductCount, productID);
                break;
            case 5:
                cout << "Exiting system..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
