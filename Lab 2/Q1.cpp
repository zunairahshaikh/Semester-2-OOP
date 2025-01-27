/*Write a C++ program that reads a group of n numbers from the user and stores them in a dynamically
allocated array of type float. Then, the program should:
 Calculate the average of the numbers.
 Find the number closest to the average.
 Print the average and the number closest to it.
 Use pointer notation wherever possible.*/

#include <iostream>
using namespace std;

int main(){
    int n;
    float sum = 0.0, avg, closest, minDiff, diff;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    float* arr = new float[n];

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }

    for (int i = 0; i < n; ++i) {
        sum+= *(arr + i);
    }

    avg = sum/n;

    // to find closest number, assign first value of the array to closest, and then keep through the array to find the number which has the min difference from avg
    closest = *(arr);
    minDiff = abs(*(arr) - avg);

    for (int i = 1; i < n; ++i) {
        diff = abs(*(arr + i) - avg);
        if (diff < minDiff) {
            minDiff = diff;
            closest = *(arr + i);
        }
    }

    cout<< "Average: " << avg << endl << "Number closest to average: " << closest << endl;

    delete[] arr;
}
