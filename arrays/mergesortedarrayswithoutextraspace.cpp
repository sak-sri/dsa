class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap=((n+m)/2)+((n+m)%2);
        while(gap){
            int i=0;
            for(;i+gap<m;i++){
                if(nums1[i]>nums1[i+gap]){
                    swap(nums1[i],nums1[i+gap]);
                }
            }
            for(;i<m && i+gap-m<n;i++)
                if(nums1[i]>nums2[i+gap-m]){
                    swap(nums1[i],nums2[i+gap-m]);
                }
            for(;i>=m && i+gap-m<n;i++){
                if(nums2[i-m]>nums2[i+gap-m])
                    swap(nums2[i-m],nums2[i+gap-m]);
            }
            if(gap==1)
                break;
            gap=(gap/2)+gap%2;
        }
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
    }
};