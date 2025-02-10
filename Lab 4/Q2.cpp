/*A library system allows users to borrow and return books. The system should:
1. Add new books to the collection.
2. Borrow books (check availability).
3. Return books.
4. Display all available books.
Requirements:
 Implement a Book class with attributes: ID, title, author, availability.
 Implement a Library class with:
1. Method to add a book (with unique ID).
2. Method to borrow a book (updates availability).
3. Method to return a book (marks it available).
4. Method to display all available books.
 Store book records dynamically using pointers and DMA.
 Use constructor overloading to initialize books with or without availability status.*/

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int ID;
    string title;
    string author;
    bool availability;

public:
    Book() : ID(0), title(""), author(""), availability(true) {}

    Book(int id, string t, string a, bool avail = true) : ID(id), title(t), author(a), availability(avail) {}

    int getID() const { return ID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return availability; }

    void setAvailability(bool avail) {
        availability = avail;
    }

    void display() const {
        cout << "ID: " << ID << endl << "Title: " << title << endl << "Author: " << author << endl << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
    }
};

class Library {
private:
    Book** books;
    int numBooks;
    int capacity;

public:
    Library(int cap) : capacity(cap), numBooks(0) {
        books = new Book*[capacity];
    }

    ~Library() {
        for (int i = 0; i < numBooks; ++i) {
            delete books[i];
        }
        delete[] books;
    }

    void addBook(int id, string title, string author) {
        if (numBooks < capacity) {
            books[numBooks] = new Book(id, title, author);
            numBooks++;
            cout << "Book added successfully." << endl;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void borrowBook(int id) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i]->getID() == id) {
                if (books[i]->isAvailable()) {
                    books[i]->setAvailability(false);
                    cout << "Book borrowed successfully." << endl;
                    return;
                } else {
                    cout << "Sorry, the book is already borrowed." << endl;
                    return;
                }
            }
        }
        cout << "Error: Book with ID " << id << " not found." << endl;
    }

    void returnBook(int id) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i]->getID() == id) {
                if (!books[i]->isAvailable()) {
                    books[i]->setAvailability(true);
                    cout << "Book returned successfully." << endl;
                    return;
                } else {
                    cout << "Error: The book was not borrowed." << endl;
                    return;
                }
            }
        }
        cout << "Error: Book with ID " << id << " not found." << endl;
    }

    void displayAvailableBooks() const {
        cout << "\nAvailable books in the library:" << endl;
        bool found = false;
        for (int i = 0; i < numBooks; ++i) {
            if (books[i]->isAvailable()) {
                books[i]->display();
                found = true;
            }
        }
        if (!found) {
            cout << "No books are currently available." << endl;
        }
    }
};

int main() {
    Library library(5);

    library.addBook(1, "The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook(2, "1984", "George Orwell");
    library.addBook(3, "To Kill a Mockingbird", "Harper Lee");

    library.displayAvailableBooks();

    library.borrowBook(1);

    library.displayAvailableBooks();

    library.returnBook(1);

    library.displayAvailableBooks();

    library.borrowBook(1);

    return 0;
}
