class Solution {
public:
    bool dfs(int i,int color,vector<vector<int>> &graph,int visited[]){
        visited[i]=color;
        for(auto it:graph[i]){
            if(visited[it]==-1){
                visited[it]=1-color;
                if(!dfs(it,1-color,graph,visited))
                    return false;
            }else if(visited[it]==color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int visited[n];
        memset(visited,-1,sizeof(visited));
        for(int i=0;i<n;i++){
            if((visited[i]==-1) && (!dfs(i,0,graph,visited)))
                return false;
        }
        return true;
    }
};