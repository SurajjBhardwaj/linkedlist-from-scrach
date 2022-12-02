#include<iostream>
using namespace std;

struct Node{

int data;
struct Node *next;

}*first=NULL;


void Insert(struct Node *p,int pos,int value){

p=first;
struct Node *last,*t=new Node;
t->data=value;
t->next=NULL;

if(pos==0){

t->next=last;
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
while(p){

cout<<p->data<<" "<<endl;
p=p->next;

}



}




int main(){
    Insert(first,0,1);
    display(first);




    return 0;
}