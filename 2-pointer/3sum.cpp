class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return {};
        vector<vector<int> > s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            while(j<k){
                if(nums[j]+nums[k]<-nums[i]){
                    j++;
                }else if(nums[j]+nums[k]>-nums[i]){
                    k--;
                }else{
                    s.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1] && nums[k]==nums[k+1]){
                        j++;k--;
                    }
                }
            }
        }
        return s;
    }
};