#include <iostream>  // Include input-output stream library
using namespace std;

// Define a structure for a node in the linked list
struct node {
    int info;  // Data stored in the node
    node* link;  // Pointer to the next node in the list
};

// Global pointer to the head of the linked list, initially NULL
node* head = NULL;

// Global count to track the number of nodes in the list
int count = 0;

/**
 * Function to insert a new node at the beginning of the linked list
 * @param data The value to be inserted
 */
void insertBeg(int data) {
    node* newNode = new node;  // Allocate memory for a new node
    newNode->info = data;  // Assign data to the node
    newNode->link = head;  // Point the new node to the current head
    head = newNode;  // Update head to point to the new node
    count++;  // Increment count of nodes
}

/**
 * Function to display the linked list and the count of nodes
 */
void display() {
    node* current = head;  // Start from the head node
    while (current != NULL) {  // Traverse until the last node
        cout << current->info << "\t";  // Print node data
        current = current->link;  // Move to the next node
    }
    cout << endl;
    cout << "Value of count = " << count << endl;  // Print number of nodes
}

/**
 * Main function to test the linked list implementation
 */
int main() {
    insertBeg(10);  // Insert 10 at the beginning
    insertBeg(20);  // Insert 20 at the beginning
    insertBeg(30);  // Insert 30 at the beginning
    display();  // Display the linked list
    return 0;
}

/* ================= DRY RUN ===================
Step 1: Initial State
    head = NULL
    count = 0

Step 2: insertBeg(10)
    1. Create a new node:
       newNode->info = 10
       newNode->link = head (which is NULL)
    2. Update head to point to the new node.
    Linked List Now:
       head → [10 | NULL]
       count = 1

Step 3: insertBeg(20)
    1. Create a new node:
       newNode->info = 20
       newNode->link = head (which points to 10)
    2. Update head to point to the new node.
    Linked List Now:
       head → [20 | *] → [10 | NULL]
       count = 2

Step 4: insertBeg(30)
    1. Create a new node:
       newNode->info = 30
       newNode->link = head (which points to 20)
    2. Update head to point to the new node.
    Linked List Now:
       head → [30 | *] → [20 | *] → [10 | NULL]
       count = 3

Step 5: Calling display()
    1. Start from head (30), print 30, move to next node.
    2. Print 20, move to next node.
    3. Print 10, move to next node (NULL, stop).

    Output:
    30    20    10    
    Value of count = 3
================================================ */
