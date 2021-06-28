
class Solution {
public:
    vector<vector<string> > ans;
    void cal(int i,int n,vector<string> temp,vector<vector<bool> > &dp,string &s){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        string str;
        for(int j=i;j<n;j++){
            str+=s[j];
            if(dp[i][j]){
                temp.push_back(str);
                cal(j+1,n,temp,dp,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<bool> > dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            if(i+1<n){
                if(s[i]==s[i+1]){
                    dp[i][i+1]=true;
                }
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i+k-1<n;i++){
                if((dp[i+1][i+k-2]) && (s[i]==s[i+k-1])){
                    dp[i][i+k-1]=true;
                }
            }   
        }
        vector<string> temp; 
        cal(0,n,temp,dp,s);
        return ans;
    }
};