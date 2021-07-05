
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int x[]={1,-1,0,0};
        int y[]={0,0,-1,1};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int> > q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=1)
                    visited[i][j]=true;
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        int ans=0;
        while(!q.empty()){
            int srcX=q.front().first.first;
            int srcY=q.front().first.second;
            int tm=q.front().second;
            ans=max(ans,tm);
            q.pop();
            for(int i=0;i<4;i++){
                if((srcX+x[i]>=0) && (srcX+x[i]<n) && (srcY+y[i]>=0) && (srcY+y[i]<m) && (!visited[srcX+x[i]][srcY+y[i]])){
                    q.push({{srcX+x[i],srcY+y[i]},tm+1});
                    visited[srcX+x[i]][srcY+y[i]]=true;
                    fresh--;
                }
            }
        }
        if(fresh)
            ans=-1;
        return ans;
        
    }
};
