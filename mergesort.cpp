#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &v,int l1,int h1,int l2,int h2){
    int n1=h1-l1+1;
    int n2=h2-l2+1;
    vector<int> temp(n1+n2,0);
    vector<int> left(n1,0);
    vector<int> right(n2,0);
    for(int i=l1;i<=h1;i++){
        left[i-l1]=v[i];
    }
    for(int i=l2;i<=h2;i++){
        right[i-l2]=v[i];
    }
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            temp[k++]=left[i++];
        }else{
            temp[k++]=right[j++];
        }
    }
    while(i<n1){
        temp[k++]=left[i++];
    }
    while(j<n2){
        temp[k++]=right[j++];
    }
    for(int i=l1;i<=h2;i++){
        v[i]=temp[i-l1];
    }
}
void divide(vector<int> &v,int l,int h){
    if(l>=h)
        return;
    int mid=(l+h)/2;
    divide(v,l,mid);
    divide(v,mid+1,h);
    merge(v,l,mid,mid+1,h);
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    divide(v,0,n-1);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
