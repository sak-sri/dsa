class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mn=min(mn,(int)strs[i].length());
        }
        string s=strs[0];
        string ans;
        for(int k=0;k<mn;k++){
            bool val=true;
            for(int i=1;i<n;i++){
                if(s[k]!=strs[i][k]){
                    val=false;
                    break;
                }
            }
            if(val){
                ans+=s[k];
            }
            else
                break;
        }
        return ans;
    }
};