#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "queue full";
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    Node *p;
    int x = -1;
    if (front == NULL)
    {
        cout << "queue full";
    }
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void display()
{
    int i;
    Node *p = front;
    while (p != NULL)
    {
        cout << "\n"
             << p->data;
        p = p->next;
    }
}
int main()
{
    struct Node p;
    enqueue(4);
    enqueue(2);
    enqueue(7);

    display();
    dequeue();
    // display();
    return 0;
}