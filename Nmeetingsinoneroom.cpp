#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        pair<int,int> p[n];
        for(int i=0;i<n;i++){
            p[i]={start[i],end[i]};
        }
        sort(p,p+n,[](pair<int,int> a,pair<int,int> b){
            return a.second<b.second;
        });
        int prev=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(p[i].first>prev){
                ans++;
                prev=p[i].second;
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}