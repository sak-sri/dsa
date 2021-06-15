class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int bp=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                bp=i;
                break;
            }
        }
        if(bp==-1){
            reverse(nums.begin(),nums.end());
        }else{
            for(int i=n-1;i>=bp;i--){
                if(nums[i]>nums[bp-1]){
                    swap(nums[i],nums[bp-1]);
                    break;
                }
            }
            reverse(nums.begin()+bp,nums.end());
        }
    }
};