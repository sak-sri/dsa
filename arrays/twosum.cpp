class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int> > v(n,{-1,-1});
        for(int i=0;i<n;i++){
            v[i]={nums[i],i};
        }
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        while(i<j){
            if(target==v[i].first+v[j].first){
                return {v[i].second,v[j].second};
            }else if(target<v[i].first+v[j].first){
                j--;
            }else{
                i++;
            }
        }
        return {-1,-1};
    }
};