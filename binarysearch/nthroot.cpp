#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	long long int binexpo(long long int a,long long int b){
	    if(b==0)
	        return 1;
	    if(b==1)
	        return a;
	    long long int temp=binexpo(a,b/2);
	    if(b%2){
	        return temp*temp*a;
	    }else{
	        return temp*temp;
	    }
	}
	int NthRoot(int n, int m)
	{
	    if((m==0) || (m==1))
	        return m;
	    long long int l=1;
	    long long int h=m+1;
	    while(l<=h-1){
	        long long int mid=(h+l)/2;
	        long long int temp=binexpo(mid,n);
            cout<<temp<<endl;
	        if(temp>m){
	            h=mid;
	        }else if(temp<m){
	            l=mid+1;
	        }else{
	            return mid;
	        }
	    }
	    return -1;
	}  
};
int main(){
    Solution s;
    cout<<s.NthRoot(7,78125)<<endl;
    return 0;
}