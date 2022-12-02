   
   /* The whole linkedlist */
#include<iostream>
using namespace std;

struct Node{
	public:
	int data;
	struct Node *next;
}*first=NULL;
 
 
 /* 
 
 this function create will convert the array into a linked list without returning anything.
 it is important logic 
 
 */
void create(int arr[],int n){
	
	int i;
	struct Node *temp,*last;
	first=new Node;
	first->data=arr[0];
	first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++){
		temp=new Node;
		temp->data=arr[i];
		temp->next=NULL;
		
		last->next=temp;
		last=temp;
		
	}
}

/* this is a iterative method  to display a linked list */

void display(struct Node *s){
	
	cout<<"your linkedlist is : ";
	while(s!=NULL){
		cout<<s->data<<"->";
	    s=s->next;
	    
	    if(s->next==NULL){
			cout<<s->data<<endl;
			s=s->next;
		}
			}
	
}

/* this is a recursive function to display a linked list */

void displayR(struct Node *p)
{
if(p!=NULL){
	
    displayR(p->next);
    cout<<p->data<<"->";

	/* if we want to display in the same order then just call the cout first then
	call the display function recursively but if you want to display the contacts in
	reverse order then you can use call first then display

	 like this :-
	1.to print in reverse order
	displayR(p->next);
	cout<<p->data<<"->";

	2.to print in the same order
	cout<<p->data<<"->";
	displayR(p->next);

	 */

}
}


/*
this function will count the node of the linkedlist
*/

int count(struct Node *p){


int i;
while(p !=NULL){
i++;
p=p->next;

}

return i;

}
/* writing an iterative function to find the sum of all members of the linkedlist */

int sum(struct Node *p){

int sum=0;
while(p){

sum=sum+p->data;
p=p->next;

}
return sum;

}

/* writing a recursive function to find the add of all members */
int add(struct Node *p){

int sum=0;

if(p==NULL){

	return 0;

}
 else {
	return add(p->next)+p->data;
 }

}

/* to find the maximum no in the linkedlist */

int max(struct Node *p){

int maxi= INT32_MIN;
while(p){

if(p->data > maxi){
	maxi=p->data;
}
p=p->next;
}
return maxi;
}


/* to find the key in the linkedlist */
Node * linearS(struct Node *p,int key){

while(p){

if(key == p->data){

return p;
} 

p=p->next;

}

return NULL;

}
/* Recursive method to find the key using linear search method */
Node * linearSR(struct Node *p,int key){

if(p==NULL){
	return NULL;
}
if(p->data==key){
	return p;
}
return linearSR(p->next,key);
}

/* inserting a linedlist */
void insert(struct Node *p,int index,int data){

struct Node *n;
if(index<0 || index>count(p)){
	return;
}

n=new Node;
n->data=data;

if(index==0)
{

n->next=first;
first=n;

}

else{
for(int i=0;i<index-1;i++){
p=p->next;
}
n->next=p->next;
p->next=n;
}

}




int main(){
 int n;
 cout<<"enter the size of the linkedlist ";
 cin>>n;
 cout<<endl;
 int A[n];
 for(int i=0;i<n;i++){
 	cout<<"enter "<<i+1<<"th element of the linkedlist ";
	 cin>>A[i];
	 cout<<endl;
 }
 
 create(A,n);
 cout<<"the linkedlist in the same order : ";
 display(first);
 cout<<endl;
 cout<<"the linkedlist in reverse order order : ";
  displayR(first);
 cout<<endl;
 cout<<"total nodes is : "<<count(first)<<endl;
 
cout<<"the total sum is : "<<sum(first)<<endl;
cout<<"the total sum is : "<<add(first)<<endl;
cout<<"the maximum integer of the whole linkedlist is :  "<<max(first)<<endl;

int key;
cout<<"enter the key you want to search"<<endl;
cin>>key;
cout<<"your key is found at : "<<linearSR(first,key)<<endl;

char option;
cout<<"enter 'y' if you want to insert something in the following linkedlist else 'n' "<<endl;
cin>>option;

if(option=='y'){

int index,data;
cout<<"enter index and data to insert : ";
cin>>index>>data;
insert(first,index,data);

}

 cout<<"the linkedlist in the same order : ";
 display(first);
 cout<<endl;
 cout<<"the linkedlist in reverse order order : ";
  displayR(first);
 cout<<endl;


if(option=='n'){

	cout<<endl<<"            THANK YOU               "<<endl;
}
	return 0;
}
