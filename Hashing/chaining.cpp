#include <iostream>
using namespace std;
#define size 10

struct Node
{
    int data;
    struct Node *next;
};

struct Node *chain[size];

// initializing chain with NULL
int init()
{
    int i;
    for (i = 0; i < size; i++)
        chain[i] = NULL;
}

// inserting node
void insert(int value)
{
    // creting a first node
    struct Node *p = new Node;
    p->data = value;
    p->next = NULL;

    // calculating hash
    int key = value % size;

    // check if chain[key] is empty
    if (chain[key] == NULL)
    {
        chain[key] = p;
    }

    // if it is not empty then there is collision
    else
    {
        // add node at end of chain[key]
        struct Node *temp = chain[key];

        while (temp->next) // while teemp->next is not null
        {
            temp = temp->next;
        }
        temp->next = p; // assign p to the temp->next
    }
}

// display all nodes
void display()
{
    int i;
    for (i = 0; i < size; i++)
    {
        // start from index 0
        struct Node *temp = chain[i];
        cout << "chain[" << i << "]--->";
        while (temp) // while temp is not equal to null
        {
            cout << temp->data << "--->"; // print data
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

// to search node
int search(int value)
{
    // hash function
    int key = value % size; // calculate hash

    struct Node *temp = chain[key];
    while (temp)
    {
        if (temp->data == value) // if data and value match
        {
            return 1; // then value is found
        }
        else
        {
            temp = temp->next;
        }
    }
    return 0;
}

// delete node
int Delete(int value)
{
    int key = value % size; // get hash value
    struct Node *temp = chain[key];
    Node *t;

    if (temp == chain[0])
    {
        t = temp;
        temp = temp->next;
        delete t;
        return 1;
    }
    if (temp != NULL) // if temp is not null
    {
        if (temp->data == value) // if data matched with value
        {
            t = temp;          // take data inside t
            temp = temp->next; // move temp
            delete t;          // delete that node t
            return 1;
        }
        else // if that value doesnt match
        {
            while (temp->next) // move temp
            {
                if (temp->next->data == value) // now check its value whether it is matching or not
                {
                    t = temp->next; // copy it to the t
                    temp->next = temp->next->next;
                    delete t;
                    return 1;
                }
                temp = temp->next;
            }
        }
    }
    return 0;
}

int main()
{
    //init array of list to NULL
    init();

    // insert values
    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);
    insert(25);
    insert(75);

    // searching node
    if (search(4))
    {
        cout << "value found" << endl;
    }
    else
    {
        cout << " value not found" << endl;
    }
    display();

    // deleting node
    if (Delete(5))
    {
        cout << "deleted " << endl;
    }
    else
    {
        cout << "key not present" << endl;
    }

    display();
}