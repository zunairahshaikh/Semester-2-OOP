/*Q5. You're building a tool to search and replace a specific word in a text file without
rewriting the entire file.
Requirements:

1. Create and populate a file named data.txt with a few sentences. (e.g., AI is the
future. AI will transform the world. Embrace AI now.)
2. Prompt the user to enter:
○ A searchWord (e.g., "AI")
○ A replacementWord (e.g., "ML")
3. Open the file using fstream in ios::in | ios::out mode.
4. Search for the searchWord using seekg() and read sequentially.
5. When found:
○ Use tellg() to get the current read pointer location.
○ Use seekp() to position the write pointer.
○ Replace the word only if the replacement is of equal or smaller length to
avoid shifting content.

6. If the word is replaced, pad with spaces if needed (e.g., replacing "AI" with "ML" or
"XX").
7. After all replacements, display the updated file.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream create_file("data.txt");
    if (create_file.is_open()) {
        create_file << "AI is the future.\nAI will transform the world.\nEmbrace AI now." << endl;
        create_file.close();
    }
    else {
        cout << "Cannot create a file." << endl;
        return 1;
    }

    string searchWord, replacementWord;
    cout << "Enter a word to search: ";
    cin >> searchWord;
    cout << "Enter a word to replace the searched word: ";
    cin >> replacementWord;

    if (replacementWord.length() > searchWord.length()) {
        cout << "Replacement word must be equal or smaller in length than the search word." << endl;
        return 1;
    }

    fstream file("data.txt", ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Cannot open the file!" << endl;
        return 1;
    }

    char ch;
    string word;
    streampos pos;

    while (true) {
        pos = file.tellg();
        word = "";

        for (int i = 0; i < searchWord.length(); i++) {
            file.get(ch);
            if (file.eof())
                break;
            word += ch;
        }

        if (file.eof())
            break;

        if (word == searchWord)
        {
            /*Q5. You're building a tool to search and replace a specific word in a text file without
rewriting the entire file.
Requirements:

1. Create and populate a file named data.txt with a few sentences. (e.g., AI is the
future. AI will transform the world. Embrace AI now.)
2. Prompt the user to enter:
○ A searchWord (e.g., "AI")
○ A replacementWord (e.g., "ML")
3. Open the file using fstream in ios::in | ios::out mode.
4. Search for the searchWord using seekg() and read sequentially.
5. When found:
○ Use tellg() to get the current read pointer location.
○ Use seekp() to position the write pointer.
○ Replace the word only if the replacement is of equal or smaller length to
avoid shifting content.

6. If the word is replaced, pad with spaces if needed (e.g., replacing "AI" with "ML" or
"XX").
7. After all replacements, display the updated file.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream create_file("data.txt");
    if (create_file.is_open())
    {
        create_file << "AI is the future.\nAI will transform the world.\nEmbrace AI now." << endl;
        create_file.close();
    }
    else
    {
        cout << "Cannot create a file." << endl;
        return 1;
    }

    string searchWord, replacementWord;
    cout << "Enter a word to search: ";
    cin >> searchWord;
    cout << "Enter a word to replace the searched word: ";
    cin >> replacementWord;

    if (replacementWord.length() > searchWord.length())
    {
        cout << "Replacement word must be equal or smaller in length than the search word." << endl;
        return 1;
    }

    fstream file("data.txt", ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Cannot open the file!" << endl;
        return 1;
    }

    char ch;
    string word;
    streampos pos;

    while (true)
    {
        pos = file.tellg();
        word = "";

        for (int i = 0; i < searchWord.length(); i++)
        {
            file.get(ch);
            if (file.eof())
                break;
            word += ch;
        }

        if (file.eof())
            break;

        if (word == searchWord)
        {
            file.seekp(pos);
            file << replacementWord;

            for (size_t i = replacementWord.length(); i < searchWord.length(); i++)
            {
                file.put(' ');
            }

            file.seekg(pos + (streamoff)searchWord.length());
        }
        else
        {
            file.seekg(pos + (streamoff)1);
        }
    }

    file.close();

    ifstream read("data.txt");
    if (read.is_open())
    {
        cout << "\nUpdated File Content:" << endl;
        string line;
        while (getline(read, line))
        {
            cout << line << endl;
        }
        read.close();
    }
    else
    {
        cout << "Cannot open the file!" << endl;
        return 1;
    }

    return 0;
}file.seekp(pos);
            file << replacementWord;

            for (size_t i = replacementWord.length(); i < searchWord.length(); i++)
            {
                file.put(' ');
            }

            file.seekg(pos + (streamoff)searchWord.length());
        }
        else
        {
            file.seekg(pos + (streamoff)1);
        }
    }

    file.close();

    ifstream read("data.txt");
    if (read.is_open())
    {
        cout << "\nUpdated File Content:" << endl;
        string line;
        while (getline(read, line))
        {
            cout << line << endl;
        }
        read.close();
    }
    else {
        cout << "Cannot open the file!" << endl;
        return 1;
    }
}