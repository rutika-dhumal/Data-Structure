#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "\nstack overflow";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
    cout << "\nPushed element is: " << x;
}

int pop()
{
    Node *t;
    int x = -1;
    if (top == NULL)
    {
        cout << "\nstack is empty";
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

int peek(int pos)
{
    Node *p;
    p = top;
    for (int i = 0; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}
void display()
{
    Node *p;
    p = top;
    while (p != NULL)
    {
        cout << "\n"
             << p->data;
        p = p->next;
    }
}

int main()
{

    push(3);
    push(4);
    cout << "\npopped element is : " << pop();
    cout << "\nsearch element is : " << peek(2);

    cout << "\nThe elements are: ";
    display();
    return 0;
}