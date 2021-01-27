#include<iostream>
using namespace std;

typedef struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(Queue *q)
{
    if(q->r == q->size-1)
        return 1;
    else
        return 0;
}

int isEmpty(Queue *q)
{
    if(q->f == q->r)
        return 1;
    else
        return 0;
}
void enqueue(Queue *q)
{
    int val;
    cout<<"\nenter element: ";
    cin>>val;
    if(isFull(q))
    {
        cout<<"queue overflow";
    }
    else
    {
        q->r = q->r+1;
        q->arr[q->r]=val;
        cout<<"added element is: "<<val;
    }
}

int dequeue(Queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        cout<<"queue is empty";
    }
    else
    {
        q->f = q->f+1;
        a = q->arr[q->f];
        cout<<a;
    }
    return a;
}

int main()
{
    Queue q ;
    int a;
    q.size = 10;
    q.f = q.r = -1;
    q.arr =(int*)malloc(q.size * sizeof(int));
    int ch;
    while(1)
    {
        cout<<"\n 1.ENQUEUE 2.DEQUEUE 3.ISEMPTY 4.ISFULL 5.DISPLAY 6.EXIT"<<endl;
        cout<<"\n enter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:enqueue(&q);
                    break;

            case 2:dequeue(&q);
                    break;

            case 3:if(isEmpty(&q)){
            cout<<"\n queue is empty";
            }
            break;

            case 4:if(isFull(&q)){
            cout<<"\n queue is full";
            }
            break;

            case 5:display(&q);
                    break;
        }
    }
    return 0;
}
