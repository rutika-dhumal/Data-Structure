#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
struct Node *root = NULL;
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Enter root value: "); // take data inside x
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node)); // create root node
    root->data = x;
    root->lchild = root->rchild = NULL; // make root's left and right as null
    enqueue(&q, root);                  // enqueue root data into queue
    while (!isEmpty(q))                 // if q is not empty
    {
        p = dequeue(&q);                            // dequeue q and assign it to p
        printf("enter left child of %d ", p->data); // for its left child
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct
                                             Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t); // enqueue t
        }
        printf("enter right child of %d ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct
                                             Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void Preorder(struct Node *p)
{
    if (p) // if p is not equal to null
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int count(struct Node *root)
{
    if (root)
    {
        return count(root->lchild) + count(root->rchild) + 1;
    }
    return 0;
}

// if (p->lchild == NULL && p->rchild == NULL)  -- for exactly degree 0
// if(p->lchild != NULL && p->rchild != NULL)  -- for exactly degree 2
// if(p->lchild != NULL || p->rchild != NULL)  -- for degree 1 or 2
// if((p->lchild != NULL && p->rchild == NULL)  ||(p->lchild == NULL && p->rchild != NULL))  -- for exactly degree 1

// count of leaf node whose degree is 0
int count_leaf(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count_leaf(p->lchild);
        y = count_leaf(p->rchild);

        if (p->lchild == NULL && p->rchild == NULL) // if(p->lchild != NULL && p->rchild != NULL) -- for counting nodes which has degree 2
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
    {
        return 0;
    }
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}
int main()
{
    Treecreate();
    printf("\nPre Order: ");
    Preorder(root);

    printf("\nIn Order: ");
    Inorder(root);

    printf("\nPost Order:");
    Postorder(root);

    printf("\nCount is :%d ", count(root));
    printf("\nHeight is:%d", height(root));

    printf("\nCount of leaf node is:%d", count_leaf(root));

    return 0;
}
