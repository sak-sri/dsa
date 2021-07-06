class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m){
            return kthElement(arr2,arr1,m,n,k);
        }
        long int low=max(0,k-m);
        long int high=min(k,n);
        while(low<=high){
            long int cut1=low+((high-low)/2);
            long int cut2=k-cut1;
            long int l1=cut1>0?arr1[cut1-1]:LONG_MIN;
            long int l2=cut2>0?arr2[cut2-1]:LONG_MIN;
            long int r1=cut1<n?arr1[cut1]:LONG_MAX;
            long int r2=cut2<m?arr2[cut2]:LONG_MAX;
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }else if(l1>r2){
                high=cut1-1;
            }else{
                low=cut1+1;
            }
            
        }
    }
};

