#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int countWays(int n, string s){
        int mod=1003;
        string oprtr,oprnd;
        for(auto it:s){
            if(it=='T' || it=='F'){
                oprnd+=it;
            }else{
                oprtr+=it;
            }
        }
        n=oprnd.size();
        int dpt[n][n],dpf[n][n];
        memset(dpt,0,sizeof(dpt));
        memset(dpf,0,sizeof(dpf));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;true,j<n;i++,j++){
                if(g==0){
                    if(oprnd[j]=='T'){
                        dpt[i][j]=1;
                    }else{
                        dpf[i][j]=1;
                    }
                }else{
                    for(int k=i;k<j;k++){
                        int ltc=dpt[i][k]%mod;
                        int rtc=dpt[k+1][j]%mod;
                        int lfc=dpf[i][k]%mod;
                        int rfc=dpf[k+1][j]%mod;
                        if(oprtr[k]=='|'){
                            dpt[i][j]+=(ltc*rtc)+(ltc*rfc)+(lfc*rtc);
                            dpt[i][j]%=mod;
                            dpf[i][j]+=(lfc*rfc);
                            dpf[i][j]%=mod;
                        }else if(oprtr[k]=='&'){
                            dpt[i][j]+=(ltc*rtc);
                            dpt[i][j]%=mod;
                            dpf[i][j]+=(lfc*rfc)+(lfc*rtc)+(rfc*ltc);
                            dpf[i][j]%=mod;
                        }else{
                            dpt[i][j]+=(ltc*rfc)+(lfc*rtc);
                            dpt[i][j]%=mod;
                            dpf[i][j]+=(ltc*rtc)+(lfc*rfc);
                            dpf[i][j]%=mod;
                        }
                    }
                }
            }
        }
        return dpt[0][n-1]%mod;
    }
};
int main(){
    return 0;
}