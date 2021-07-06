#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isPossible(vector<ll> &v,ll dist,ll c){
    ll n=v.size();
    ll prev=v[0];
    c--;
    for(ll i=1;i<n;i++){
        if(v[i]-prev>=dist){
            prev=v[i];
            c--;
            if(c==0)
                return true;
        }
    }
    return false;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        vector<ll> v(n);
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll low=1,high=v[n-1]-v[0]+1;
        ll ans=1;
        while(low<=high-1){
            ll mid=low+((high-low)/2);
            if(isPossible(v,mid,c)){
                low=mid+1;
                ans=max(ans,mid);
            }else{
                high=mid;
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}