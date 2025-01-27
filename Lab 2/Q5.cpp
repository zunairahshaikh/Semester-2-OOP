/*You are required to write a c++ function swap_string that shifts the last n characters of a string to the
front n times. It will take str and int as parameters. And will return the new string after shifting.
Note: You have to work with pointers.*/

#include <iostream>
#include <cstring>
using namespace std;

char* swap_string(char* str, int n) {
    int length = strlen(str);

    if (n >= length || n <= 0) {
        return str;
    }

    char* result = new char[length + 1]; // +1 for null-terminator

    int i = 0;
    for (int j = length - n; j < length; ++j, ++i) {
        result[i] = str[j];
    }

    for (int j = 0; j < length - n; ++j, ++i) {
        result[i] = str[j];
    }

    result[i] = '\0';

    return result;
}

int main() {
    char str[100];  //to hold the input string 
    int n;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    cout << "Enter the number of characters to shift: ";
    cin >> n;

    cout << "Original string: " << str << endl;

    char* newStr = swap_string(str, n);

    cout << "Modified string: " << newStr << endl;

    delete[] newStr;
}

