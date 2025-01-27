/*You are required to write a C++ program that will creates a function named unique that will take array
as input . the array may contains the duplicates values but you have to process on the array and have to
return the array which must contains only unique values not duplicates.*/

#include <iostream>
using namespace std;

int* unique(int arr[], int &size) {
    int* uniqueArr = new int[size];
    int uniqueCount = 0;

    for (int i = 0; i < size; ++i) {
        bool isDuplicate = false;

        for (int j = 0; j < uniqueCount; ++j) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            uniqueArr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    size = uniqueCount;
    return uniqueArr;
}

int main() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int* arr = new int[size];
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int* uniqueArr = unique(arr, size);

    cout << "Array with unique values: ";
    for (int i = 0; i < size; ++i) {
        cout << uniqueArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] uniqueArr;

    return 0;
}
