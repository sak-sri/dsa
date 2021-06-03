#include<bits/stdc++.h>
using namespace std;
int find_set(int i,int parent[]){
    if(parent[i]==i)
        return i;
    return parent[i]=find_set(parent[i],parent);
}
void uni(int v1,int v2,int rank[],int parent[]){
    int a=find_set(v1,parent);
    int b=find_set(v2,parent);
    if(rank[a]>rank[b]){
        parent[b]=a;
        rank[a]++;
    }else{
        parent[a]=b;
        rank[b]++;
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,pair<int,int> > >  p(e);
    for(int i=0;i<e;i++){
        int wt,dst,src;
        cin>>wt>>src>>dst;
        p[i]={wt,{src,dst}};
    } 
    sort(p.begin(),p.end());
    int parent[v],rank[v];
    memset(rank,0,sizeof(rank));
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    int ans=0;
    for(int i=0;i<e;i++){
        int v1,v2;
        v1=p[i].second.first;
        v2=p[i].second.second;
        if(find_set(v1,parent)!=find_set(v2,parent)){
            ans+=p[i].first;
            uni(v1,v2,rank,parent);
        }
    }
    cout<<ans<<endl;
    return 0;
}
// time Complexity (ElogE + ElogV)