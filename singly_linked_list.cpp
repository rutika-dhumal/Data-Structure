#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node* getNode() // to get the node
{
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Node)); // allocating memory
    p->next = NULL;                  // making its next to NULL
    cout<<"Enter data: "<<endl;      // taking data
    cin>>p->data;
    return p;
}

Node *createNode(Node* head) // to create node
{
    Node *p = NULL , *q = NULL;
    int n;
    cout<<"Enter no. of nodes : "<<endl;  // enter nodes
    cin>>n;

    for(int i=0;i<n;i++)
    {
        p = getNode();  // taking value of getNode into p
        if(head == NULL) // checking head is null or not
        {
            head = p;    // assign value of p to head
            q = p;
        }
        else
        {
            q->next = p;  // else assign it to the next node
            q = p;
        }
    }
    return(head);
}

void displayNodes(Node* head) // display function
{
    Node* p;
    if(head!=NULL)
    {
         p = head;
        while(p != NULL) // work until p is not null
        {
            cout<<p->data<<endl;
            p = p->next;
        }
    }
    else
        cout<<"linked list is empty"<<endl;
}

Node* insertAtFirst(Node *head)  // insert node at first
{
    Node* p=NULL;
    p=getNode();
    if(head==NULL)
    {
        p->next=NULL;
        head=p;
    }
    else
    {
        p->next=head;
        head=p;
    }
    return(head);
}

Node* insertAtIndex(Node *head)
{
   Node *p , *q = NULL;
   q = head;
   p = getNode();
   int index , i = 0;
   cout<<"enter position : ";
   cin>>index;
   if(index == 1)
   {
       p->next = head;
       head = p;
   }
   else
   {
       while(i!=index-1)
        {
            q = q->next;
            i++;
        }
        p->next = q->next ;
        q->next = p;
   }
   return head;
}

Node *insertAtLast(Node *head)
{
    Node *p ,*q = NULL;
    q = head;
    p = getNode();
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next = p;
    p->next = NULL;

    return head;
}


Node* deleteAtFirst(Node* head)
{
    Node* p=NULL;
    if(head!=NULL)
    {
        p=head;
        head=head->next;
        cout<<"deleted element is "<<p->data<<endl;
        free(p);
    }
    else
        cout<<"linked list is empty"<<endl;

    return(head);
}

Node *deleteLast(Node *head)
{
    Node *p ,*q = NULL;
    p =  head;
    q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    cout<<"deleted element is: "<<q->data<<endl;
    free(q);

    return head;
}

Node *deleteIndex(Node *head)
{
    Node *p=NULL,*q=NULL,*prev=NULL;
        int pos,n=1;
        q=prev=head;
        printf("enter position:");
        scanf("%d",&pos);
        if(pos==1)
        {
            p=head;
            head=head->next;
            p->next=NULL;
            cout<<"deleted elemnt is: "<<p->data;
            free(p);

        }
        else
        {
            while(n!=pos)
            {
                prev=q;
                q=q->next;
                n++;
            }
            (prev->next)=(q->next);
            q->next=NULL;
            cout<<"deleted elemnt is : "<<q->data;
            free(q);

        }
        return head;
}


int main()
{
    Node *head = NULL;
    int ch;
    while(1)
    {
        cout<<"\n1.CREATE NODE 2.INSERT AT FIRST 3.INSERT AT INDEX 4.INSERT AT LAST 5.DELETE AT FIRST 6.DELETE AT LAST 7.DELETE AT INDEX 8.DISPLAY"<<endl;
        cout<<"\nenter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1 : head = createNode(head);
                     break;

            case 2 : head = insertAtFirst(head);
                     break;

            case 3 :  head=insertAtIndex(head);
				     break;

            case 4 :  head=insertAtLast(head);
				     break;

            case 5 : head = deleteAtFirst(head);
                     break;

            case 6 : head = deleteLast(head);
                     break;

            case 7 : head = deleteIndex(head);
                     break;

            case 8 : displayNodes(head);
                     break;

            default :
                return 0;
        }
    }
    //createNode(head);
    //displayNodes(head);
    return 0;
}
