//Q1: Write a C++ program to check whether a given number is prime or not. Allow the user to input a number and display whether it's prime or not?

#include <iostream>
using namespace std;

int main(){
    int num;
    bool isPrime = true;
    cout << "Enter an interger: ";
    cin >> num;
    if(num <=1)
        isPrime = false;
        
    for(int i = 2; i < num/2; i++){
        if(num % i == 0)
             isPrime = false;
    }

    if(isPrime == true)
         cout << "Number is prime";
    else
        cout << "Number is not prime";

}