class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int e=edges.size();
	    vector<int> dist(n,INT_MAX);
	    dist[0]=0;
	    int x=-1;
	    for(int i=0;i<n;i++){
	        x=-1;
	        for(int j=0;j<e;j++){
	            if((dist[edges[j][0]]!=INT_MAX) && (dist[edges[j][1]]>dist[edges[j][0]]+edges[j][2])){
	                dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
	                x=1;
	            }
	        }
	    }
	    return x==1;
	}
};
