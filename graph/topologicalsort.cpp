class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	stack<int> s;
	void dfs(int i,vector<int> adj[],bool visited[]){
	    visited[i]=true;
	    for(auto it:adj[i]){
	        if(!visited[it])
	            dfs(it,adj,visited);
	    }
	    s.push(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   bool visited[V];
	   memset(visited,false,sizeof(visited));
	   for(int i=0;i<V;i++){
	       if(!visited[i]){
	           dfs(i,adj,visited);
	       }
	   }
	   vector<int> ans;
	   while(!s.empty()){
	       ans.push_back(s.top());
	       s.pop();
	   }
	   return ans;
	}
};
