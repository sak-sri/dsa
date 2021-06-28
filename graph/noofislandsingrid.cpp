class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,-1,1};
    bool check(int i,int j,vector<vector<bool> > &visited,int n,int m){
        return i>=0 && i<n && j>=0 && j<m && (!visited[i][j]);
    }
    void dfs(int i,int j,vector<vector<bool> > &visited,int n,int m){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            if(check(i+y[k],j+x[k],visited,n,m)){
                dfs(i+y[k],j+x[k],visited,n,m);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0'){
                    visited[i][j]=true;
                }
            }
        }
        int noofislands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    dfs(i,j,visited,n,m);
                    noofislands++;
                }
            }
        }
        return noofislands;
    }
};