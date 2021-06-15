class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int> > ans;
        int j=0;
        ans.push_back({intervals[0][0],intervals[0][1]});
        int mx=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>mx){
                ans[j][1]=mx;
                ans.push_back({intervals[i][0],intervals[i][1]});
                j++;
            }
            mx=max(mx,intervals[i][1]);
        }
        ans[j][1]=mx;
        return ans;
    }
};