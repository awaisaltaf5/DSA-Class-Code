#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *arr;
    int top;
    int capacity;

public:
    Stack(int size = 20)
    {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(T x)
    {
        if (isFull())
        {
            cout << "The stack is full. Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty. Nothing to pop." << endl;
            return T();
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i]; 
        }
        cout << endl;
    }
};

int main()
{
    Stack<char> stackA, stackB, stackC;
    string firstName, middleName, lastName;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your middle name: ";
    cin >> middleName;
    cout << "Enter your last name: ";
    cin >> lastName;

    for (int i = 0; i < firstName.length(); i++)
    {
        stackA.push(firstName[i]);
    }
    for (int i = 0; i < middleName.length(); i++)
    {
        stackB.push(middleName[i]);
    }
    for (int i = 0; i < lastName.length(); i++)
    {
        stackC.push(lastName[i]);
    }

    cout << "\nPrinting names in last-middle-first order:\n";

    cout << "Last Name: ";
    stackC.display();

    cout << "Middle Name: ";
    stackB.display();

    cout << "First Name: ";
    stackA.display();

    return 0;
}
