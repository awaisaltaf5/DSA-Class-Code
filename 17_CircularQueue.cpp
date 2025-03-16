#include <iostream>  // Include necessary library for input-output operations
using namespace std;

// Class definition for a Circular Queue
class QueueType {
public:
    QueueType(int);  // Constructor declaration
    ~QueueType();    // Destructor declaration
    void MakeEmpty();  // Function to reset the queue
    bool IsEmpty() const;  // Function to check if queue is empty
    bool IsFull() const;   // Function to check if queue is full
    void Enqueue(int);  // Function to add an element to the queue
    void Dequeue();     // Function to remove an element from the queue
    int peek();         // Function to get the front element of the queue
    void Display();     // Function to print all elements in the queue

private:
    int front, rear;  // Variables to track front and rear positions
    int* items;       // Pointer to dynamically allocate queue array
    int maxQue;       // Maximum number of elements in the queue (capacity)
};

// Constructor: Initializes the queue with a given size
QueueType::QueueType(int max) {
    maxQue = max + 1; // One extra space to differentiate between full and empty states
    front = maxQue - 1; // Initialize front at the last index
    rear = maxQue - 1;  // Initialize rear at the last index
    items = new int[maxQue]; // Allocate memory dynamically for queue
}

// Destructor: Frees up allocated memory
QueueType::~QueueType() {
    delete[] items; // Deallocate memory
}

// Function to reset the queue to its initial empty state
void QueueType::MakeEmpty() {
    front = maxQue - 1; // Reset front position
    rear = maxQue - 1;  // Reset rear position
}

// Function to check if the queue is empty
bool QueueType::IsEmpty() const {
    return (rear == front); // If rear equals front, queue is empty
}

// Function to check if the queue is full
bool QueueType::IsFull() const {
    return ((rear + 1) % maxQue == front); // If next rear position equals front, queue is full
}

// Function to add an element to the queue
void QueueType::Enqueue(int newItem) {
    if (IsFull()) { // Check if queue is full
        cout << "Queue is full! Cannot enqueue." << endl;
        return;
    }
    rear = (rear + 1) % maxQue; // Move rear to next position in circular manner
    items[rear] = newItem; // Insert new item at rear
    cout << "Enqueued: " << newItem << endl; // Confirmation message
}

// Function to remove an element from the queue
void QueueType::Dequeue() {
    if (IsEmpty()) { // Check if queue is empty
        cout << "Queue is empty! Cannot dequeue." << endl;
        return;
    }
    cout << "Dequeued: " << items[(front + 1) % maxQue] << endl; // Show dequeued element
    front = (front + 1) % maxQue; // Move front to next position in circular manner
}

// Function to get the front element of the queue without removing it
int QueueType::peek() {
    if (IsEmpty()) { // Check if queue is empty
        cout << "Queue is empty! No front element." << endl;
        return -1; // Return an error value
    }
    return items[(front + 1) % maxQue]; // Return the front element
}

// Function to display the elements of the queue
void QueueType::Display() {
    if (IsEmpty()) { // Check if queue is empty
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    // If queue is not wrapped around
    if (rear >= front) {
        for (int i = front + 1; i <= rear; i++) // Loop from front to rear
            cout << items[i] << " ";
    } else { // If queue is wrapped around (circular behavior)
        for (int i = front + 1; i < maxQue; i++) // Loop from front to end of array
            cout << items[i] << " ";
        for (int i = 0; i <= rear; i++) // Loop from beginning of array to rear
            cout << items[i] << " ";
    }
    cout << endl;
}

// Main function to test the queue
int main() {
    QueueType q(5); // Create a queue with capacity 5

    // Checking enqueue operation
    q.Enqueue(10); // Enqueue elements
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60); // This should show queue full message
    
    q.Display(); // Display queue elements
    
    // Checking dequeue operation
    q.Dequeue(); // Dequeue two elements
    q.Dequeue();
    
    q.Display(); // Display queue elements after dequeue
    
    // Checking peek operation
    cout << "Front element: " << q.peek() << endl; // Print the front element
    
    // Emptying the queue completely
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue(); // This should show queue empty message
    
    q.Display(); // Display after emptying the queue
    
    return 0;
}


/*
### Explanation of Circular Queue:
A circular queue is an advanced version of a linear queue where the last position is connected back to the first position, forming a circle. This approach efficiently utilizes space by allowing elements to be added to the queue even when there are vacant spots at the beginning, which is not possible in a linear queue.

#### Key Concepts:
1. **Front and Rear Pointers:**
   - `front`: Represents the position before the first element of the queue.
   - `rear`: Represents the last inserted element.
2. **Circular Movement:**
   - When `rear` reaches the last index and a new element is added, `rear` moves to index `0`.
   - Similarly, when `front` reaches the last index, it moves to index `0` after a dequeue.
3. **Full and Empty Conditions:**
   - **Full Condition:** `(rear + 1) % maxQue == front`
   - **Empty Condition:** `rear == front`
4. **Efficient Space Utilization:**
   - Unlike a linear queue, a circular queue reuses empty spaces efficiently, preventing memory wastage.
*/