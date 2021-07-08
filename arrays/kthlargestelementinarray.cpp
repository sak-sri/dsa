class Solution {
public:
    int pivot(int l,int h,vector<int> &nums){
        int j=l-1;
        int pivot=nums[l];
        for(int i=l;i<=h;i++){
            if(nums[i]<=pivot){
                swap(nums[++j],nums[i]);
            }
        }
        swap(nums[j],nums[l]);
        return j;
    }
    int helper(int l,int h,vector<int> &nums,int i){
        int pi=pivot(l,h,nums);
        if(pi==i){
            return nums[i];
        }
        else if(pi>i){
            return helper(l,pi-1,nums,i);   
        }else{
            return helper(pi+1,h,nums,i);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return helper(0,nums.size()-1,nums,nums.size()-k);
    }
};