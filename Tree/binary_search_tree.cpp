#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

Node *insert(Node *p, int key)
{
    Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = insert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = insert(p->rchild, key);
    }
    return t;
}

Node *search(Node *t, int key)
{

    if (t == NULL)
    {
        return NULL;
    }
    if (key == t->data)
    {
        return t;
    }
    else if (key < t->data)
    {
        return search(t->lchild, key);
    }
    else
        return search(t->rchild, key);
}

void Inorder(Node *p)
{
    if (p != NULL)
    {
        Inorder(p->lchild);
        cout << p->data;
        Inorder(p->rchild);
    }
}

int height(Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

// right most child of left subtree
Node *Inpre(struct Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

// left most child of right subtree
Node *Insucc(struct Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    cout << p->data;
    return p;
}

Node *Delete(Node *p, int key)
{
    Node *q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        delete p;
        return NULL;
    }

    // serching key
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }

    // now key is found now replace it
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
    }
    return p;
}

int main()
{
    Node *temp;
    root = insert(root, 30);
    insert(root, 25);
    insert(root, 10);
    insert(root, 27);
    insert(root, 50);
    insert(root, 45);
    insert(root, 60);
    insert(root, 65);
    cout << "\nHeight of tree: " << height(root);
    // Insucc(root);
    Delete(root, 60);

    // temp = search(root, 55);
    // if (temp != NULL)
    // {
    //     cout << "element found: " << temp->data;
    // }
    // else
    // {
    //     cout << "not found";
    // }

    return 0;
}