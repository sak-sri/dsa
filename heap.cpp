#include<bits/stdc++.h>
using namespace std;
void minheapify(vector<int> &v,int i,int n){
    int leftchild=2*i+1;
    int rightchild=2*i+2;
    int minindex=-1;
    if((rightchild>=n) && (v[leftchild]<v[i])){
        minindex=leftchild;
        swap(v[leftchild],v[i]);
    }else if(rightchild<n){
        if((v[leftchild]<v[rightchild]) && (v[leftchild]<v[i])){
            minindex=leftchild;
            swap(v[leftchild],v[i]);
        }else if((v[rightchild]<v[leftchild]) && (v[rightchild]<v[i])){
            minindex=rightchild;
            swap(v[rightchild],v[i]);
        }
    }
    if(minindex==-1)
        return;
    minheapify(v,minindex,n);
}
void insert(vector<int> &v,int i){
    if(i<=0)
        return;
    int parent=-1;
    if(i%2){
        parent=i/2;
    }else{
        parent=(i-1)/2;
    }
    if(v[i]<v[parent]){
        swap(v[i],v[parent]);
        insert(v,parent);
    }
}
void del(vector<int> &v,int i,int &n){
    v[i]=INT_MIN;
    insert(v,i);
    v[0]=v[n-1];
    n--;
    minheapify(v,0,n);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int startindex=-1;
    if((n-1)%2){
        startindex=(n-1)/2;
    }else{
        startindex=(n-2)/2;
    }
    for(int i=startindex;i>=0;i--){
        minheapify(arr,i,n);
    }
    return 0;
}
// insertion O(n)
// else all O(log(n))