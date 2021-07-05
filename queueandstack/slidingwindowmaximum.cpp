class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int> st;
        vector<int> nextGreater(n,n);
        for(int i=0;i<n;i++){
            while((!st.empty()) && (nums[st.top()]<=nums[i])){
                nextGreater[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int j=0;
        vector<int> ans;
        for(int i=0;i+k-1<n;i++){
            j=max(i,j);
            while(nextGreater[j]<=i+k-1){
                j=nextGreater[j];
            }
            ans.push_back(nums[j]);
        }
        return ans;
    }
};