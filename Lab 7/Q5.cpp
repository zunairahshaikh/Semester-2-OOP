#include <iostream>
using namespace std;

class Media{
    protected:
        string title, uniqueID, publicationDate, publisher;
    
    public:
        Media(string t, string id, string pd, string p) : title(t), uniqueID(id), publicationDate(pd), publisher(p) {}

        virtual void displayInfo(){
            cout << "Title: " << title << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "Publisher: " << publisher << endl;
        }

        void checkOut(){
            cout << title << " has been checked out." << endl;
        }

        void returnItem(){
            cout << title << " has been returned." << endl;
        }
};

class Book : public Media{
    string author;
    long int ISBN;
    int numberOfPages;

    public:
        Book(string t, string id, string pd, string p, string a, long int isbn, int pgs) : Media(t,id,pd,p), author(a), ISBN(isbn), numberOfPages(pgs) {}

        void displayInfo() override {
            Media::displayInfo();
            cout << "Author: " << author << endl;
            cout << "ISBN: " << ISBN << endl;
            cout << "Number Of Pages: " << numberOfPages << " pages" <<endl;
        }
};

class DVD : public Media{
    string director;
    int duration;
    float rating;

    public:
        DVD(string t, string id, string pd, string p, string d, int du, float r) : Media(t,id,pd,p), director(d), duration(du), rating(r) {}

        void displayInfo() override {
            Media::displayInfo();
            cout << "Director: " << director << endl;
            cout << "Duration: " << duration << " minutes" << endl;
            cout << "Rating: " << rating << endl;
        }
};

class CD : public Media{
    string artist, genre;
    int numberOfTracks;

    public:
        CD(string t, string id, string pd, string p, string a, string g, int tracks) : Media(t,id,pd,p), artist(a), genre(g), numberOfTracks(tracks) {}

        void displayInfo() override {
            Media::displayInfo();
            cout << "Artist: " << artist << endl;
            cout << "Genre: " << genre << endl;
            cout << "Number Of Tracks: " << numberOfTracks << endl;
        }
};

class Magazine : public Media {
    public:
        Magazine(string t, string id, string pd,  string p) : Media(t, id, pd, p) {}
    
        void displayInfo() override {
            Media::displayInfo();
            cout << "Category: Magazine" << endl;
        }
};

void searchMedia(string title) {
    cout << "Searching for media with title: " << title << endl;
}

void searchMedia(long int ISBN) {
    cout << "Searching for books by ISBN: " << ISBN << endl;
}

void searchMedia(int publicationYear) {
    cout << "Searching for media published in: " << publicationYear << endl;
}
