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

    if (pos == 0)
    {
        t->next = p; // t->next=first || t->next=p->next (all of these codes works fine)
        first = t;
    }

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

if (p==NULL)
{
    /* code */
    p->data=data;
    p->next=NULL;
}
    struct Node *t,*q = NULL;
    t=new Node;
    t->data=data;
    t->next=NULL;
    while (p && p->data<data)
    {
        q = p;
        p = p->next;
        /* code */
    }
   
   t->next=q->next;
   q->next=t; 
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
        }else
        {
            x=p->data;
            p=p->next;
        }
    }
    return 1;
}


void Dubblicate(struct Node *p){

struct Node *q=p->next;


while (q)
{
    /* code */
if (p->data!=q->data)
{
p=q;
q=q->next;
      

}
else
{
    p->next=q->next;
    delete(q);
    q=p->next;
}
}
}
