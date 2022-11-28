#include<bits/stdc++.h>
using namespace std;
struct Item{
    int value;
    int weight;
    Item(int v,int w){
        this->weight=w;
        this->value=v;
    }
};
bool cmp(Item a,Item b){
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W,Item arr[],int n){
    sort(arr,arr+n,cmp);
    double finalW=0.0;
    for(int i=0;i<n;i++){
        if(arr[i].weight<=W){
            W-=arr[i].weight;
            finalW+=arr[i].value;
        }
        else{
            finalW+=arr[i].value*((double)W/(double)arr[i].weight);
            break;
        }
    }
    return finalW;
}
int main(){
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << fractionalKnapsack(W, arr, N);
    return 0;
}