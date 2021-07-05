class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int> st;
        vector<int> nextSmaller(n);
        for(int i=0;i<n;i++){
            nextSmaller[i]=prices[i];
        }
        for(int i=0;i<n;i++){
            while((!st.empty()) && (prices[i]<=prices[st.top()])){
                nextSmaller[st.top()]-=prices[i];
                st.pop();
            }
            st.push(i);
        }
        return nextSmaller;
    }
};