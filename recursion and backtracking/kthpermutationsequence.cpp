class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> s;
        for(int i=1;i<=n;i++){
            s.push_back((i+'0'));
        }
        int fact[n+1];
        fact[0]=1;
        for(int i=1;i<=n;i++){
            fact[i]=i*fact[i-1];
        }
        k-=1;
        string ans;
        vector<char>::iterator it;
        while(!s.empty()){
            int sz=fact[n]/n;
            it=s.begin();
            advance(it,k/sz);
            ans+=*it;
            s.erase(it);
            k=k%sz;
            n--;
        }
        return ans;
    }
};