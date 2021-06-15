class Solution{
    public:
    int maxSubarraySum(int arr[], int n){
        
        int sum=0;
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            res=max(res,sum);
            if(sum<0)
                sum=0;
        }
        return res;
        
    }
};
