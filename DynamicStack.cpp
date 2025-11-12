#include <iostream>
#include <string>
using namespace std;

// Node structure for the stack
struct Node {
    string data;
    Node* next;
};

// Dynamic stack class
class StringStack {
private:
    Node* top; // Points to the top of the stack

public:
    StringStack();          // Constructor
    ~StringStack();         // Destructor
    void push(string str);  // Push a string onto the stack
    bool pop(string& str);  // Pop a string off the stack
    bool isEmpty();         // Check if stack is empty
    void display();         // Display stack contents
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

// Pop a string off the stack
bool StringStack::pop(string& str) {
    if (isEmpty())
        return false;

    Node* temp = top;
    str = top->data;
    top = top->next;
    delete temp;
    return true;
}

// Check if the stack is empty
bool StringStack::isEmpty() {
    return top == nullptr;
}

// Display stack contents
void StringStack::display() {
    Node* current = top;
    cout << "\nStack contents (top to bottom):\n";
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
    string input, popped;

    cout << "=== Dynamic Stack of Strings ===\n";

    // Push strings onto the stack
    for (int i = 0; i < 3; i++) {
        cout << "Enter a string: ";
        getline(cin, input);
        stack.push(input);
    }

    // Display all stack contents
    stack.display();

    // Pop and display all elements
    cout << "\nPopping all elements:\n";
    while (!stack.isEmpty()) {
        stack.pop(popped);
        cout << "Popped: " << popped << endl;
    }

    cout << "\nStack is now empty.\n";
    return 0;
}
