#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
} *first = NULL;

// create node
void create(int A[], int n)
{
    Node *t, *last;
    first = new Node;

    // for 1st element

    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) // for remaining elements
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << " " << p->data;
        p = p->next;
    }
}

// to determine legth of ll
int length(Node *p)
{
    int l = 0;
    while (p != NULL)
    {
        l++;
        p = p->next;
    }
    return l;
}

// insert

void insert(Node *p, int pos, int x)
{
    int i;
    Node *t;

    if (pos == 1)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;

        if (p->next) // if p's next is not null
            p->next->prev = t;
        p->next = t;
    }
}

// delete node
void delete_node(Node *p, int pos)
{
    p = first;
    int x;
    if (pos == 1)
    {
        first = first->next;
        first->prev = NULL;
        x = p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next; // if it is null
        if (p->next != NULL)
        {
            p->prev->next = p->prev;
        }
        x = p->data;
        delete p;
    }
}

// reverse a ll
void reverse(Node *p)
{
    Node *t;
    while (p != NULL)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;

        p = p->prev;

        if (p != NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    create(A, 5);

    // cout << "\nLength is: "
    //      << length(first);

    // insert(first, 3, 10);

    // delete_node(first, 5);

    reverse(first);
    display(first);
    return 0;
}