#include <iostream>
#include <string>
using namespace std;

// Node structure for the stack
struct Node {
    string data; // stores the string
    Node* next;  // pointer to the next node
};

// Dynamic stack class
class StringStack {
private:
    Node* top; // top of the stack

public:
    StringStack();          // constructor
    ~StringStack();         // destructor
    void push(string str);  // push a string onto the stack
    bool isEmpty();         // check if the stack is empty
    void display();         // display all strings in the stack
};

// Constructor
StringStack::StringStack() {
    top = nullptr;
}

// Destructor
StringStack::~StringStack() {
    Node* temp;
    while (top != nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }
}

// Push a string onto the stack
void StringStack::push(string str) {
    Node* newNode = new Node;
    newNode->data = str;
    newNode->next = top;
    top = newNode;
}

// Check if the stack is empty
bool StringStack::isEmpty() {
    return top == nullptr;
}

// Display all strings in the stack
void StringStack::display() {
    if (isEmpty()) {
        cout << "\nThe stack is empty.\n";
        return;
    }

    cout << "\nStrings stored in the dynamic stack (top to bottom):\n";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

// -----------------------------
// Main function (driver program)
// -----------------------------
int main() {
    StringStack stack;
    string input;

    cout << "=== Dynamic Stack of Strings ===\n";
    cout << "Enter strings to store in the stack.\n";
    cout << "Type 'done' to stop.\n\n";

    while (true) {
        cout << "Enter a string: ";
        getline(cin, input);

        if (input == "done" || input == "DONE")
            break;

        stack.push(input);
    }

    // Display all stored strings
    stack.display();

    cout << "\nProgram ended successfully.\n";
    return 0;
}
