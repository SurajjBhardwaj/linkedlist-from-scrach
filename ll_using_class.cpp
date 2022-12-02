#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);

    void display();
    void Insert(int data);
    int length();
    ~LinkedList();
};

LinkedList::LinkedList(int A[], int n)
{

    Node *last = NULL, *t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout << "construstructer is called successfully" << endl;
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        /* code */
        first = first->next;
        delete p;
        p = first;
    }
    cout << "destructor is called successfully" << endl;
}

void LinkedList::display()
{
    Node *p = first;
    cout << "your ll is : first->";
    while (p)
    {
        cout << p->data << "->";
        p = p->next;

        if (p->next == NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    cout << endl;
}

void LinkedList::Insert(int data)
{

    Node *p;

    p = first;

    if (p == NULL)
    {
        /* code */
        p->data = data;
        p->next = NULL;
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
    cout << endl
         << "inserted " << data << " successfully " << endl;
}

int LinkedList::length()
{

    cout << endl
         << "the length of ll is: ";

    Node *p = first;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int main()
{
    int A[] = {1, 3, 5, 7, 8, 5};
    LinkedList l(A, 6);
    cout << l.length() << endl;
    l.display();
    l.Insert(11);
    cout << l.length() << endl;
    l.display();

    return 0;
}
