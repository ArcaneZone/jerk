#include<bits/stdc++.h>
using namespace std;

void iterativeFibonacci(int n){
    int n1=0;
    int n2=1;
    int nw;
    cout<<n1<<" "<<n2<<" ";
    for(int i=2;i<=n;i++){
        nw=n1+n2;
        n1=n2;
        n2=nw;
        cout<<nw<<" ";
    }
    cout<<endl;
}
int recursiveFibonacci(int n){
    if(n==1 || n==0){
        return n;
    }
    return  recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
}

int main(){
    int n=10;
    cout<<"iterative solution for n=10"<<endl;
    iterativeFibonacci(n);
    cout<<"Recursive solution for n=10"<<endl;
    for(int i=0;i<=n;i++){
        cout<<recursiveFibonacci(i)<<" ";
    }
    cout<<endl;
}
