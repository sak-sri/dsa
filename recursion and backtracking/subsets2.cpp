class Solution {
public:
    vector<vector<int> > v;
    void cal(int i,vector<int> &nums,vector<int> temp,int n){
        if(i==n){
            v.push_back(temp);
            return;
        }
        int j=i+1;
        while((j<n) && (nums[j]==nums[j-1])){
            j++;
        }
        cal(j,nums,temp,n);
        for(int k=i;k<j;k++){
            temp.push_back(nums[k]);
            cal(j,nums,temp,n);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> temp;
        cal(0,nums,temp,n);
        return v;
    }
};