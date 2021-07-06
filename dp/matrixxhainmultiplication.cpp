#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int findOptimalMultiplication(int l,int h,int arr[],vector<vector<int> > &dp){
        if(l==h){
            return 0;
        }
        int minMultiplications=INT_MAX;
        if(dp[l][h]!=-1)
            return dp[l][h];
        for(int i=l;i<h;i++){
            minMultiplications=min(findOptimalMultiplication(l,i,arr,dp)+findOptimalMultiplication(i+1,h,arr,dp)+(arr[l-1]*arr[i]*arr[h]),minMultiplications);
        }
        return dp[l][h]=minMultiplications;
    }
    int matrixMultiplication(int N, int arr[])
    {
        if(N<=2)
            return 0;
        vector<vector<int> > dp(N,vector<int>(N,-1));
        return findOptimalMultiplication(1,N-1,arr,dp);
    }
};
int main(){
    return 0;
}