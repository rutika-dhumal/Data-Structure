#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    int i;
    head = new Node;
    Node *t, *last;
    head->data = A[0];
    head->next = head;

    last = head;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    do
    {
        cout << " " << p->data;
        p = p->next;
    } while (p != head);
}

// Recursive display
void Rdisplay(Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << " " << p->data;
        Rdisplay(p->next);
    }
    flag = 0;
}

// insert
void insert(Node *p, int pos, int x)
{
    Node *t;
    if (pos == 1) // if it is first node
    {
        t = new Node;
        t->data = x;
        t->next = head;

        while (p->next != head)
        {
            p = p->next;
        }
        p->next = t;
        head = t;
    }
    else // other positions
    {
        int i;
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

// delete node
int delete_node(Node *p, int pos)
{
    int x, i;
    Node *q;
    if (pos == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < pos - 2; i++)
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
    // display(head);
    // insert(head, 1, 10);
    delete_node(head, 1);
    Rdisplay(head);

    return 0;
}
