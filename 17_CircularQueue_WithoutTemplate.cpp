#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;
    int front, rear;
    int maxSize;

public:
    CircularQueue(int size);
    ~CircularQueue();

    bool IsFull() const;
    bool IsEmpty() const;
    void Enqueue(int value);
    void Dequeue();
    int Peek() const;
    void Display() const;
};

// Constructor
CircularQueue::CircularQueue(int size) {
    maxSize = size;
    queue = new int[maxSize];
    front = -1;
    rear = -1;
}

// Destructor
CircularQueue::~CircularQueue() {
    delete[] queue;
}

// Check if the queue is full
bool CircularQueue::IsFull() const {
    return ((rear + 1) % maxSize == front);
}

// Check if the queue is empty
bool CircularQueue::IsEmpty() const {
    return (front == -1);
}

// Enqueue operation
void CircularQueue::Enqueue(int value) {
    if (IsFull()) {
        cout << "Queue is full. Cannot enqueue " << value << endl;
        return;
    }

    if (IsEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % maxSize;
    }

    queue[rear] = value;
}

// Dequeue operation
void CircularQueue::Dequeue() {
    if (IsEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    if (front == rear) {
        front = rear = -1; // Queue becomes empty
    } else {
        front = (front + 1) % maxSize;
    }
}

// Peek front element
int CircularQueue::Peek() const {
    if (IsEmpty()) {
        cout << "Queue is empty. No front element." << endl;
        return -1;
    }
    return queue[front];
}

// Display all elements
void CircularQueue::Display() const {
    if (IsEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % maxSize;
    }
    cout << endl;
}

// Main function to demonstrate circular queue
int main() {
    CircularQueue cq(5); // Circular queue of size 5

    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Enqueue(40);
    cq.Enqueue(50); // Should say full
    cq.Display();

    cq.Dequeue();
    cq.Dequeue();
    cq.Display();

    cq.Enqueue(60);
    cq.Enqueue(70); // Wraps around
    cq.Display();

    cout << "Front element: " << cq.Peek() << endl;

    return 0;
}
