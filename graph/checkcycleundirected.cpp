class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool check(int i,int p,bool visited[],vector<int> adj[]){
        visited[i]=true;
        for(auto it:adj[i]){
            if(!visited[it]){
                if(check(it,i,visited,adj))
                    return true;
            }else if(it!=p && p!=-1)
                return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    bool visited[V];
	    memset(visited,false,sizeof(visited));
	    for(int i=0;i<V;i++){
	        if((!visited[i]) && check(i,-1,visited,adj)){
	            return true;
	        }
	    }
	    return false;
	}
};
