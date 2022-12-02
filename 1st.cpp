#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    struct Node *next;

} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{

    int i;
    struct Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {

        t = new Node;
        t->data = A[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

// void Insert(struct Node *p,){

// struct Node *s;
// s->data

// }

void display(struct Node *p)
{

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
        /* code */
    }
    cout << endl;
}

void Rdisplay(struct Node *p)
{

    if (p != NULL)
    {
        /* code */
        cout << p->data << " ";
        Rdisplay(p->next);
    }
}

int count(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
        /* code */
    }
    return count;
}

int add(struct Node *p)
{

    int sum = 0;
    while (p != NULL)
    {

        sum = sum + p->data;
        p = p->next;
    }

    return sum;
}

int maximum(struct Node *p)
{
    int max = INT32_MIN; // how to know the minimum in the whole system
    cout << "minimum in the whole 32 bit machine is : " << max << endl;
    while (p)
    {
        /* code */
        if (p->data > max)
        {
            max = p->data;
            p->next;
            /* code */
        }
        else
        {
            p = p->next;
        }
    }

    return max;
}

int minimum(struct Node *p)
{
    int min = INT32_MAX; // Remark the point
    cout << "maximum int in 32 bit is : " << min << endl;
    while (p)
    {
        /* code */
        if (p->data < min)
        {
            min = p->data;
            p->next;
            /* code */
        }
        else
        {
            p = p->next;
        }
    }

    return min;
}

int search(struct Node *p, int key)
{

    int count = 0;
    while (p)
    {
        count++;
        if (p->data == key)
        {
            return count;
        }
        else
        {
            p = p->next;
        }

        /* code */
    }

    return -1;
}

int impsearch(struct Node *p, int key)
{

    struct Node *q = NULL;
    while (p)
    {
        /* code */
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;

            /* code */
        }

        q = p;
        p = p->next;
    }
}

void Insert(struct Node *p, int pos, int data)
{
    if (pos < 0 || pos > count(p))
    {
        return;
    }
    struct Node *t;
    t = new Node;
    t->data = data;
/*
case 1.
for before first node
*/
    if (pos == 0)
    {
        t->next = p; // t->next=first || t->next=p->next (all of these codes works fine)
        first = t;
    }
/*
case 2.
for after (pos-1)node
*/
    else
    {

        p = first;
        int i;
        for (i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SIns(struct Node *p, int data)
{

    if (p == NULL)
    {
        /* code */
        p->data = data;
        p->next = NULL;
        first=p;
    }
    struct Node *t, *q = NULL;
    t = new Node;
    t->data = data;
    t->next = NULL;
    while (p && p->data < data)
    {
        q = p;
        p = p->next;
        /* code */
    }

    t->next = q->next;
    q->next = t;
}

void Delete(struct Node *p, int pos)
{

    if (pos == 0)
    {
        first = p->next;
        int x = p->data;
        delete p;
    }
    else
    {

        struct Node *q = NULL;

        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        int x = p->data;
        cout << x << endl;
        delete p;
    }
}

int Issorted(struct Node *p)
{

    int x = INT32_MIN;
    while (p)
    {
        /* code */

        if (p->data < x)
        {
            return -1;
        }
        else
        {
            x = p->data;
            p = p->next;
        }
    }
    return 1;
}

void Dubblicate(struct Node *p)
{

    struct Node *q = p->next;

    while (q)
    {
        /* code */
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete (q);
            q = p->next;
        }
    }
}

void Reverse(struct Node *p)
{

    struct Node *q = NULL, *r = NULL;
    while (p)
    {
        /* code */
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }
    first = q;
}

void ReverseR(struct Node *q, struct Node *p)
{

    if (p != NULL)
    {
        ReverseR(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void create2(int A[], int n)
{

    int i;
    struct Node *t, *last;

    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {

        t = new Node;
        t->data = A[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

void concatnating(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        /* code */
        p = p->next;
    }
    p->next = q; // you can use p->next=second also,because second is a global variable which has a address of second ll.
    q = NULL;
}

void merging(struct Node *p, struct Node *q)
{

    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p && q)
    {

        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {

            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    while (p)
    {
        /* code */
        last->next = p;
        p = p->next;
    }
    while (q)
    {
        last->next = q;
        q = q->next;
    }
}

int isloop(struct Node *f)
{
    struct Node *p = NULL, *q = NULL;
    p = q = f;
    do
    {
        /* code */
        p = p->next;
        q = q->next;
        q != NULL ? q = q->next : NULL;
    } while (p && q);

    if (p == q)
    {
        /* code */
        return 1;
    }
    return 0;
}

int main()
{

    int A[] = {2, 4, 6, 8, 9};
    create(A, 5);
    display(first);
    cout << endl;
    int B[] = {5, 6, 7, 8, 11};
    create2(B, 5);
    display(second);
    cout << endl;

    // cout<<endl<<"after deleting dubblicate "<<endl;

    merging(first, second);
    display(third);

    cout << "is loop : " << isloop(third) << endl;
    cout << second->next->next->data << endl;
    /*
    TRICK:-
    Jis no ka data output karana ho utne bar use next next kar do,
    like in  line 455 we're printing the 3rd data of the second linked_list using three next;
    */

    // Dubblicate(first);

    // display(first);
    // cout<<endl<<"after reversing"<<endl;
    // ReverseR(NULL,first);
    // display(first);

    // Insert(first, 0, 12);
    // Insert(first, 1, 45);
    // Insert(first, 2, 75);
    // Insert(first, 3, 85);
    // SIns(first,25);
    // Insert(first,5,75);

    // display(first);

    // cout << endl;
    // cout << "no of nodes is :" << count(first) << endl;
    // cout << "the sum of all data is :" << add(first) << endl;

    // cout << "maximum from the linkedlist is : " << maximum(first) << endl;
    // cout << "minimum from the linkedlist is : " << minimum(first) << endl;
    // cout << "11 excist in our linkedlist at pos : " << search(first, 11) << endl;
    // cout << "is ll sorted: " << Issorted(first) << endl;

    // cout << endl<<"\n";

    // cout << "after deleting : ";

    // Delete(first, 3);
    // display(first);
    // cout << endl;
    // cout << "no of nodes is :" << count(first) << endl;
    // cout << "the sum of all data is :" << add(first) << endl;

    // cout << "maximum from the linkedlist is : " << maximum(first) << endl;
    // cout << "minimum from the linkedlist is : " << minimum(first) << endl;
    // cout << "11 excist in our linkedlist at pos : " << search(first, 11) << endl;
    // cout << "Is sorted: " << Issorted(first) << endl;

    return 0;
}