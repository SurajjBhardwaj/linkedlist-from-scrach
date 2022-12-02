#include<iostream>
using namespace std;

struct Node{

int data;
struct Node *next;

}*first=NULL;

int count(struct Node *p){
int count=1;
while (p)
{
    count++;
    p=p->next;

}

return count;
}

void Insert(struct Node *p,int pos,int value){

if(pos<0 || pos>count(first)){
    cout<<"Invalid position"<<endl;
}


p=first;
struct Node *last,*t=new Node;
t->data=value;
t->next=NULL;

if(pos==0){


first=t;

}
else{

for(int i=0;i<pos-1;i++){

p=p->next;


}
t->next=p->next;
p->next=t;
}



}

void display(struct Node *p){
    cout<<"your LL is ";
while(p){

cout<<"->"<<p->data;
p=p->next;

}
}

void InsertS(struct Node *p,int data){

if(p==NULL){
p->data=data;
p->next=NULL;
}
struct Node *t,*q=NULL;
t=new Node;
t->data=data;
t->next=NULL;

while (p && p->data<data)
{
    /* code */
    q=p;
    p=p->next;
}
t->next=q->next;
q->next=t;
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


int main(){
    Insert(first,0,1);
    InsertS(first,10);
    InsertS(first,12);
    SIns(first,0);
    display(first);






    return 0;
}