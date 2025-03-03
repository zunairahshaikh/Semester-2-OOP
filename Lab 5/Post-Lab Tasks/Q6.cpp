/*Write a program that uses composition to implement a game engine. A game engine is madeup of
several components. For example:
a) Graphics rendering engine
b) Input handler
c) Physics engine
You don’t have to write the logicforhow these individual components work.*/

#include <iostream>
using namespace std;

class GraphicsRenderingEngine{
        string type;

    public:
        GraphicsRenderingEngine(string t) : type(t){}

        string getType(){
            return type;
        }
};

class InputHandler{
        string type;

    public:
        InputHandler(string t) : type(t){}

        string getType(){
            return type;
        }
};

class PhysicsEngine{
        string type;

    public:
        PhysicsEngine(string t) : type(t){}

        string getType(){
            return type;
        }
};

class GameEngine{
        GraphicsRenderingEngine *gre;
        InputHandler *ih;
        PhysicsEngine *pe;

    public:
        GameEngine(GraphicsRenderingEngine *gre, InputHandler *ih, PhysicsEngine *pe){
            this->gre = gre;
            this->ih = ih;
            this->pe = pe;
        }

        void display(){
            cout << "Graphics Rendering Engine: " << gre->getType() << endl;
            cout << "Input Handler: " << ih->getType() << endl;
            cout << "Physics Engine: " << pe->getType() << endl;
        }
};
