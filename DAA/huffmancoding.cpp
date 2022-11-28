#include<bits/stdc++.h>
using namespace std;
struct node{
    int freq;
    char data;
    const node *child0,*child1;
    node(char d,int f=-1){
        data=d;
        freq=f;
        child0=NULL;
        child1=NULL;
    }
    node(node* n1,node*n2){
        data=0;
        freq=n1->freq+n2->freq;
        child0=n1;
        child1=n2;
    }
    bool operator <(const node &a) const{
        return freq>a.freq;
    }
    void traverse(string code="") const{
        if(child0!=NULL){
            child0->traverse(code+'0');
            child1->traverse(code+'1');
        }
        else{
            cout<<"Data : "<<data<<", Frequency: "<<freq<<", Code: "<<code<<endl;
        }
    }
};
void huffmanCoding(string str){
    priority_queue<node> qu;
    unordered_map<char,int> frequency;
    for(int i=0;i<str.size();i++){
        frequency[str[i]]++;
    }
    for(auto  x: frequency){
        qu.push(node(x.first,x.second));
    }
    while(qu.size() >1){
        node *c0= new node(qu.top());
        qu.pop();
        node *c1=new node(qu.top());
        qu.pop();
        qu.push(node(c0,c1));
    }
    cout<<"The Huffman Code : "<<endl;
    qu.top().traverse();
}
int main(){
    string str = "ACCEBFFFFAAXXBLKE";
    huffmanCoding(str);
}