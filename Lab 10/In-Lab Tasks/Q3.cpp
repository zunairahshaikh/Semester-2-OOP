#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream createChapter1("chapter1.txt");
    createChapter1 << "Chapter 1: The Beginning\n";
    createChapter1 << "This is the start of our story.\n";
    createChapter1 << "Once upon a time...\n";
    createChapter1.close();

    
    ofstream createChapter2("chapter2.txt");
    createChapter2 << "Chapter 2: The Adventure Continues\n";
    createChapter2 << "Our hero faced many challenges.\n";
    createChapter2 << "But perseverance paid off in the end.\n";
    createChapter2.close();

   
    ifstream chapter1("chapter1.txt");
    ifstream chapter2("chapter2.txt");
    ofstream book("book.txt", ios::app);
    
    if(!chapter1.is_open() || !chapter2.is_open() || !book.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    string line;
    
   
    while (getline(chapter1, line)) {
        book << line << "\n";
    }
    
    
    book << "\n";
    
   
    while (getline(chapter2, line)) {  
        book << line << "\n";  
    }
    
    
    chapter1.close();
    chapter2.close();
    book.close();

 
    ifstream verify("book.txt");
    cout << "Contents of book.txt:\n";
    while (getline(verify, line)) {
        cout << line << endl;
    }
    verify.close();
}
