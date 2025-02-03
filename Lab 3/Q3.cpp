/*Q3. Create a class that includes a data member that holds a “serial number” for each object created from the class.
That is, the first object created will be numbered 1, the second 2, and so on. To do this, you’ll need another data
member that records a count of how many objects have been created so far. (This member should apply to the
class as a whole; not to individual objects. What keyword specifies this?) Then, as each object is created, its
constructor can examine this count member variable to determine the appropriate serial number for the new
object.
Add a member function that permits an object to report its own serial number. Then write a main() program that
creates three objects and queries each one about its serial number. They should respond I am object number 2, and
so on.*/

#include <iostream>
using namespace std;

class SerialNumber {
private:
    int serialNumber;
    static int objectCount;

public:
    SerialNumber() {
        serialNumber = ++objectCount;  //increment objectCount and assign serial number
    }

    void reportSerialNumber() const {
        cout << "I am object number " << serialNumber << endl;
    }

    static int getObjectCount() { // static int func because the return variable objectCount is a static int
        return objectCount;
    }
};

int SerialNumber::objectCount = 0;

int main() {
    SerialNumber obj1;
    SerialNumber obj2;
    SerialNumber obj3;

    obj1.reportSerialNumber();
    obj2.reportSerialNumber();
    obj3.reportSerialNumber();

    return 0;
}
