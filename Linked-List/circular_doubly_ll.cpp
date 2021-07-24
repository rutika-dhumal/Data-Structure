#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
} *first = NULL, *last = NULL;

// create
void create(int A[], int n)
{
    int i;
    Node *t, *p;
    first = new Node;
    first->data = A[0];
    first->prev = first;
    first->next = first;
    p = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        p->next = t;
        t->prev = p;
        t->next = first;
        first->prev = t;

        p = t;
    }
}

void display(Node *p)
{
    do
    {
        cout << " " << p->data;
        p = p->next;
    } while (p != first);
}

void insert(Node *p, int pos, int x)
{
    Node *t;

    if (pos == 1) // if it is first node
    {
        t = new Node;
        t->data = x;
        t->next = first;
        t->prev = first;

        while (p->next != first)
        {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
        first = t;
    }
    else // other positions
    {
        int i;
        for (i = 1; i < pos - 1; i++)
        {

            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int delete_node(Node *p, int pos)
{
    int x;
    Node *t;
    Node *q;

    if (pos == 1) // if it is first node
    {
        t = first;
        x = t->data;
        q = first->prev;
        first = first->next;
        q->next = first;
        first->prev = q;
        delete t;
    }

    else // other positions   ///  its incomplete
    {
        int i;
        for (i = 1; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    create(A, 5);
    // insert(first, 6, 7);
    delete_node(first, 2);
    display(first);
    return 0;
}