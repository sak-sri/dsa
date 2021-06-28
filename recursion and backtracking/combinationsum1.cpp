class Solution {
public:
    vector<vector<int> > ans;
    void combinationSum(int i,vector<int> temp,vector<int> &nums,int target){
        if(target<0)
            return;
        if(i<0 && target==0){
            ans.push_back(temp);
            return;
        }
        if(i<0)
            return;
        combinationSum(i-1,temp,nums,target);
        temp.push_back(nums[i]);
        combinationSum(i,temp,nums,target-nums[i]);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<int> s;
        for(auto it:candidates){
            s.insert(it);
        }
        vector<int> nums;
        for(auto it:s){
            nums.push_back(it);
        }
        int n=nums.size();
        vector<int> temp;
        combinationSum(n-1,temp,nums,target);
        return ans;
    }
};