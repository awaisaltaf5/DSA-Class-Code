#include <iostream>
using namespace std;

// Template class for Stack, allowing it to store any data type
template<class ItemType>
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
    ItemType Top() const;

    // Function to push (insert) an element into the stack
    void Push(ItemType);

    // Function to pop (remove) an element from the stack
    void Pop();

private:
    int top;        // Index of the top element in the stack
    int maxStack;   // Maximum size of the stack
    ItemType* items; // Pointer to dynamically allocated array for stack storage
};

// Constructor: Initializes the stack with a given size
template<class ItemType>
StackType<ItemType>::StackType(int size) {
    top = -1;            // Stack is initially empty
    maxStack = size;     // Set the maximum size of the stack
    items = new ItemType[maxStack]; // Dynamically allocate memory for stack elements
}

// Destructor: Frees dynamically allocated memory when the object is destroyed
template<class ItemType>
StackType<ItemType>::~StackType() {
    delete[] items;  // Free the allocated memory
}

// Function to check if the stack is empty
template<class ItemType>
bool StackType<ItemType>::IsEmpty() const {
    return (top == -1);  // If top is -1, the stack is empty
}

// Function to check if the stack is full
template<class ItemType>
bool StackType<ItemType>::IsFull() const {
    return (top == maxStack - 1);  // If top reaches maxStack-1, stack is full
}

// Function to push (insert) an element into the stack
template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem) {
    if (IsFull()) {
        cout << "Stack Overflow! Cannot push " << newItem << endl;
    } else {
        top++;             // Move top to the next index
        items[top] = newItem; // Insert the new element at the top
    }
}

// Function to pop (remove) an element from the stack
template<class ItemType>
void StackType<ItemType>::Pop() {
    if (IsEmpty()) {
        cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
    } else {
        top--;  // Simply decrement top to remove the top element
    }
}

// Function to get the top element of the stack without removing it
template<class ItemType>
ItemType StackType<ItemType>::Top() const {
    if (IsEmpty()) {
        cout << "Stack is empty! No top element." << endl;
        exit(1); // Exit program if no top element exists
    }
    return items[top]; // Return the top element
}

// Main function to demonstrate stack operations
int main() {
    StackType<int> stack(5); // Create a stack of size 5

    // Pushing elements into stack
    cout << "Pushing elements: 10, 20, 30, 40, 50" << endl;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    // Display the top element
    cout << "Top element: " << stack.Top() << endl; // Should print 50

    // Trying to push when stack is full
    cout << "Trying to push 60 into a full stack:" << endl;
    stack.Push(60); // Stack overflow

    // Popping elements from the stack
    cout << "Popping an element..." << endl;
    stack.Pop();
    cout << "Top element after pop: " << stack.Top() << endl; // Should print 40

    // Emptying the stack
    cout << "Popping all elements to empty the stack..." << endl;
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();

    // Trying to pop when stack is empty
    cout << "Trying to pop from an empty stack:" << endl;
    stack.Pop(); // Stack underflow

    return 0;
}
