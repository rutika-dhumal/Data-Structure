#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// create linked list
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
// for creating second list
void create2(int B[], int n)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// to display linked list
void display(struct Node *p)
{
    cout << "\n";
    while (p != NULL)
    {
        cout << " " << p->data;
        p = p->next;
    }
}

// to display linked list using recursion
void display1(struct Node *p)
{
    if (p != NULL)
    {
        cout << " " << p->data;
        display1(p->next);
    }
}

// to display reverse linked list using recursion
void reverse(struct Node *p)
{
    if (p != NULL)
    {
        reverse(p->next);
        cout << " " << p->data;
    }
}

// to count no. of elemeents in linked list
int count(struct Node *p)
{
    int cnt = 0;
    while (p != NULL)
    {
        //cout << " " << p->data;
        cnt++;
        p = p->next;
    }
    return cnt;
}

// sum of all elements in linked list
void sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    cout << "sum is : " << sum;
}

// to get maximum element from linked list
int max(struct Node *p)
{
    int max = 0;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// to serach element from linked list
void search(struct Node *p)
{
    int ser;
    cout << "enter element to be search : ";
    cin >> ser;

    while (p != NULL)
    {
        if (p->data == ser)
        {
            cout << "element found";
        }
        p = p->next;
    }
}

// u can do it in this way also using recursion
Node *search1(struct Node *p)
{
    int ser;
    cout << "enter element to be search : ";
    cin >> ser;
    if (p == NULL)
    {
        return NULL;
    }
    if (ser == p->data)
    {
        return p;
    }
    return (search1, p->next);
}

// inserting in linked list
void insert(Node *p, int pos, int x)
{

    int i;
    if (pos < 0 || pos > count(p)) // to check if index is not valid
    {
        cout << "incorrect index";
        // return;
    } // else index is valid

    Node *t = new Node;
    t->data = x;
    if (pos == 0) // if it is 0 position
    {
        t->next = first;
        first = t;
    }
    else // else position > 0
    {
        for (i = 0; i < pos - 1 && p != NULL; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// inserting at last only
void insert(int x)
{
    Node *last;
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

// insert in sorted linked list
void insert_ll(Node *p, int x)
{
    Node *t, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p != NULL && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// delete node

int delete_node(Node *p, int pos)
{
    Node *q = NULL;
    int i, x = -1;
    if (pos < 1 || pos > count(p))
    {
        return -1;
    }
    if (pos == 1)
    {
        q = first;           // make q as first node
        first = first->next; // move first
        x = q->data;         // take data first's data into x
        delete q;            // free the space
        return x;            // return the deleted element
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

// to check whether the linked list is sorted or not
int sorted_ll(Node *p)
{
    int x = -1, i;
    p = first;

    while (p != NULL) // to check upto p is not equal to null
    {

        if (p->data < x) // if data inside p is less than x then list is not sirted
        {
            return false;
        }
        x = p->data; // take the node data inside x
        p = p->next; // move p
    }

    return true; // if data is sorted
}

// remove duplicate elements

void duplicate(Node *p)
{
    p = first;
    Node *q = p->next; // make q as p ->next
    while (q != NULL)  // do it until q is not equal to null
    {
        if (p->data != q->data) // if p's and q's data is not matched
        {
            p = q;       // assign q value to p
            q = q->next; // move q
        }
        else // if value match
        {
            p->next = q->next;
            cout << "\ndeleted element is: " << q->data;
            delete q;    // delete q which is duplicate value
            q = p->next; // make that q to the p->next to check further elements
        }
    }
}

// reverse ll
void reverse_ll(Node *p)
{
    Node *q = NULL, *r = NULL;
    p = first;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// using recursion  reverse list
void Reverse3(struct Node *p)
{
    struct Node *q;
    if (p)
    {
        Reverse3(p);
        p = p->next;
        p->next = q;
    }
    else
        first = q;
}

// concanetation of 2 linked list it doesnt require sorted ll it is just ll1+ll2
void concat(Node *A, Node *B)
{
    //Node *A;
    // A = first;
    // B = second;
    while (A->next != NULL)
    {
        A = A->next;
    }
    A->next = B;
    B = NULL; // removing B from list
}

//merging a linked list it requires sorted ll and give results in sorted order
void merge(Node *A, Node *B)
{
    Node *last;

    if (A->data < B->data)
    {
        third = last = A;
        A = first->next;
        third->next = NULL;
    }
    else
    {
        third = last = B;
        B = B->next;
        third->next = NULL;
    }
    while (A != NULL && B != NULL)
    {
        if (A->data < B->data)
        {
            last->next = A;
            last = A;
            A = A->next;
            last->next = NULL;
        }
        else
        {
            last->next = B;
            last = B;
            B = B->next;
            last->next = NULL;
        }
    }
    if (A != NULL)
    {
        last->next = A;
    }
    else
    {
        last->next = B;
    }
}

int main()
{

    int A[5] = {1, 3, 9, 10, 11};

    // int B[2] = {2, 5};
    create(A, 5);
    // create2(B, 2);
    // insert(first, 8, 10);

    // create a list using insert
    // insert(first, 0, 1);
    // insert(first, 1, 3);
    // insert(first, 2, 5);

    // insert at last
    // insert(4);
    // insert(5);

    // insert_ll(first, 1);

    // delete_node(first, 1);
    // delete_node(first, 3);
    // cout << sorted_ll(first);
    // duplicate(first);

    // reverse(first);
    // Reverse3(first);

    // concat(first, second);

    // merge(first, second);

    display(first);

    // display1(first);
    // reverse(first);
    // cout << "count is: " << count(first);
    // sum(first);
    // cout << "maximum number is : " << max(first);
    // cout << search1(first);
    return 0;
}