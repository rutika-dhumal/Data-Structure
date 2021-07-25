#include <iostream>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        cout << "queue is full";
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
int dequeue(queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout << "queue is empty";
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        cout << "\n"
             << q.Q[i];
    }
}
int main()
{
    struct queue q;
    cout << "enter size: ";
    cin >> q.size;

    q.Q = new int;
    q.front = q.rear = -1;

    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    dequeue(&q);
    display(q);

    return 0;
}