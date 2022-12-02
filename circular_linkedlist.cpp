#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

} *head = NULL;

void create(int A[], int n)
{
    head = new Node;
    struct Node *p = NULL, *t;

    head->data = A[0];
    head->next = head;
    p = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = p->next;
        p->next = t;
        p = t;
    }
    cout << "created all ";
}

void display(struct Node *p)
{

    do
    {

        cout << p->data << " ";
        p = p->next;

    } while (p != head);
}
int len(struct Node *p)
{

    int count = 0;
    do
    {
        count++;
        p = p->next;

    } while (p != head);
    return count;
}

void Insert(struct Node *p, int pos, int data)
{

    if (pos < 0 || pos > len(p))
    {
        cout << "invalid index" << endl;
        return;
    }

    p = head;
    struct Node *t;
    t = new Node;
    t->data = data;

    if (pos == 0)
    {

        if (p == NULL)
        {
            t->next = head;
            head = t;
        }
        else
        {

            while (p->next != head)
            {

                p = p->next;
            }

            p->next = t;
            t->next = head;
            head=t;
        }
    }

    if (pos > 0)
    {

        for (int i = 0; i < pos - 1; i++)
        {

            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p,int pos){

if(pos<0 || pos>len(p)){
    cout<<endl<<"invalid index"<<endl;
    return -1;
}
p=head;
int x;
if(pos==1){

while(p->next!=NULL){

    p=p->next;

}
x=head->data;

if(p==head){

delete head;
head=NULL;

}else{

p->next=head->next;
delete head;
head=p->next;


} 
}
else{

struct Node *q=NULL;
for(int i=0;i<pos-2;i++){

p=p->next;

}

q=p->next;
p->next=q->next;
x=q->data;
delete q;


}
return x;
}


int main()
{
    int A[] = {5, 6, 7, 9, 11};
    create(A, 5);
    display(head);
    cout<<endl<<"length of ll is "<<len(head)<<endl;
    Insert(head,2,12);
    display(head);
    cout<<endl<<"after deleting "<<Delete(head,3)<<endl;
    display(head);
    cout<<endl<<"length of ll is "<<len(head)<<endl;
    return 0;
}