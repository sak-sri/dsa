class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n=nums.size();
      if(n<2)
          return n;
      int curr=0,next=1;
      int ans=1;
      while(next<n){
          if(nums[curr]!=nums[next]){
              ans++;
              swap(nums[++curr],nums[next++]);
          }else{
              next++;
          }
      }
        return ans;
    }
};