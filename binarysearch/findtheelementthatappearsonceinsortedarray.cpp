class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int l=0;
        int h=n-2;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==arr[mid^1]){
                l=mid+1;       
            }else{
                h=mid-1;
            }
        }
        return arr[l];
    }
};