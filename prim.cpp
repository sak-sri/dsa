#include<bits/stdc++.h>
using namespace std;
int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,int> > g[v];
    for(int i=0;i<e;i++){
        int src,dst,wt;
        cin>>src>>dst>>wt;
        g[src].push_back({dst,wt});
        g[dst].push_back({src,wt});
    }
    set<pair<int,int> > s;
    vector<pair<int,int> > min_e(v,{INT_MAX,-1});
    min_e[0].first=0;
    vector<bool> selected(v,false);
    s.insert({0,0});
    int ans=0;
    for(int i=0;i<v;i++){
        int src=s.begin()->second;
        selected[src]=true;
        ans+=s.begin()->first;
        s.erase(s.begin());
        for(auto it:g[src]){
            if((!selected[it.first]) && (it.second<min_e[it.first].first)){
                s.erase({min_e[it.first].first,it.first});
                min_e[it.first]={it.second,src};
                s.insert({it.second,it.first});
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
// time complexity Elog(v)