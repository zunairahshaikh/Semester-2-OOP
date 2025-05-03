/*Create a template class Stack<T> with a fixed capacity. Implement methods push() and pop(). Throw:

- StackOverflowException (class) if pushing to a full stack.
- StackUnderflowException (class) if popping from an empty stack.

Requirements:
- Both exceptions inherit from std::exception and override what().
- Include error details (e.g., "Stack is full!");
- Demonstrate exceptions in main().

Sample Input/Output:
Pushing to a full stack: StackOverflowException - Stack is full!
Popping from an empty stack: StackUnderflowException - Stack is empty!*/

#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class StackOverflowException : public exception {
    public:
        const char* what() const noexcept override {
            return "Stack is full!";
        }
};

class StackUnderflowException : public exception {
    public:
        const char* what() const noexcept override {
            return "Stack is empty!";
        }
};

template <typename T, int capacity = 3>
class Stack{
    T data[capacity];
    int topIndex = 0;

    public:
        void push(const T& val){
            if(topIndex >= capacity)
                throw StackOverflowException();
            else{
                data[topIndex] = val;
                topIndex++;
                cout << val << " pushed successfully." << endl;
            }
        }

        void pop(){
            if(topIndex == 0)
                throw StackUnderflowException();
            else{
                topIndex--;
                cout << data[topIndex] << " popped successfully." << endl;
            } 
        }
};

int main(){
    try{
        Stack<int, 3> myStack;

        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        myStack.push(40); // checking obverflow
        myStack.pop();
        myStack.pop();
        myStack.pop();
        myStack.pop(); // checking underflow

        // myStack.push(40);
        // myStack.push(50);
        // myStack.push(60);
        // myStack.push(70);

        }
        catch (const StackOverflowException& e) {
            cerr << "Error: " << e.what() << endl;
        }
        catch (const StackUnderflowException& e) {
            cerr << "Error: " << e.what() << endl;
        }
        catch (const exception& e) {
            cerr << "Unknown error: " << e.what() << endl;
        }
}
