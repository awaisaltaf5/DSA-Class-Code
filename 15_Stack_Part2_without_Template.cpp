#include <iostream>
using namespace std;

class StackType {
public:
    // Constructor to initialize the stack with a given size
    StackType(int size);

    // Destructor to free allocated memory
    ~StackType();

    // Function to check if the stack is empty
    bool IsEmpty() const;

    // Function to check if the stack is full
    bool IsFull() const;

    // Function to return the top element of the stack
    int Top() const;

    // Function to push (insert) an element into the stack
    void Push(int newItem);

    // Function to pop (remove) an element from the stack
    void Pop();

private:
    int top;      // Index of the top element in the stack
    int maxStack; // Maximum size of the stack
    int* items;   // Pointer to dynamically allocated array for stack storage
};

// Constructor
StackType::StackType(int size) {
    top = -1;
    maxStack = size;
    items = new int[maxStack];
}

// Destructor
StackType::~StackType() {
    delete[] items;
}

// Check if the stack is empty
bool StackType::IsEmpty() const {
    return (top == -1);
}

// Check if the stack is full
bool StackType::IsFull() const {
    return (top == maxStack - 1);
}

// Push an element onto the stack
void StackType::Push(int newItem) {
    if (IsFull()) {
        cout << "Stack Overflow! Cannot push " << newItem << endl;
    } else {
        top++;
        items[top] = newItem;
    }
}

// Pop an element from the stack
void StackType::Pop() {
    if (IsEmpty()) {
        cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
    } else {
        top--;
    }
}

// Get the top element of the stack
int StackType::Top() const {
    if (IsEmpty()) {
        cout << "Stack is empty! No top element." << endl;
        exit(1);
    }
    return items[top];
}

// Main function to demonstrate stack operations
int main() {
    StackType stack(5);

    // Pushing elements into stack
    cout << "Pushing elements: 10, 20, 30, 40, 50" << endl;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    // Display the top element
    cout << "Top element: " << stack.Top() << endl;

    // Trying to push when stack is full
    cout << "Trying to push 60 into a full stack:" << endl;
    stack.Push(60);

    // Popping an element
    cout << "Popping an element..." << endl;
    stack.Pop();
    cout << "Top element after pop: " << stack.Top() << endl;

    // Emptying the stack
    cout << "Popping all elements to empty the stack..." << endl;
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();

    // Trying to pop when stack is empty
    cout << "Trying to pop from an empty stack:" << endl;
    stack.Pop();

    return 0;
}
