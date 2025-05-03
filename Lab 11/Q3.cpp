#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

class FileException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "File error occurred";
    }
};

class FileNotFoundException : public FileException {
public:
    const char* what() const noexcept override {
        return "File not found";
    }
};

class PermissionDeniedException : public FileException {
public:
    const char* what() const noexcept override {
        return "Permission denied";
    }
};

void readFile(const string& filename) {
    ifstream file(filename);
    
    if (!file.good()) {
        if (filename == "secret.txt") {
            throw PermissionDeniedException();
        } else {
            throw FileNotFoundException();
        }
    }
    
    cout << "Reading file: " << filename << endl;
    file.close();
}

int main() {
    try {
        readFile("nonexistent.txt");
        readFile("secret.txt");
    } 
    catch (const PermissionDeniedException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const FileNotFoundException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const FileException& e) {
        cerr << "Generic file error: " << e.what() << endl;
    }
}
