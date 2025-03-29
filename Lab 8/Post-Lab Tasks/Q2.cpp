/*An E-commerce website provides multiple ways to calculate the total price of a customer's order based on the type of product.
There are two main product categories:
1. Electronics: Tax rate 15%
2. Clothing: Tax rate 5%

The website supports different discount methods based on the type of user (Regular or Premium). Additionally, the website allows combining multiple carts and applying arithmetic
operations to calculate total prices dynamically.

Task Requirements:
1. Create a base class Product with attributes like productID, price, and a virtual function calculatePrice().

2. Implement two derived classes:
o Electronics (Applies 15% tax)
o Clothing (Applies 5% tax)

3. Overload the applyDiscount method to handle different discount types:
o Percentage discount (e.g., 10% off)
o Fixed discount (e.g., $20 off)
o Buy One Get One Free

4. Override the calculatePrice method to apply category-specific tax rates.

5. Implement operator overloading for the ShoppingCart class:
o + to merge two shopping carts
o - to remove an item from the cart
o * to apply bulk discounts
o / to split cart total among multiple users

6. Create objects for Electronics and Clothing categories, demonstrate method overloading, overriding, and operator overloading by simulating an online shopping experience.*/

#include <iostream>
using namespace std;

class ShoppingCart;

class Product{
    protected:
        int productID;
        double price;

    public:
        Product(int id, double p) : productID(id), price(p) {}

        virtual double calculatePrice() = 0;

        double applyDiscount(float perc){
            return price - (price * (perc/100));
        }

        double applyDiscount(int val){
            return (price>val)? price - val : 0;
        }

        double  applyDiscount(bool isBOGO){
            if(isBOGO)
                return price/2;
            else
                return price;
        }

        virtual void display() {
            cout << "Product ID: " << productID << ", Base Price: $" << price << endl;
        }

        friend class ShoppingCart;
};

class Electronics : public Product{
    float tax;

    public:
        Electronics(int id, double p) : Product(id,p), tax(0.15) {}


        double calculatePrice() override {
            return price + (price*tax);
        }

        void display() override {
            cout << "Electronics - ";
            Product::display();
            cout << "Final Price (with tax): $" << calculatePrice() << endl;
        }

        friend class ShoppingCart;
};


class Clothing : public Product{
    float tax;

    public:
        Clothing(int id, double p) : Product(id,p), tax(0.05) {}

        double calculatePrice() override {
            return price + (price*tax);
        }

        void display() override{
            cout << "Clothing - ";
            Product::display();
            cout << "Final Price (with tax): $" << calculatePrice() << endl;
        }

        friend class ShoppingCart;
};

class ShoppingCart{
    Product* itemsInCart[10];
    int itemsCount;

    public:
        ShoppingCart() : itemsCount(0) {}

        ShoppingCart operator+(const ShoppingCart& otherCart){
            ShoppingCart newCart = *this;

            for (int i = 0; i < otherCart.itemsCount; i++) {
                if (newCart.itemsCount < 10) {
                    newCart.itemsInCart[newCart.itemsCount] = otherCart.itemsInCart[i];  
                    newCart.itemsCount++;
                }
            }
            return newCart;
        }

        ShoppingCart& operator-(int productid){
            for(int i = 0; i < itemsCount; i++){
                if(itemsInCart[i]->productID == productid){
                    for(int j= i; j < itemsCount - 1; j++){
                        itemsInCart[j] =  itemsInCart[j + 1];
                    }
                    itemsCount--;
                    break;
                }
            }
            return *this;
        }

        void operator*(double discount){
            for (int i = 0; i < itemsCount; i++) {
                double newPrice = itemsInCart[i]->price * (1 - discount / 100);
                cout << "Discounted price for Product " << itemsInCart[i]->productID << ": $" << newPrice << endl;
            }
        }

        void operator/(int users) {
            double total = 0;
            for (int i = 0; i < itemsCount; i++) {
                total += itemsInCart[i]->calculatePrice();
            }
            cout << "Each user pays: $" << total / users << endl;
        }

        void addProduct(Product* p) {
            if (itemsCount < 10) {
                itemsInCart[itemsCount++] = p;
            } else {
                cout << "Cart is full!\n";
            }
        }

        void displayCart() const {
            cout << "\nShopping Cart:\n";
            for (int i = 0; i < itemsCount; i++) {
                itemsInCart[i]->display();
            }
            cout << endl;
        }
};

int main(){
    Electronics laptop(101, 1000);
    Clothing tshirt(202, 50);
    Clothing jeans(203, 80);

    ShoppingCart cart1, cart2;
    cart1.addProduct(&laptop);
    cart1.addProduct(&tshirt);

    cart2.addProduct(&jeans);

    cout << "Cart 1:";
    cart1.displayCart();

    cout << "Cart 2:";
    cart2.displayCart();

    
    ShoppingCart mergedCart = cart1 + cart2;
    cout << "\nMerged Cart:";
    mergedCart.displayCart();


    ShoppingCart updatedCart = cart1 - 202;
    cout << "\nUpdated Cart after removing Product 202:";
    updatedCart.displayCart();
}
