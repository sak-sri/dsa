#include<bits/stdc++.h>
using namespace std;
int main(){
    int v,e;
    cin>>v>>e;
    pair<int,pair<int,int> > g[e];
    for(int i=0;i<e;i++){
        int src,dst,wt;
        cin>>src>>dst>>wt;
        g[i]={wt,{src,dst}};
    }
    int dist[v],parent[v];
    fill(dist,dist+v,INT_MAX);
    memset(parent,-1,sizeof(parent));
    dist[0]=0;
    int x=-1;
    for(int i=0;i<v;i++){
        x=-1;
        for(int j=0;j<e;j++){
            if(g[j].second.first!=INT_MAX){
                if(dist[g[j].second.second]>(dist[g[j].second.first]+g[j].first)){
                    dist[g[j].second.second]=dist[g[j].second.first]+g[j].first;
                    parent[g[j].second.second]=g[j].second.first;
                    x=1;
                }
            }
        }
    }
    for(int i=0;i<v;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    if(x==1){
        cout<<"cycle";
    }else{
        int trg;
        cin>>trg;
        if(parent[trg]==-1)
            cout<<"no path";
        else{
            cout<<trg<<" ";
            while(parent[trg]!=-1){
                cout<<parent[trg]<<" ";
                trg=parent[trg];
            }
        }
    }
    return 0;
}