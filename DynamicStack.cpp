#include <iostream>
#include <string>
using namespace std;

// Node structure to hold a string and a pointer to the next node
struct Node {
    string data;
    Node* next;
};

// Class for a dynamic stack of strings
class StringStack {
private:
    Node* top; // pointer to the top of the stack

public:
    // Constructor
    StringStack() {
        top = nullptr;
    }

    // Destructor to free memory
    ~StringStack() {
        Node* temp;
        while (top != nullptr) {
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Push a new string onto the stack
    void push(string item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    // Pop a string from the stack
    bool pop(string &item) {
        if (isEmpty())
            return false;
        Node* temp = top;
        item = top->data;
        top = top->next;
        delete temp;
        return true;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Test program
int main() {
    StringStack stack;
    string word;

    cout << "Adding strings to the stack..." << endl;
    stack.push("Los Angeles");
    stack.push("City College");
    stack.push("CS 136");
    stack.push("Dynamic Stack");

    cout << "\nRemoving strings from the stack:\n";
    while (stack.pop(word)) {
        cout << word << endl;
    }

    cout << "\nStack is now empty." << endl;
    return 0;
}
