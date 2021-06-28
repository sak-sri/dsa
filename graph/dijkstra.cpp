class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        vector<pair<int,int> > g[n];
        for(auto it:times){
            g[it[0]-1].push_back({it[1]-1,it[2]});
        }
        vector<int> dist(n,INT_MAX);
        vector<bool> visited(n,false);
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            int src=pq.top().second;
            int srcDist=pq.top().first;
            visited[src]=true;
            pq.pop();
            for(auto it:g[src]){
                if((!visited[it.first]) && (dist[it.first]>srcDist+it.second)){
                    dist[it.first]=srcDist+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int mx=-1;
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            mx=max(mx,dist[i]);
        }
        return mx;
    }
};