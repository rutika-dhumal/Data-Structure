// dequeue using circular array

#include <iostream>
using namespace std;
#define size 5

class dequeue
{
private:
    int *arr;
    int front;
    int rear;

public:
    // to create array
    dequeue()
    {
        arr = new int[size];
        front = rear = -1;
    }

    int isFull();
    int isEmpty();
    void enqueue_front(int x);
    void enqueue_rear(int x);
    void dequeue_front();
    void dequeue_rear();
    void display();
};

// to check queue is full
int dequeue::isFull()
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        return 1;
    }
    return 0;
}

// to check queue is empty
int dequeue::isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

// insert from front
void dequeue::enqueue_front(int x)
{
    // to check whether queue is full or not
    if (isFull())
    {
        cout << "queue full";
    }
    else
    {
        if (front == -1)
            front = rear = 0;

        else if (front == 0)
            front = size - 1;

        else
            front--;

        arr[front] = x;
    }
}

// insert from rear
void dequeue::enqueue_rear(int x)
{
    // to check whether queue is full or not
    if (isFull())
    {
        cout << "queue full";
    }
    else
    {
        if (rear == -1)
            front = rear = 0;

        else if (rear == size - 1)
            rear = 0;

        else
            rear++;

        arr[rear] = x;
    }
}

// display elements
void dequeue::display()
{
    int i = front;
    while (i != rear)
    {
        cout << "\n"
             << arr[i];
        i = (i + 1) % size;
    }
    cout << "\n"
         << arr[rear];
}

// delete from front
void dequeue::dequeue_front()
{
    int x;
    if (isEmpty())
    {
        cout << "queue empty";
    }
    else
    {
        if (front == 0 && rear == 0)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

// delete from rear
void dequeue::dequeue_rear()
{
    int x;
    if (isEmpty())
    {
        cout << "queue empty";
    }
    else
    {
        if (front == 0 && rear == 0)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
}

int main()
{
    dequeue d;
    d.enqueue_front(3);
    d.enqueue_rear(4);

    d.dequeue_rear();
    // d.dequeue_front();
    d.display();
    return 0;
}