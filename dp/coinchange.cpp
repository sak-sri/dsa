#include<bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    long long int count( int s[], int m, int n )
    {
       long long int dp[n+1];
       memset(dp,0,sizeof(dp));
       dp[0]=1;
       for(int i=0;i<m;i++){
           for(int j=s[i];j<=n;j++){
               dp[j]+=dp[j-s[i]];
           }
       }
       return dp[n];
    }
};
int main(){
    return 0;
}