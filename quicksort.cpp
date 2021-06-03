#include<bits/stdc++.h>
using namespace std;
int findpivotposition(vector<int> &v,int l,int h){
    int i=l;
    int pivot=v[l];
    for(int j=l+1;j<=h;j++){
        if(v[j]<pivot){
            swap(v[++i],v[j]);
        }
    }
    swap(v[i],v[l]);
    return i;
}
void divide(vector<int> &v,int l,int h){
    if(l>=h)
        return;
    int pivotpos=findpivotposition(v,l,h);
    divide(v,l,pivotpos-1);
    divide(v,pivotpos+1,h);
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
/*
The worst case occurs when the partition process always picks greatest or smallest element as pivot.
 when the array is already sorted in ascending or descending order
T(n) = T(1) + T(n-1) + O(n)
which is equivalent to  
T(n) = T(n-1) + O(n)
Time Complexity=O(n*n)

The best case occurs when the partition process always picks the middle element as pivot. 
Following is recurrence for best case. 
T(n) = 2T(n/2) + O(n)
Time Complexity=O(nlog(n))
*/
