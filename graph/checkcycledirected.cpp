

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool check(int i,vector<int> adj[],bool grey[],bool white[],bool black[]){
	    if(black[i])
	        return true;
	    if(!white[i])
	        return false;
	    black[i]=true;
	    white[i]=false;
	    for(auto it:adj[i]){
	        if(check(it,adj,grey,white,black))
	            return true;
	    }
	    black[i]=false;
	    grey[i]=true;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	bool white[V],black[V],grey[V];
	   	memset(white,true,sizeof(white));
	   	memset(black,false,sizeof(black));
	   	memset(grey,false,sizeof(grey));
	   	for(int i=0;i<V;i++){
	   	    if(check(i,adj,grey,white,black))
	   	        return true;
	   	}
	   	return false;
	}
};
