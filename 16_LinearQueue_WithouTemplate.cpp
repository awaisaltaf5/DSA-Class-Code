#include <iostream>
using namespace std;

class QueueType {
public:
    QueueType(int max);     // Constructor
    ~QueueType();           // Destructor
    void MakeEmpty();       // Reset the queue
    bool IsEmpty() const;   // Check if empty
    bool IsFull() const;    // Check if full
    void Enqueue(int newItem); // Add element
    void Dequeue();         // Remove element
    int peek() const;       // View front element
    void Display() const;   // Display all elements

private:
    int front, rear;
    int* items;
    int maxQue;
};

// Constructor
QueueType::QueueType(int max) {
    maxQue = max;
    front = -1;
    rear = -1;
    items = new int[maxQue];
}

// Destructor
QueueType::~QueueType() {
    delete[] items;
}

// Make queue empty
void QueueType::MakeEmpty() {
    front = -1;
    rear = -1;
}

// Check if queue is empty
bool QueueType::IsEmpty() const {
    return (front == -1 || front > rear);
}

// Check if queue is full
bool QueueType::IsFull() const {
    return (rear == maxQue - 1);
}

// Enqueue function
void QueueType::Enqueue(int newItem) {
    if (IsFull()) {
        cout << "Queue is full. Cannot enqueue " << newItem << endl;
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    items[rear] = newItem;
}

// Dequeue function
void QueueType::Dequeue() {
    if (IsEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// Peek function
int QueueType::peek() const {
    if (IsEmpty()) {
        cout << "Queue is empty. No front element." << endl;
        return -1;
    }
    return items[front];
}

// Display function
void QueueType::Display() const {
    if (IsEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << items[i] << " ";
    cout << endl;
}

// Main function to test the queue
int main() {
    QueueType queueInt(5);

    cout << "Initial state:" << endl;
    queueInt.Display();

    cout << "\nEnqueue operations:" << endl;
    queueInt.Enqueue(10);
    queueInt.Enqueue(20);
    queueInt.Enqueue(30);
    queueInt.Enqueue(40);
    queueInt.Enqueue(50);
    queueInt.Enqueue(60); // Queue full
    queueInt.Display();

    cout << "\nPeek front element: " << queueInt.peek() << endl;

    cout << "\nDequeue operations:" << endl;
    queueInt.Dequeue();
    queueInt.Display();
    queueInt.Dequeue();
    queueInt.Dequeue();
    queueInt.Dequeue();
    queueInt.Dequeue();
    queueInt.Dequeue(); // Queue empty
    queueInt.Display();

    cout << "\nTesting MakeEmpty function:" << endl;
    queueInt.Enqueue(100);
    queueInt.Enqueue(200);
    queueInt.Display();
    queueInt.MakeEmpty();
    queueInt.Display();

    return 0;
}
