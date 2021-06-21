int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int xr=0;
    unordered_map<int,int> mp;
    int ans=0;
    mp[0]=1;
    for(int i=0;i<n;i++){
        xr^=A[i];
        if(mp.find(xr^B)!=mp.end()){
            ans+=mp[xr^B];
        }
        if(mp.find(xr)==mp.end()){
            mp[xr]=1;
        }else{
            mp[xr]++;
        }
    }
    return ans;
}
