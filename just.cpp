#include <bits/stdc++.h>
using namespace std;

 void display(int A[],int n){
for(int i=0;i<n;i++){
    cout<<A[i]<<" ";
}

 }


int  main(){
int A[]={2,4,6,1,6,8};
int n=sizeof(A)/4;
cout<<n<<endl;
display(A,n);

cout<<endl;
sort(A[0],A[n]);
display(A,n);

 


    return 0;
}