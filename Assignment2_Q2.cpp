#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

node *head = NULL;

void insertBeg(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->link = head;
    head = newNode;
}

void display(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}

void bubbleSort()
{
    if (head == NULL)
        return;

    bool swapped;
    node *current;
    node *lastSorted = NULL;

    do
    {
        swapped = false;
        current = head;

        while (current->link != lastSorted)
        {
            if (current->data > current->link->data)
            {
                int temp = current->data;
                current->data = current->link->data;
                current->link->data = temp;
                swapped = true;
            }
            current = current->link;
        }
        lastSorted = current;
    } while (swapped);
}

int main()
{
    int values[] = {5, 3, 8, 1, 4};
    for (int i = 0; i < 5; i++)
    {
        insertBeg(values[i]);
    }

    cout << "The original values: ";
    display(head);

    bubbleSort();

    cout << "The sorted values: ";
    display(head);

    return 0;
}
