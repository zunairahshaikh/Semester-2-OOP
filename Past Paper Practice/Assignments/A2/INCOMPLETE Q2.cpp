/*Let’s say you are working to simulate a Haunted House based game!
Your game allows users to create multiple Haunted Houses with ghosts of their own choices. After creating a Haunted House, the user can run a simulation
to see how well the Haunted House is doing in terms or visitor experience and scares!
Let’s have a look at the entities involved:
• HauntedHouse – has a name and multiple ghosts (ensure runtime polymorphism here).
• Ghost – the super class for all types of ghosts. It will contain everything that is shared between different types of ghosts.
For example: name of the worker playing the ghost, the scare level of the ghost (RNG 1-10), a function to perform the haunting, etc.
Ghosts have some operator overloading done on the << operator to display information about them, and + operator to upgrade a
ghost (results in a ghost with two people playing a bigger ghost and combined scare level of both ghosts)
• There are different ghosts who perform hauntings differently; Poltergeists (move objects), Banshees (scream loudly), and ShadowGhosts (whisper creepily).
• There are also some hybrid ghosts that may appear; for example, ShadowPoltergeist (is a shadow ghost and Poltergeist). This ghost performs both actions of a ShadowGhost
and a Poltergeist.
• Visitor – a class of objects that can “visit” a Haunted house. Each visitor has a name and some amount of bravery (1-4: Cowardly, 5-7: Average, 8-10: Fearless).
When a visitor visits a Haunted House, the ghosts will try to haunt them. If the scare level of the ghost is less than the bravery range of
the visitor, then the visitor might laugh or taunt the ghost. If it is greater, then the visitor might scream or run away. If it’s around average,
then they might get a shaky voice. (please make sure to check if the scare level lies within the bravery range; DO NOT compare the numbers directly)
• Main method should make 2-3 Haunted Houses with multiple ghosts of each type.
• Main method should also have an array of Visitors (a group of friends visiting the haunted house) Try to ensure that there’s at least one
of each bravery level among the group.
• “Visit” is a global friend function that accepts the Visitors array and a Haunted House, and then simulates the visit.
• Do the same for each Haunted house that you made.*/

#include <iostream>
using namespace std;

class Ghost{
    protected:
        string name;
        int scareLevel;
        string hauntingType;
    public:
        Ghost(string n, int s, string h) : name(n), scareLevel(s), hauntingType(h) {}

        virtual ~Ghost() {}
        virtual void haunt() = 0;

        friend ostream& operator<<(ostream& out, const Ghost& g) {
            out << "Name: " << g.name << "\nScare Level: " << g.scareLevel << "\nHaunting Type: " << g.hauntingType << endl;
            return out;
        }

        Ghost* operator+(const Ghost& other) {
            return new Poltergeist(name + " and " + other.name, scareLevel + other.scareLevel, hauntingType + " and " + other.hauntingType, "combined object");
        }

        string getName() const {
            return name; 
        }

        int getScareLevel() const {
            return scareLevel;
        }
};

class Poltergeist : public virtual Ghost{
    string object;
    public: 
        Poltergeist(string n, int s, string h, string o) : Ghost(n, s, h), object(o) {}

        void haunt() override {
            cout << "Poltergeist " << name << " is moving " << object << " around." << endl;
        }

        string getObjectName() const {
            return object;
        }
};

class Banshee : public Ghost{
    string sound;
    public:
        Banshee(string n, int s, string h) : Ghost(n, s, h){}
        void haunt() override {
            cout << "Banshee " << name << " is screaming " << endl;
        }
};

class ShadowGhost : public virtual Ghost{
    string whisper;
    public:
        ShadowGhost(string n, int s, string h) : Ghost(n, s, h){}
        void haunt() override {
            cout << "Shadow Ghost " << name << " is whispering creepily" << endl;
        }

};

class ShadowPoltergeist : public Poltergeist, public ShadowGhost{
    public:
        ShadowPoltergeist(string n, int s, string h, string o) : Ghost(n, s, h), Poltergeist(n, s, h, o), ShadowGhost(n, s, h) {}

        void haunt() override {
            cout << "Shadow Poltergeist " << name << " is moving " << getObjectName() << " around and whispering creepily" << endl;
        }
};

class Visitor{
    string name;
    int bravery;
    public:
        Visitor(string n, int b) : name(n), bravery(b) {}

        string getName() const {
            return name;
        }

        int getBravery() const {
            return bravery;
        }
};

class HauntedHouse{
    string name;
    Ghost** ghosts;
    int ghostCount;
    public:
        HauntedHouse(string n, int maxGhosts) : name(n), ghostCount(0) {
            ghosts = new Ghost*[maxGhosts];
        }

        ~HauntedHouse() {
            for (int i = 0; i < ghostCount; i++) 
                delete ghosts[i];
            delete[] ghosts;
        }

        void addGhost(Ghost* g) {
            ghosts[ghostCount++] = g;
            cout << "Ghost " << g->getName() << " added to " << name << ".\n";
        }

        void visit(Visitor* v) {
            cout << "Visitors are entering " << name << "...\n";
            for (int i = 0; i < ghostCount; i++) {
                if (ghosts[i]->getScareLevel() < v->getBravery()) {
                    cout << "Visitor " << v->getName() << " is laughing at " << ghosts[i]->getName() << ".\n";
                } else {
                    cout << "Visitor " << v->getName() << " is screaming and running away from " << ghosts[i]->getName() << ".\n";
                }
            }
            cout << "Visitors are leaving " << name << "...\n";
        }
};

void visit(Visitor** visitors, HauntedHouse* house, int visitorCount) {
    for (int i = 0; i < visitorCount; i++) {
        house->visit(visitors[i]);
    }
}

int main() {
    HauntedHouse* houses[3] = {
        new HauntedHouse("Creepy Cabin", 3),
        new HauntedHouse("Mysterious Mansion", 3),
        new HauntedHouse("Boo Bungalow", 3)
    };

    Ghost* ghosts[9] = {
        new Poltergeist("P1", 5, "moving objects", "chair"),
        new Poltergeist("P2", 6, "moving objects", "table"),
        new Poltergeist("P3", 7, "moving objects", "book"),
        new Banshee("B1", 8, "screaming"),
        new Banshee("B2", 9, "screaming"),
        new Banshee("B3", 10, "screaming"),
        new ShadowGhost("SG1", 3, "whispering"),
        new ShadowGhost("SG2", 4, "whispering"),
        new ShadowGhost("SG3", 5, "whispering")
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            houses[i]->addGhost(ghosts[(i * 3) + j]);
        }
    }

    Visitor* visitors[4] = {
        new Visitor("Aman", 2),
        new Visitor("Bisma", 5),
        new Visitor("Sarah", 8),
        new Visitor("Hasan", 3),
    };

    visit(visitors, houses[0], 5);
    visit(visitors, houses[1], 5);
    visit(visitors, houses[2], 5);

    for (int i = 0; i < 3; i++) 
        delete houses[i];

    for (int i = 0; i < 9; i++) 
        delete ghosts[i];

    for (int i = 0; i < 5; i++) 
        delete visitors[i];

    return 0;
}
