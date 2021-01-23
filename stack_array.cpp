#include<iostream>
#define max 10
using namespace std;

class Stack
{
    int top;
    int a[max];

public:
    Stack();
    bool isFull();
    bool isEmpty();
    void push(int x);
    void pop();
    void Top();
    void size_stack();
    void display();
};

Stack::Stack()   // initializing top=0 using default constructor
{
    top=0;
}

bool Stack::isFull()  // to check whether stack is full or not
{
    if(top==max)
        return true;
    else
        return false;
}

bool Stack::isEmpty()  // to check whether stack is empty or not
{
    if(top==0)
        return true;
    else
        return false;
}

void Stack::push(int x)  // to push element into stack
{
    if(isFull()){
        cout<<"stack is full"<<endl;
        return ;
    }
    else
        a[top]=x;
        cout<<"pushed element is: "<<a[top]<<endl;
        top++;
}

void Stack::pop()  // to pop element from stack
{
    if(isEmpty()){
        cout<<"stack is empty"<<endl;
        return ;
    }
    else
        top--;
        cout<<"popped element is: "<<a[top]<<endl;
}

void Stack::Top()
{
    cout<<"\n top element is : "<<a[top-1];
}

void Stack::size_stack()    // displays the size of stack
{
    cout<<"size of Stack is "<<top<<endl;
}

void Stack::display()  //display stack elements
{
    if(top==0)
    {
        cout<<"stack is empty";
        return ;
    }
    else
    {
        cout<<"\nstack elements are: ";
        for(int i=0;i<top;i++)
        {
            cout<<a[i]<<endl;
        }
    }
}

int main()
{
    Stack s;
    int ch , element  ;

    while(1)
    {
        cout<<"\n1.PUSH \n2.POP \n3.TOP \n4.ISEMPTY \n5.ISFULL \n6.SIZE \n7.DISPLAY \n8.EXIT"<<endl;
        cout<<"\n enter your choice: ";
        cin>>ch;

        if(ch==1)  //push
        {
            cout<<"enter element : "<<endl;
            cin>>element;
            s.push(element);
        }
        else if(ch==2) //pop
        {
            s.pop();
        }
        else if(ch==3) //top
        {
            s.Top();
        }
        else if(ch==4) //isempty
        {
            if(s.isEmpty()){
                cout<<"\nstack is empty";
            }
            else
                cout<<"\nstack is not empty.. you can pop elements ";
        }
        else if(ch==5)  //isfull
        {
            if(s.isFull()){
                cout<<"\nstack is full";
            }
            else
                cout<<"\nstack is not full.. you can push elements ";
        }
         else if(ch==6) //size
        {
            s.size_stack();
        }
        else if(ch==7) //display
        {
            s.display();
        }
        else
        return 0;
    }
    return 0;
}
