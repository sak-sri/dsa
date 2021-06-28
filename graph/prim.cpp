class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        set<pair<int,int> > s;
        vector<pair<int,int> > dist(v,{INT_MAX,-1});
        dist[0].first=0;
        vector<bool> selected(v,false);
        s.insert({0,0});
        for(int i=0;i<v;i++){
            int srcDist=s.begin()->first;
            int src=s.begin()->second;
            selected[src]=true;
            s.erase(s.begin());
            for(auto it:adj[src]){
                if((!selected[it[0]]) && (dist[it[0]].first>it[1])){
                    s.erase({dist[it[0]].first,it[0]});
                    dist[it[0]]={it[1],src};
                    s.insert({it[1],it[0]});
                }
            }
        }
        int ans=0;
        for(int i=0;i<v;i++){
            ans+=dist[i].first;
        }
        return ans;
    }
};
