/*Keeping in mind our previous car example, write a class that represents a car, and useaggregation and composition to combine different components like engine, wheels, headlights and steering to create the
car object.

Hint: create the individual classes firstbeforeperforming the composition. Remember thatfor aggregation, you will need pointers! You’ll be needing constructors and setters to set these values
in case of aggregation. Same hint applies to other questions.*/

#include <iostream>
using namespace std;

class Engine{
        string type;

    public:
        Engine(string t) : type(t){}

        string getType(){
            return type;
        }
};

class Wheel{
        int size;

    public:
        Wheel(int s) : size(s){}

        int getSize(){
            return size;
        }
};

class Headlight{
        string type;

    public:
        Headlight(string t) : type(t){}

        string getType(){
            return type;
        }
};

class Steering{
        string type;

    public:
        Steering(string t) : type(t){}

        string getType(){
            return type;
        }
};

class Car{
        Engine *engine;
        Wheel *wheels;
        Headlight *headlights;
        Steering *steering;

    public:
        Car(Engine *e, Wheel *w, Headlight *hl, Steering *s) : engine(e), wheels(w), headlights(hl), steering(s){}

        void display() const{
            cout << "Engine: " << engine->getType() << endl;
            cout << "Wheel Size: " << wheels->getSize() << endl;
            cout << "Headlight Type: " << headlights->getType() << endl;
            cout << "Steering Type: " << steering->getType() << endl;
        }
};

int main(){
    Engine e("V8");
    Wheel w(18);
    Headlight hl("LED");
    Steering s("Power");

    Car c(&e, &w, &hl, &s);
    c.display();

    return 0;
}
