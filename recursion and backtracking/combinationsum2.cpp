class Solution {
public:
    vector<vector<int> > ans;
    void cal(int i,int n,vector<int> temp,vector<int> &candidates,int target){
        if(i==n && target==0){
            ans.push_back(temp);
        }
        if((i==n) || (target<0))
            return;
        int j=i+1;
        while(j<n && (candidates[j]==candidates[j-1])){
            j++;
        }
        cal(j,n,temp,candidates,target);
        for(int k=i;k<j;k++){
            target-=candidates[k];
            temp.push_back(candidates[k]);
            cal(j,n,temp,candidates,target);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        cal(0,candidates.size(),temp,candidates,target);
        return ans;
    }
};