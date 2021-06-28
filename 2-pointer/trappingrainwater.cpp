
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        pair<int,int> p[n];
        int mxfromleft=-1,mxfromright=-1;
        for(int i=0;i<n;i++){
            p[i].first=mxfromleft;
            mxfromleft=max(mxfromleft,arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            p[i].second=mxfromright;
            mxfromright=max(mxfromright,arr[i]);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=max(min(p[i].first,p[i].second)-arr[i],0);
        }
        return ans;
    }
};