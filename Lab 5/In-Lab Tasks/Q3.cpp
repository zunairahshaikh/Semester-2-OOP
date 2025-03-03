/*Create a class called ValidateString. The purpose of this class will be check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.*/

#include <iostream>
#include <cctype>
using namespace std;

class ValidateString{
        string str;
    public:
        ValidateString(string str){
            this->str = str;
        }
        // This function is constant because it does not modify the object's state. It only checks if the string is valid or not.
        bool isValid() const{
            for(int i = 0; i < str.length(); i++){
                if(!isalpha(str[i])){
                    return false;
                }
            }
            return true;
        }
};

int main(){
    ValidateString vs1("Hello");
    cout << "String is " << (vs1.isValid() ? "valid" : "invalid") << endl;

    ValidateString vs2("Hello!!");
    cout << "String is " << (vs2.isValid() ? "valid" : "invalid") << endl;

    return 0;
}
