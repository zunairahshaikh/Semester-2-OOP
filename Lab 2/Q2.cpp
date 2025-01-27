/*Write a C++ program that:
 Reads n strings from the user and stores them in a dynamically allocated array of char*.
 Prints the strings in reverse order using pointer arithmetic.
 Finds and prints the string with the most vowels (a, e, i, o, u).
 Calculates and prints the average length of all the strings.
Note: Use pointer notation wherever possible.
If there are multiple strings with the same number of vowels, print the first one encountered*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
    int n;

    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); //so that newline isnt taken as an input string

    char** arr = new char*[n];

    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; ++i) {
        char temp[100]; // temporarily store and read the input string
        cin.getline(temp, 100);
        arr[i] = new char[strlen(temp) + 1]; //dynamically allocate memory for the string, to get the length each time
        strcpy(arr[i], temp);
    }

    //sring with most vowels
    int maxVowels = -1;
    char* stringWithMostVowels = nullptr;
    for (int i = 0; i < n; ++i) {
        int vowelCount = 0;
        char* str = *(arr + i);
        while (*str != '\0') {
            char ch = tolower(*str);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
            str++;
        }
        if (vowelCount > maxVowels) {
            maxVowels = vowelCount;
            stringWithMostVowels = *(arr + i);
        }
    }
    cout << "String with the most vowels: " << stringWithMostVowels << endl;


    //reverse order
    cout << "Strings with characters reversed:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << strrev(arr[i]) << endl;
    }

    //avg length of strings
    int totLen = 0;
    for(int i = 0; i < n; ++i){
        totLen += strlen(*(arr+i));
    }

    float avgLen = (float)totLen/(float)n;
    cout << "Average length of all strings: " << avgLen << endl;

    for (int i = 0; i < n; ++i) {
        delete[] arr[i]; //one string
    }
    delete[] arr; //whole array of the strings
}
