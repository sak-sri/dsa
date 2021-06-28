
class Solution
{
	public:
	stack<int> s;
	void dfs(int i,vector<int> adj[],vector<int> revadj[],bool visited[],bool reverse){
	    visited[i]=true;
	    for(auto it:adj[i]){
	        if(reverse)
	            revadj[it].push_back(i);
	        if(!visited[it])
	            dfs(it,adj,revadj,visited,reverse);
	    }
	     s.push(i);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        int ans=0;
        vector<int> revadj[V];
        bool visited[V];
        memset(visited,false,sizeof(visited));
        bool tempvisited[V];
        memset(tempvisited,false,sizeof(tempvisited));
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,revadj,visited,true);
             }
        }
         while(!s.empty()){
                    if(!tempvisited[s.top()]){
                        ans++;
                        dfs(s.top(),revadj,revadj,tempvisited,false);
                    }
                    s.pop();
        }
        return ans;
    }
};
