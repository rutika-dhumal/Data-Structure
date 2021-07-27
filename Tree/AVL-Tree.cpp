#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    int height; // get height of left and right subtree
    struct Node *rchild;
} *root = NULL;

// calculating height of nodes

int Nodeheight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0; // to check p is not null and p->lchild is there then take height of p->lchild otherwise height should be taken as 0
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

// functions to find balanced factor
int balancedFactor(Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0; // to check p is not null and p->lchild is there then take height of p->lchild otherwise height should be taken as 0
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

struct Node *LLRotation(Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;

    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);
    if (root == p)
        root = pl;
    return pl;
}

struct Node *LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->rchild;
    p->lchild = plr->lchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);
    plr->height = Nodeheight(plr);

    if (p == root)
    {
        root = plr;
    }
    return plr;
}
struct Node *RRRotation(Node *p)
{
    struct Node *pl = p->rchild;
    struct Node *pll = pl->lchild;
    pl->lchild = p;
    p->lchild = pll;

    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}
struct Node *RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = prl->lchild;
    p->rchild = prl->lchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = Nodeheight(p);
    pr->height = Nodeheight(pr);
    prl->height = Nodeheight(prl);

    if (p == root)
    {
        root = prl;
    }
    return prl;
}

Node *insert(Node *p, int key)
{
    Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
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

    p->height = Nodeheight(p); // updating height of each node

    // check balance factor

    if (balancedFactor(p) == 2 && balancedFactor(p->lchild) == 1)
        return LLRotation(p);

    else if (balancedFactor(p) == 2 && balancedFactor(p->lchild) == -1)
        return LRRotation(p);

    else if (balancedFactor(p) == -2 && balancedFactor(p->lchild) == -1)
        return RRRotation(p);

    else if (balancedFactor(p) == 2 && balancedFactor(p->lchild) == 1)
        return RLRotation(p);

    return p;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->lchild);
        cout << "\n"
             << root->data;
        inOrder(root->rchild);
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
        if (Nodeheight(p->lchild) > Nodeheight(p->rchild))
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

    p->height = Nodeheight(p); // updating height of each node

    // check balance factor

    if (balancedFactor(p) == 2 && balancedFactor(p->lchild) == 1)
        return LLRotation(p);

    else if (balancedFactor(p) == 2 && balancedFactor(p->lchild) == -1)
        return LRRotation(p);

    else if (balancedFactor(p) == -2 && balancedFactor(p->lchild) == -1)
        return RRRotation(p);

    else if (balancedFactor(p) == 2 && balancedFactor(p->lchild) == 1)
        return RLRotation(p);

    return p;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

int main()
{
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 2);

    inOrder(root);
    // preOrder(root);
    cout
        << "\n";

    Delete(root, 5);

    cout << "\n";
    inOrder(root);
    return 0;
}