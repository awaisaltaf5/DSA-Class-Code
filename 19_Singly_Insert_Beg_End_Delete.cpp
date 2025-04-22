#include <iostream>
using namespace std;

// Node structure for singly linked list
struct node {
    int info;       // Stores data
    node* link;     // Pointer to next node
};

// Global head pointer and count of nodes
node* head = NULL;
int count = 0;

// Insert at the beginning
void insertBeg(int data) {
    // Step 1: Create new node
    node* newNode = new node;
    newNode->info = data;
    
    // Step 2: Point new node to the current head
    newNode->link = head;
    
    // Step 3: Update head to new node
    head = newNode;
    
    count++;
}

// Insert at the end
void insertEnd(int data) {
    node* newNode = new node;
    newNode->info = data;
    newNode->link = NULL;

    if (head == NULL) {
        // If list is empty, new node is the head
        head = newNode;
    } else {
        node* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }

    count++;
}

// Insert in the middle (after count/2 nodes)
void insertMiddle(int data) {
    node* newNode = new node;
    newNode->info = data;
    newNode->link = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        int mid = count / 2;
        node* temp = head;
        int c = 1;

        // Traverse to the node before the mid position
        while (c != mid) {
            temp = temp->link;
            c++;
        }

        // Insert the new node after temp
        newNode->link = temp->link;
        temp->link = newNode;
    }

    count++;
}

// Delete from beginning
void deleteBeg() {
    if (head == NULL) {
        cout << "List is empty." << endl;
    } else {
        node* ptr = head;
        head = head->link;
        delete ptr;
        count--;
    }
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty." << endl;
    } else if (head->link == NULL) {
        // Only one node
        delete head;
        head = NULL;
        count--;
    } else {
        node* ptr = head;
        node* prev = NULL;

        // Traverse to last node
        while (ptr->link != NULL) {
            prev = ptr;
            ptr = ptr->link;
        }

        prev->link = NULL;
        delete ptr;
        count--;
    }
}

// Delete from middle (removes the count/2-th node)
void deleteMiddle() {
    if (head == NULL || count < 3) {
        cout << "List too short to delete from middle." << endl;
        return;
    }

    int mid = count / 2;
    node* ptr = head;
    node* prev = NULL;
    int c = 1;

    // Traverse to the mid node
    while (c != mid) {
        prev = ptr;
        ptr = ptr->link;
        c++;
    }

    // Remove the mid node
    if (prev != NULL) {
        prev->link = ptr->link;
        delete ptr;
        count--;
    }
}

// Display the list and count
void display() {
    node* current = head;
    cout << "List: ";
    while (current != NULL) {
        cout << current->info << " -> ";
        current = current->link;
    }
    cout << "NULL" << endl;
    cout << "Total Nodes: " << count << endl;
}

// Main function with dry run comments
int main() {
    // Dry Run Step 1:
    insertBeg(10);     // List becomes: 10
    // count = 1

    // Dry Run Step 2:
    insertBeg(20);     // List becomes: 20 -> 10
    // count = 2

    // Dry Run Step 3:
    insertEnd(30);     // List becomes: 20 -> 10 -> 30
    // count = 3

    // Dry Run Step 4:
    insertEnd(40);     // List becomes: 20 -> 10 -> 30 -> 40
    // count = 4

    // Dry Run Step 5:
    insertMiddle(25);  // Middle index = 4/2 = 2
                       // Insert after 2nd node: 20 -> 10 -> 25 -> 30 -> 40
    // count = 5

    display();         // Expected Output: 20 -> 10 -> 25 -> 30 -> 40

    // Deletion Section:

    deleteBeg();       // Removes 20 → New list: 10 -> 25 -> 30 -> 40
    // count = 4

    deleteEnd();       // Removes 40 → New list: 10 -> 25 -> 30
    // count = 3

    deleteMiddle();    // Removes 25 → Middle index = 3/2 = 1
                       // Remove after first node → New list: 10 -> 30
    // count = 2

    display();         // Expected Output: 10 -> 30

    return 0;
}
