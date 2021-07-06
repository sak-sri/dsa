class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0,high=min(n1,(n1+n2)/2);
        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=((n1+n2)/2)-cut1;
            double l1=cut1>0?nums1[cut1-1]:INT_MIN;
            double l2=cut2>0?nums2[cut2-1]:INT_MIN;
            double r1=cut1<n1?nums1[cut1]:INT_MAX;
            double r2=cut2<n2?nums2[cut2]:INT_MAX;
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2){
                    return min(r1,r2);
                }else{
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }else if(l1>r2){
                high=cut1-1;
            }else{
                low=cut1+1;
            }
        }
        return -1;
    }
};