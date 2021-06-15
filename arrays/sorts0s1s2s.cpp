#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,k=n-1;
        while(j<n){
            if(nums[j]==0){
                swap(nums[j++],nums[i++]);
            }else if(nums[j]==1){
                j++;
            }else{
                if(j<k)
                    swap(nums[j],nums[k--]);
                else
                    break;
                        
            }
        }
    }
};
int main(){
    return 0;
}