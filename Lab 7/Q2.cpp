/*Picture an innovative design tool aimed at architects and graphic designers that allows for creating, manipulating, and analyzing various geometric shapes.
The system is structured around a Shape class, which includes data members such as position, color, and an optional borderThickness. It provides functions like draw() for
rendering, calculateArea() for area measurement, and calculatePerimeter() for perimeter computation.

Derived classes such as Circle, Rectangle, Triangle, and Polygon introduce their own properties--for example, a Circle includes radius and center position, while a Rectangle
includes width, height, and top left corner position. Each derived class overrides draw(), calculateArea(), and calculatePerimeter() to handle their respective geometries.*/

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    protected:
        int positionX, positionY;
        string color;
        int borderThickness;

    public:
        Shape(int x, int y, string c, int bt = 1) : positionX(x), positionY(y), color(c), borderThickness(bt) {}

        virtual void draw() = 0;

        virtual double calculateArea() = 0;

        virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
    int radius;

    public:
        Circle(int x, int y, string c, int r, int bt = 1) : Shape(x, y, c, bt), radius(r) {}

        void draw() override {
            cout << "Drawing Circle at (" << positionX << ", " << positionY << ") with radius " << radius << ", color: " << color << ", border thickness: " << borderThickness << endl;
        }

        double calculateArea() override {
            return 3.14159 * radius * radius;
        }

        double calculatePerimeter() override {
            return 2 * 3.14159 * radius;
        }
};

class Rectangle : public Shape {
    int width, height;

    public:
        Rectangle(int x, int y, string c, int w, int h, int bt = 1) : Shape(x, y, c, bt), width(w), height(h) {}

        void draw() override {
            cout << "Drawing Rectangle at (" << positionX << ", " << positionY << ") with width " << width << ", height " << height << ", color: " << color << ", border thickness: " << borderThickness << endl;
        }

        double calculateArea() override {
            return width * height;
        }

        double calculatePerimeter() override {
            return 2 * (width + height);
        }
};

class Triangle : public Shape {
    int side1, side2, side3;

    public:
        Triangle(int x, int y, string c, int s1, int s2, int s3, int bt = 1) : Shape(x, y, c, bt), side1(s1), side2(s2), side3(s3) {}

        void draw() override {
            cout << "Drawing Triangle at (" << positionX << ", " << positionY << ") with sides " << side1 << ", " << side2 << ", " << side3 << ", color: " << color << ", border thickness: " << borderThickness << endl;
        }

        double calculateArea() override {
            double s = (side1 + side2 + side3) / 2.0;
            return sqrt(s * (s - side1) * (s - side2) * (s - side3));
        }

        double calculatePerimeter() override {
            return side1 + side2 + side3;
        }
};

class Polygon : public Shape {
    int numSides;
    int* sides;

    public:
        Polygon(int x, int y, string c, int n, int* s, int bt = 1) : Shape(x, y, c, bt), numSides(n) {
            sides = new int[numSides];
            for (int i = 0; i < numSides; i++) {
                sides[i] = s[i];
            }
        }

        void draw() override {
            cout << "Drawing Polygon at (" << positionX << ", " << positionY << ") with sides ";
            for (int i = 0; i < numSides; i++) {
                cout << sides[i] << " ";
            }
            cout << ", color: " << color << ", border thickness: " << borderThickness << endl;
        }

        double calculateArea() override {
            double area = 0.0;
            for (int i = 0; i < numSides; i++) {
                area += sides[i] * sides[(i + 1) % numSides];
            }
            return 0.5 * abs(area);
        }

        double calculatePerimeter() override {
            double perimeter = 0.0;
            for (int i = 0; i < numSides; i++) {
                perimeter += sides[i];
            }
            return perimeter;
        }
};

int main() {
    Shape* shapes[4];
    shapes[0] = new Circle(10, 10, "Red", 5);
    shapes[1] = new Rectangle(20, 20, "Green", 10, 15);
    shapes[2] = new Triangle(30, 30, "Blue", 3, 4, 5);
    int sides[] = {4, 5, 6, 7};
    shapes[3] = new Polygon(40, 40, "Yellow", 4, sides);

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl;
        cout << endl;
    }

    return 0;
}
