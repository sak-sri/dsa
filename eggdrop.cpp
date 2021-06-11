#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int cal(int f,int n,vector<vector<int> > &dp){
        if(n==1){
            return f;
        }
        if(f==1)
            return 1;
        if(f==0)
            return 0;
        if(dp[f][n]!=-1)
            return dp[f][n];
        int temp=INT_MAX;
        for(int i=1;i<=f;i++){
            temp=min(temp,1+max(cal(i-1,n-1,dp),cal(f-i,n,dp)));
        }
        return dp[f][n]=temp;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int> > dp(k+1,vector<int>(n+1,-1));
        return cal(k,n,dp);
    }
};

int main(){
    return 0;
}