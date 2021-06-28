int find(int i,vector<int> &parent){
    if(parent[i]==i)
        return i;
    else
        return parent[i]=find(parent[i],parent);
}
void uni(int v1,int v2,vector<int> &rank,vector<int> &parent){
    if(rank[v1]>rank[v2]){
        rank[v1]++;
        parent[v2]=v1;
    }else{
        rank[v2]++;
        parent[v1]=v2;
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {
    int e=B.size();
    pair<int,pair<int,int> > edges[e];
    for(int i=0;i<e;i++){
        edges[i]={B[i][2],{B[i][0]-1,B[i][1]-1}};
    }
    sort(edges,edges+e);
    vector<int> parent(A),rank(A);
    for(int i=0;i<A;i++){
        parent[i]=i;
        rank[i]=0;
    }
    int ans=0;
    for(int i=0;i<e;i++){
        int p1=find(edges[i].second.first,parent);
        int p2=find(edges[i].second.second,parent);
        if(p1!=p2){
            uni(p1,p2,rank,parent);
            ans+=edges[i].first;
        }
    }
    return ans;
}
