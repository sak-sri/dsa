class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> s(nums.begin(),nums.end());
       int n=nums.size();
        if(n==0)
            return 0;
       int ans=1;
       for(int i=0;i<n;i++){
           if(s.find(nums[i])==s.end())
               continue;
           int right=nums[i]+1;
           int left=nums[i]-1;
           while(s.find(right)!=s.end())
               s.erase(right++);
           while(s.find(left)!=s.end())
               s.erase(left--);
           ans=max(ans,right-left-1);
       }
        return ans;
    }
};