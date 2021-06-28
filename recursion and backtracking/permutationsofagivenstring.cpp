class Solution
{
	public:
	    vector<string> ans;
	    void cal(int l,int h,string s){
	        if(l==h){
	            ans.push_back(s);
	        }
	        for(int k=l;k<=h;k++){
	            swap(s[k],s[l]);
	            cal(l+1,h,s);
	            swap(s[k],s[k]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(),S.end());
		    cal(0,S.length()-1,S);
		    return ans;
		}
};

