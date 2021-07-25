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
    if ((q->rear + 1) % q->size == q->front)
    {
        cout << "queue full";
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout << "queue empty";
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct queue q)
{
    int i = q.front + 1;
    do
    {
        cout << "\n"
             << q.Q[i];
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
}
int main()
{
    struct queue q;
    cout << "enter size : ";
    cin >> q.size;
    q.rear = q.front = 0;
    q.Q = new int;

    enqueue(&q, 5);
    enqueue(&q, 7);
    enqueue(&q, 8);

    dequeue(&q);
    display(q);
    return 0;
}