vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    long long sum1ton=0,sqsum1ton=0,actualsum=0,sqactualsum=0;
    for(int i=1;i<=n;i++){
        sum1ton+=(long long)i;
        sqsum1ton+=((long long)i)*((long long)i);
    }
    for(int i=0;i<n;i++){
        actualsum+=(long long)A[i];
        sqactualsum+=((long long)A[i])*((long long)A[i]);
    }
    long long diff=sum1ton-actualsum;
    long long add=(sqsum1ton-sqactualsum)/diff;
    int repeat=(add-diff)/2;
    int missing=diff+repeat;
    return {repeat,missing};
}
