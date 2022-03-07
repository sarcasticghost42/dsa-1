#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int coeff;
    int xexpo;
    int yexpo;
    int zexpo;
    node *next;
    node(){};
    node(int c, int x, int y, int z)
    {
        coeff = c;
        next = 0;
        xexpo = x;
        yexpo = y;
        zexpo = z;
    }
};

node *insert(int c, int x, int y, int z, node *h)
{
    node *term = new node(c, x, y, z);

    if (!h)
    {
        h = term;
        return h;
    }

    node *it = h;
    if (x > it->xexpo)
    {
        term->next = h;
        h = term;
        return h;
    }
    else
    {
        while (it->next != 0 && it->next->xexpo > x)
        {
            it = it->next;
        }
        term->next = it->next;
        it->next = term;
        return h;
    }
}

node *create(node *h)
{
    int n;
    cout << "\nEnter no. of terms : ";
    cin >> n;
    int c, x, y, z;
    for (int i = 0; i < n; i++)
    {
        cout << "coeff: ";
        cin >> c;
        cout << "x power y power z power: ";
        cin >> x;
        cin >> y;
        cin >> z;
        h = insert(c, x, y, z, h);
    }
    return h;
}

node *add(node *h1, node *h2)
{
    node *res = 0;
    while (h1 && h2)
    {
        if (h1->xexpo == h2->xexpo && h2->yexpo == h1->yexpo && h1->zexpo == h2->zexpo)
        {
            res = insert(h1->coeff + h2->coeff, h1->xexpo, h1->yexpo, h1->zexpo, res);
            h1 = h1->next;
            h2 = h2->next;
        }
        else if (h1->xexpo + h1->yexpo + h1->zexpo > h2->xexpo + h2->yexpo + h2->zexpo)
        { 
            res = insert(h1->coeff, h1->xexpo, h1->yexpo, h1->zexpo, res);
            h1 = h1->next;
        }
        else if (h1->xexpo + h1->yexpo + h1->zexpo < h2->xexpo + h2->yexpo + h2->zexpo)
        {
            res = insert(h2->coeff, h2->xexpo, h2->yexpo, h2->zexpo, res);
            h2 = h2->next;
        }
        else if (h1->xexpo + h1->yexpo + h1->zexpo == h2->xexpo + h2->yexpo + h2->zexpo)
        {
            res = insert(h1->coeff, h1->xexpo, h1->yexpo, h1->zexpo, res);
            h1 = h1->next;
            res = insert(h2->coeff, h2->xexpo, h2->yexpo, h2->zexpo, res);
            h2 = h2->next;
        }
    }
    
    while (h1 || h2)
    {
        if(h1)
        {
            res = insert(h1->coeff + h2->coeff, h1->xexpo, h1->yexpo, h1->zexpo, res);
            h1 = h1->next;
        }
        if(h2)
        {
             res = insert(h2->coeff, h2->xexpo, h2->yexpo, h2->zexpo, res);
            h2 = h2->next;
        }
    }
    
    return res;
}

void display(node *p)
{
    while (p)
    {
        cout << p->coeff << "x^(" << p->xexpo << ")y^(" << p->yexpo << ")z^(" << p->zexpo<<")";
        if (p->next != 0 && p->next->coeff > 0)
            cout << " + ";
        p = p->next;
    }
}

int main()
{
    node *poly1 = 0;
    poly1 = create(poly1);
    cout<<"\n\tf(x) : ";
    display(poly1);

    node *poly2 = 0;
    poly2 = create(poly2);
    cout<<"\n\tg(x) : ";
    display(poly2);

    node *poly3 = 0;
    poly3 = add(poly1, poly2);
    cout<<"\n\n\tp(x) = f(x) + g(x) : ";
    display(poly3);

    return 0;
}