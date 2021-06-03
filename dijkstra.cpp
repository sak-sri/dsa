#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,edges;
    cin>>n>>edges;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<pair<int,int> > g[n];
    for(int i=0;i<edges;i++){
        int src,dst,wt;
        cin>>src>>dst>>wt;
        g[src].push_back({wt,dst});
        g[dst].push_back({wt,src});
    }
    int src;
    cin>>src;
    int dst[n];
    bool visited[n];
    memset(visited,false,sizeof(visited));
    fill(dst,dst+n,INT_MAX);
    dst[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int src=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        if(visited[src])
            continue;
        visited[src]=true;
        for(auto it:g[src]){
            if(dist+it.first<dst[it.second]){
                dst[it.second]=dist+it.first;
                pq.push({dst[it.second],it.second});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dst[i]<<" ";
    }
    return 0;
}
//Time Complexity (ElogV + V)