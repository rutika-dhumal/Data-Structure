#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
};

node *getnode()
{
    node *p = NULL;
    p = (node*)malloc(sizeof(struct node));
    cout<<"\nenter data: ";
    cin>>p->data;
    p->next = NULL;
    return p;
}
int isEmpty(node *top)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

int isFull(node *top)
{
    node *p = (node*)malloc(sizeof(struct node));
    if(p==NULL)
        return 1;
    else
        return 0;
}

node *pop(node *top)
{
    if(isEmpty(top))
    {
        cout<<"\nstack underflow";
    }
    else
    {
        node *n = top;
        top = top->next;
        cout<<"\ndeleted element is: "<<n->data<<endl;
        free(n);
    }
    return top;
}
node *push(node *top)
{
    if(isFull(top))
    {
        cout<<"\nstack overflow"<<endl;
    }
    else
    {
        node *n = NULL;
        n = getnode();
        n->next = top;
        top = n;
    }
    return top;
}

int peek(node *top)
{
    node *p = top;
    int pos;
    cout<<"\nenter position: ";
    cin>>pos;
    for(int i=0;(i<pos-1 && p!=NULL);i++)
    {
        p = p->next;
    }
    if(p!=NULL)
    {
        cout<<"\nelement is: "<<p->data;
    }
    else
    {
        cout<<"element is not found";
    }
}

int stack_top(node *top)
{
    cout<<"top element is: "<<top->data<<endl;
}

void display(node *top)
{
    node *p;
    p = top;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main()
{
    node *top = NULL;
    int ch;
    while(1)
    {
        cout<<"\n1.PUSH 2.POP 3.PEEK 4.TOP 5.DISPLAY 6.EXIT"<<endl;
        cout<<"enter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1: top = push(top);
                    break;

            case 2: top = pop(top);
                    break;

            case 3: peek(top);
                    break;

            case 4: stack_top(top);
                    break;

            case 5: display(top);
                    break;

            case 6: exit(0);
        }

    }
    return 0;
}
