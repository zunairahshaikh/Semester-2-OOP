/*Q5: Design Event Management System in C++ to facilitate the organization of
events. The program should empower the user to seamlessly manage event
details, including the event name, date, venue, and organizer. Incorporate key
features such as the ability to add events, display comprehensive details of all
events, and perform event searches based on specific dates. To enhance
flexibility and scalability, leverage dynamic memory allocation for storing event
details.
1. Prompt the user to input the total number of events they wish to manage.
2. Dynamically allocate memory to store event details for the specified
number of events.
3. For each event, prompt the user to input:
 Event Name
 Date
 Venue
 Organizer
4. Display all events that match the provided date, including their complete
details.
5. Allow the user to search for events based on a specific date.*/

#include <iostream>
#include <string>
using namespace std;

struct Event {
    string eventName;
    string date;
    string venue;
    string organizer;
};

int main() {
    int n;
    bool eventFound = false;
    string searchDate;

    cout << "Enter the number of events you want to manage: ";
    cin >> n;
   
    Event* events = new Event[n];
    
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Event " << i + 1 << ":\n";
        cout << "Event Name: ";
        cin >> events[i].eventName;
        cout << "Date (DD-MM-YYYY): ";
        cin >> events[i].date;
        cout << "Venue: ";
        cin >> events[i].venue;
        cout << "Organizer: ";
        cin >> events[i].organizer;
    }

    cout << "\nEnter a date (DD-MM-YYYY) to search for events: ";
    cin >> searchDate;

    cout << "\nEvents on " << searchDate << ":\n";
    for (int i = 0; i < n; ++i) {
        if (events[i].date == searchDate) {
            eventFound = true;
            cout << "Event " << i + 1 << ":\n";
            cout << "Event Name: " << events[i].eventName << "\n";
            cout << "Date: " << events[i].date << "\n";
            cout << "Venue: " << events[i].venue << "\n";
            cout << "Organizer: " << events[i].organizer << "\n";
        }
    }

    if (!eventFound) {
        cout << "No events found on " << searchDate << ".\n";
    }

    delete[] events;

    return 0;
}
