class Solution {
public:
    int merge(int l1,int h1,int l2,int h2,vector<int> &nums){
        int n1=h1-l1+1,n2=h2-l2+1;
        int temp1[n1],temp2[n2];
        for(int i=l1;i<=h1;i++){
            temp1[i-l1]=nums[i];
        }
        for(int i=l2;i<=h2;i++){
            temp2[i-l2]=nums[i];
        }
        int i=0,j=0,k=l1,revpair=0;
        while(i<n1){
            while(j<n2 && ((temp1[i]/2.0)>temp2[j]))
                j++;
            revpair+=j;
            i++;
        }
        i=0;
        j=0;
        while(i<n1 && j<n2){
            if(temp1[i]<=temp2[j]){
                nums[k++]=temp1[i++];   
            }else{
                nums[k++]=temp2[j++];
            }
        }
        while(i<n1){
            nums[k++]=temp1[i++];
        }
        while(j<n2){
            nums[k++]=temp2[j++];
        }
        return revpair;
    }
    int divide(int l,int h,vector<int> &nums){
        if(l>=h)
            return 0;
        int mid=l+((h-l)/2);
        return divide(l,mid,nums)+divide(mid+1,h,nums)+merge(l,mid,mid+1,h,nums);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int revpair=divide(0,n-1,nums);
        for(auto it:nums){
            cout<<it<<" ";
        }
        cout<<endl;
        return revpair;
    }
};