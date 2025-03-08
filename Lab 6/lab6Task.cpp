/*1. Create a Message class
o It should have a private instance variable text of type string to store the message content.
o Implement a method toString() that returns the message text.
o Provide a setter method to modify the text value.

2. Create an SMS class that inherits from Message
o It should have an additional instance variable recipientContactNo to store the recipient’s phone number.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing the recipient’s contact number and the message text.

3. Create an Email class that inherits from Message
o It should have additional instance variables: sender, receiver, and subject.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing sender, receiver, subject, and the message text.

4. Implement Keyword Search Function
o Define a function:
o bool ContainsKeyword(const Message& messageObject, const string& keyword);
o This function should return true if the text of the Message object contains the given keyword, otherwise return false.

5. Implement Message Encoding
o Define a function to encode a given message using the following scheme:
 Each character should be replaced by the next character in the alphabet
(e.g., ‘A’ → ‘B’, ‘b’ → ‘c’, ‘Z’ → ‘A’, ‘z’ → ‘a’).
 Example: If the message is "This is Java", the encoded message should be
"Uijt jt Kbwb".

6. Test the Implementation
o In the main() function, create sample objects of SMS and Email, assign values, and test the functionalities including keyword search and encoding.*/

#include <iostream>
using namespace std;

class Message{
    string text;

    public:
        string toString(){
            return text;
        }

        void setText(string t){
            text = t;
        }
        
        string getText() const {
            return text;
        }
};

class SMS : public Message{
    string  recipientContactNo;

    public:
        void setRecpientContactNo(string num){
            recipientContactNo = num;
        }

        string getRecipientContactNo(){
            return recipientContactNo;
        }

        string toString(){
            string newText = recipientContactNo + ": " + Message::toString();
            return newText;
        }        
};

class Email : public Message{
    string sender, receiver, subject;

    public:
        void setSender(string s){
            sender = s;
        }

        void setReceiver(string r){
            receiver= r;
        }

        void setSubject(string subj){
            subject = subj;
        }

        string getSender(){
            return sender;
        }

        string getReceiver(){
            return receiver;
        }

        string getSubject(){
            return subject;
        }

        string toString(){
            string newText = "Sender: " + sender + "\n" + "Receiver: " + receiver + "\n" + "Subject: " + subject + "\n" + Message::toString();
            return newText;
        }         
};

bool ContainsKeyword(const Message& messageObject, const string& keyword);
string EncodeMessage(const Message& messageObject);

int main(){
    SMS sms;
    sms.setText("Hello, how are you?");
    sms.setRecpientContactNo("1234567890");

    cout << "SMS: " << sms.toString() << endl;

    cout << endl;

    Email email;
    email.setSender("Student");
    email.setReceiver("Teacher");
    email.setSubject("Assignment Help");
    email.setText("I am unable to understand Q1 of the assignment. Can you please help me?");

    cout << "Email: " << email.toString() << endl;

    cout << endl;

    bool keywordPresent = ContainsKeyword(sms, "Hello");
    cout << "Keyword Present in SMS: " << keywordPresent << endl;

    cout << "Encoded Message: " << EncodeMessage(sms) << endl;
    cout << "Encoded Message: " << EncodeMessage(email) << endl;

}

bool ContainsKeyword(const Message& messageObject, const string& keyword){
    string text = messageObject.getText();

    if (keyword.length() == 0) {
        return false;
    }

    for (int i = 0; i <= text.length() - keyword.length(); i++) {
        bool found = true;
        for (int j = 0; j < keyword.length(); j++) {
            if (text[i + j] != keyword[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }

    return false;
}

string EncodeMessage(const Message& messageObject){
    string text = messageObject.getText();

    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + 1) % 26 + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + 1) % 26 + 'a';
        }
    }

    return text;
}
