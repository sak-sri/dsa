#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long cal(int m,int n,int x,vector<vector<long long int> > &dp){
        if(x==0 && n==0)
            return 1;
        if(x<0)
            return 0;
        if(n<=0)
            return 0;
        if(dp[n][x]!=-1)
            return dp[n][x];
        long long int sum=0;
        for(long long int i=1;i<=m;i++){
            sum+=cal(m,n-1,x-i,dp);
        }
        return dp[n][x]=sum;
    }
    long long noOfWays(int m , int n , int x) {
        vector<vector<long long int> > dp(n+1,vector<long long int>(x+1,-1));
        return cal(m,n,x,dp);
    }
};
int main(){
    return 0;
}