/*Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of
those Square objects. After each time the area method is called, call that square’s getters for area and
allareas to display the updated values.*/

#include <iostream>
using namespace std;

class Square{
        float sideLength;
        float area;
        static float allareas;
    public:
        Square(){
            sideLength = 0;
            area = 0;
        }
        Square(float sideLength){
            this->sideLength = sideLength;
            area = 0;
        }
        void calculateArea(){
            area = sideLength * sideLength;
            allareas += area;
        }
        float getSideLength(){
            return sideLength;
        }
        void setSideLength(float sideLength){
            this->sideLength = sideLength;
        }
        float getArea(){
            return area;
        }
        static float getAllAreas(){
            return allareas;
        }
};

float Square::allareas =0.0;

int main(){
    Square s1(2);
    s1.calculateArea();
    cout << "Area of s1: " << s1.getArea() << endl;
    cout << "All areas: " << s1.getAllAreas() << endl;

    Square s2(3.95);
    s2.calculateArea();
    cout << "Area of s2: " << s2.getArea() << endl;
    cout << "All areas: " << s2.getAllAreas() << endl;

    Square s3(4);
    s3.calculateArea();
    cout << "Area of s3: " << s3.getArea() << endl;
    cout << "All areas: " << s3.getAllAreas() << endl;

    return 0;
}
