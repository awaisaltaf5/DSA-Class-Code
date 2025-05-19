#include <iostream>  // Required for input/output operations
using namespace std; // Avoids having to prefix std:: to standard objects like cout, cin

// Define a struct to represent a task in a linked list
struct taskNode {
    string taskName;          // Name of the task
    string taskDescription;   // Description of the task
    taskNode* link;           // Pointer to the next node (task) in the list
};

// Global variables
int count = 0;               // To keep track of the number of tasks
taskNode* head = NULL;       // Points to the first task in the list (initially empty)

// Function to add a task to the end of the linked list
void addTask(string name, string description) {
    // Create a new node dynamically
    taskNode* newNode = new taskNode;
    newNode->taskName = name;                // Set the task name
    newNode->taskDescription = description;  // Set the task description
    newNode->link = NULL;                    // Since it’s the last node, link is NULL

    // If the list is empty, make newNode the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Otherwise, traverse to the end and add newNode there
        taskNode* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode; // Link last node to newNode
    }

    count++; // Increase the count of tasks
}

// Function to remove a task based on its name
void removeTask(string name) {
    // If the list is empty
    if (head == NULL) {
        cout << "No tasks to remove." << endl;
        return;
    }

    // Start traversing the list
    taskNode* temp = head;
    taskNode* prev = NULL;

    // Loop to find the task with the given name
    while (temp != NULL && temp->taskName != name) {
        prev = temp;          // Store the previous node
        temp = temp->link;    // Move to the next node
    }

    // If task was not found
    if (temp == NULL) {
        cout << "Task not found." << endl;
        return;
    }

    // If the task to be deleted is the head node
    if (prev == NULL) {
        head = head->link;  // Move head to the next node
    } else {
        prev->link = temp->link; // Bypass the current node
    }

    delete temp; // Free the memory of the node
    count--;     // Decrease the count of tasks
    cout << "Task removed successfully." << endl;
}

// Function to display all tasks in the list
void displayTasks() {
    if (head == NULL) {
        cout << "No tasks available." << endl;
        return;
    }

    // Traverse the list and print each task
    taskNode* temp = head;
    while (temp != NULL) {
        cout << "Task Name: " << temp->taskName << endl;
        cout << "Task Description: " << temp->taskDescription << endl;
        temp = temp->link;
    }
}

// Function to display tasks in FIFO (First In First Out) order
// (Same as displayTasks in a singly linked list)
void fifoTask() {
    if (head == NULL) {
        cout << "No tasks available." << endl;
        return;
    }

    // Traverse and print the tasks
    taskNode* current = head;
    while (current != NULL) {
        cout << "Task: " << current->taskName << " - " << current->taskDescription << endl;
        current = current->link;
    }
}

// Main function to run the Task Management System
int main() {
    int choice;              // Variable to store user's menu choice
    string name, description; // For storing task name and description

    // Menu loop runs until user chooses to exit
    do {
        // Display menu
        cout << "\nTask Management System" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. FIFO Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;       // Get user input
        cin.ignore();        // ***IMPORTANT***
                             // This ignores the newline character left in the input buffer by `cin`.
                             // Without this, getline() would read an empty line.

        switch (choice) {
            case 1:
                // Add a new task
                cout << "Enter task name: ";
                getline(cin, name); // Use getline to accept spaces
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(name, description); // Call addTask function
                break;
            case 2:
                // Remove an existing task
                cout << "Enter task name to remove: ";
                getline(cin, name);
                removeTask(name); // Call removeTask function
                break;
            case 3:
                // Display all tasks
                displayTasks(); // Call displayTasks function
                break;
            case 4:
                // FIFO Display (same as normal display for this structure)
                fifoTask(); // Call fifoTask function
                break;
            case 5:
                // Exit the program
                cout << "Exiting..." << endl;
                break;
            default:
                // If the user enters an invalid option
                cout << "Invalid choice." << endl;
        }
    } while (choice != 5); // Loop continues until user selects "Exit"

    return 0; // Program ends
}
