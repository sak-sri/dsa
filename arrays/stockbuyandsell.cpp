class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        if(n==0)
            return ans;
        int mn=prices[0];
        for(int i=1;i<n;i++)
        {
            ans=max(prices[i]-mn,ans);
            mn=min(mn,prices[i]);
        }
        return ans;
    }
};