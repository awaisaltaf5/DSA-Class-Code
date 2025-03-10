// Linear Queue Implementation in C++
// A linear queue is a data structure that follows the FIFO (First In, First Out) principle.
// In this implementation, we use an array to store elements, and two pointers (front and rear) to manage the queue.
// - `Enqueue`: Adds an element to the rear of the queue.
// - `Dequeue`: Removes an element from the front of the queue.
// - `Peek`: Retrieves the front element without removing it.
// - `Display`: Shows all elements in the queue.
// - `IsEmpty`: Checks if the queue is empty.
// - `IsFull`: Checks if the queue is full.

#include <iostream>
using namespace std;

// Template class for Queue
// This class implements a linear queue using an array
// A queue follows FIFO (First In First Out) principle

// The 'template <class T>' allows this class to work with any data type
// The '::' (scope resolution operator) is used to define functions outside the class
// '~' (tilde) is used in the destructor to free allocated memory
// 'const' ensures the function does not modify any class member variables

template <class T>
class QueueType
{
public:
    QueueType(int max); // Constructor to initialize queue
    ~QueueType(); // Destructor to free memory
    void MakeEmpty(); // Function to reset the queue
    bool IsEmpty() const; // Check if queue is empty
    bool IsFull() const; // Check if queue is full
    void Enqueue(T newItem); // Add an element to the queue
    void Dequeue(); // Remove an element from the queue
    T peek() const; // View the front element without removing it
    void Display() const; // Display all elements in the queue

private:
    int front, rear; // Front and rear pointers for the queue
    T *items; // Dynamic array to hold queue elements
    int maxQue; // Maximum size of the queue
};

// Constructor: Initializes the queue with given size
template <class T>
QueueType<T>::QueueType(int max)
{
    maxQue = max;
    front = -1; // Queue is initially empty
    rear = -1;
    items = new T[maxQue]; // Dynamically allocate memory for queue
}

// Destructor: Frees allocated memory
template <class T>
QueueType<T>::~QueueType()
{
    delete[] items; // Delete the dynamically allocated array
}

// Make queue empty by resetting front and rear
template <class T>
void QueueType<T>::MakeEmpty()
{
    front = -1;
    rear = -1;
}

// Check if queue is empty
template <class T>
bool QueueType<T>::IsEmpty() const
{
    return (front == -1 || front > rear);
}

// Check if queue is full
template <class T>
bool QueueType<T>::IsFull() const
{
    return (rear == maxQue - 1);
}

// Enqueue function
template <class T>
void QueueType<T>::Enqueue(T newItem)
{
    if (IsFull())
    {
        cout << "Queue is full. Cannot enqueue " << newItem << endl;
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    items[rear] = newItem;
}

// Dequeue function
template <class T>
void QueueType<T>::Dequeue()
{
    if (IsEmpty())
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

// Peek function
template <class T>
T QueueType<T>::peek() const
{
    if (IsEmpty())
    {
        cout << "Queue is empty. No front element." << endl;
        return T();
    }
    return items[front];
}

// Display function
template <class T>
void QueueType<T>::Display() const
{
    if (IsEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << items[i] << " ";
    cout << endl;
}

// Main function: Demonstrates all possible queue operations
int main()
{
    QueueType<int> queueInt(5); // Create queue with max size 5

    cout << "Initial state:" << endl;
    queueInt.Display();

    cout << "\nEnqueue operations:" << endl;
    queueInt.Enqueue(10);
    queueInt.Enqueue(20);
    queueInt.Enqueue(30);
    queueInt.Enqueue(40);
    queueInt.Enqueue(50);
    queueInt.Enqueue(60); // This should display "Queue is full"
    queueInt.Display();

    cout << "\nPeek front element: " << queueInt.peek() << endl;

    cout << "\nDequeue operations:" << endl;
    queueInt.Dequeue();
    queueInt.Display();
    queueInt.Dequeue();
    queueInt.Dequeue();
    queueInt.Dequeue();
    queueInt.Dequeue();
    queueInt.Dequeue(); // This should display "Queue is empty"
    queueInt.Display();

    cout << "\nTesting MakeEmpty function:" << endl;
    queueInt.Enqueue(100);
    queueInt.Enqueue(200);
    queueInt.Display();
    queueInt.MakeEmpty();
    queueInt.Display();

    return 0;
}