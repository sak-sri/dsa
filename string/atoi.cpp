class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                s=s.substr(i,n-i);
                break;
            }
        }
        n=s.length();
        if(n==0)
            return 0;
        bool isPositive=true;
        if(s[0]=='-'){
            isPositive=false;
        }
        if((s[0]=='+') || (s[0]=='-')){
            s=s.substr(1,n-1);
            n--;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(((s[i]-'0')>=0) && ((s[i]-'0')<=9)){
                if(isPositive){
                    if((INT_MAX/10<ans) || (INT_MAX%10<s[i]-'0' && INT_MAX/10==ans))
                        return INT_MAX;
                }else{
                    if((INT_MAX/10<-ans) || ((INT_MAX/10==-ans) && (s[i]-'0')>8))
                        return INT_MIN;
                }
                if(isPositive)
                    ans=(ans*10)+(s[i]-'0');
                else{
                    if(ans>0)
                        ans=-ans;
                    ans=(ans*10)-(s[i]-'0');
                }
            }else{
                break;
            }
        }
        return ans;
    }
};