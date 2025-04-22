#include <iostream>
using namespace std;

// Structure for a doubly linked list node
struct node {
    int info;
    node* prev;
    node* next;
};

// Head pointer to the doubly linked list
node* head = NULL;

// Insert a node at the beginning
void insert(int data) {
    node* newNode = new node;      // Step 1: Create new node
    newNode->info = data;          // Assign data
    newNode->next = head;          // Point new node's next to current head
    newNode->prev = NULL;          // New node is the first, so prev = NULL

    if (head != NULL) {
        head->prev = newNode;      // Set current head's prev to new node
    }

    head = newNode;                // Move head to the new node
}

// Delete node from the beginning
void delete_node() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    node* temp = head;            // Temp points to current head
    head = head->next;            // Move head to the next node

    if (head != NULL) {
        head->prev = NULL;        // Set new head's prev to NULL
    }

    delete temp;                  // Delete the old head
}

// Display list in forward direction
void display() {
    node* temp = head;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display list in reverse direction
void reverseDisplay() {
    node* temp = head;

    if (temp == NULL) {
        cout << "Reverse: List is empty" << endl;
        return;
    }

    // Move temp to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backwards
    cout << "Reverse: ";
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Dry-run friendly main function
int main() {
    // Inserting elements at the beginning
    insert(10);    // List: 10
    insert(20);    // List: 20 <-> 10
    insert(30);    // List: 30 <-> 20 <-> 10

    // Dry run: display both directions
    cout << "After Insertions:" << endl;
    display();         // Forward: 30 20 10
    reverseDisplay();  // Reverse: 10 20 30

    // Deleting a node from beginning
    delete_node();     // Removes 30

    cout << "\nAfter One Deletion:" << endl;
    display();         // Forward: 20 10
    reverseDisplay();  // Reverse: 10 20

    // Another insertion
    insert(40);        // List: 40 <-> 20 <-> 10

    cout << "\nAfter Inserting 40 at Beginning:" << endl;
    display();         // Forward: 40 20 10
    reverseDisplay();  // Reverse: 10 20 40

    return 0;
}
