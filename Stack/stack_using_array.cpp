#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *s; // pointer to create array dynamically
};

int stack_full(stack st)
{
    return st.top == st.size - 1;
}

int stack_empty(stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

void push(stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        cout << "stack full";
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
    cout << "\npushed element is : " << x;
}

void pop(stack *st)
{
    int x;
    if (st->top == -1)
    {
        cout << "stack empty";
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    cout << "popped element is : " << x;
}

void display(stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << "\n"
             << st.s[i];
    }
    cout << "\n";
}

int stackTop(stack st)
{
    if (!(st.top == -1))
    {
        return st.s[st.top];
    }
    return -1;
}

// finding element at given position
int peek(stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0)
    {
        cout << "invalid position";
    }
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}
int main()
{
    struct stack st;
    cout << "enter size of stack : ";
    cin >> st.size;
    st.s = new int[st.size];
    st.top = -1;
    push(&st, 10);
    push(&st, 30);
    cout << "\nelements are: ";
    display(st);
    // pop(&st);
    cout << "\nStack Top is: " << stackTop(st);

    cout << "\nElement is: " << peek(st, 1);

    // cout << stack_full(Stack st);
    // cout << stack_empty(Stack st);
    return 0;
}
