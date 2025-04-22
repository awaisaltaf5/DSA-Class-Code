#include <iostream>
using namespace std;

// Structure for each node in the list
struct node {
    int info;       // The data stored in the node
    node* link;     // Pointer to the next node
};

// Global variables
node* head = NULL;  // Points to the first node in the list
int count = 0;      // Keeps track of the number of nodes

// Function to insert a node at the beginning of the list
void insertBeg(int data) {
    // Step 1: Create a new node
    node* newNode = new node;

    // Step 2: Assign the data
    newNode->info = data;

    // Step 3: Link the new node to the current head
    newNode->link = head;

    // Step 4: Update head to point to the new node
    head = newNode;

    // Step 5: Increment count
    count++;
}

// Function to insert a node at the end of the list
void insertEnd(int data) {
    // Step 1: Create a new node
    node* newNode = new node;
    newNode->info = data;
    newNode->link = NULL; // End node always points to NULL

    // Step 2: Check if list is empty
    if (head == NULL) {
        // If list is empty, new node becomes head
        head = newNode;
    } else {
        // Otherwise, traverse to the last node
        node* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }

        // Link the last node to the new node
        temp->link = newNode;
    }

    // Step 3: Increment count
    count++;
}

// Function to display the linked list
void display() {
    node* current = head;

    // Traverse and print all elements
    while (current != NULL) {
        cout << current->info << "\t";
        current = current->link;
    }

    // Print total number of nodes
    cout << endl;
    cout << "Value of count = " << count << endl;
}

// Main function with dry run explanations
int main() {
    // Dry Run Step 1:
    insertBeg(10);      // Creates: [10] -> NULL
    // head now points to 10

    // Dry Run Step 2:
    insertBeg(20);      // Creates: [20] -> [10] -> NULL
    // head now points to 20

    // Dry Run Step 3:
    insertEnd(30);      // Adds 30 to the end: [20] -> [10] -> [30] -> NULL

    // Dry Run Step 4:
    insertEnd(40);      // Adds 40 to the end: [20] -> [10] -> [30] -> [40] -> NULL

    // Final List: 20 -> 10 -> 30 -> 40

    // Display the final list and count
    cout << "Linked List: ";
    display();

    return 0;
}
