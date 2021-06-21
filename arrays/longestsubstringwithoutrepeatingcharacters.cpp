class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> mp; 
        int cnt=0,ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                while(j<=mp[s[i]]){
                    mp.erase(s[j++]);
                    cnt--;
                }
            }
            cnt++;
            mp[s[i]]=i;
            ans=max(ans,cnt);
        }
        return ans;
    }
};