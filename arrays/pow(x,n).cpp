class Solution {
public:
    double binpow(double a,int b){
        if(b==0)
            return 1.0;
        if(b==1)
            return a;
        double temp=binpow(a,b/2);
        if(b%2)
            return temp*temp*a;
        else
            return temp*temp;
    }
    double myPow(double x, int n) {
        if(n<0)
            x=1/x;
        return binpow(x,n);
    }
};