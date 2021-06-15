class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int> > s;
        vector<vector<int> > ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=nums[i]+nums[j];
                int l=j+1;
                int r=n-1;
                while(l<r){
                    if((nums[l]+nums[r]==target-temp) && s.find({nums[i],nums[j],nums[l],nums[r]})==s.end()){
                        s.insert({nums[i],nums[j],nums[l],nums[r]});
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                    }else if(nums[l]+nums[r]>target-temp){
                        r--;
                    }else
                        l++;
                }
            }
        }
        return ans;
    }
};