class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        unordered_map<int,int> mp;
        int distinct=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mp.find(A[i])==mp.end()){
                mp[A[i]]=1;
                distinct++;
            }else{
                mp[A[i]]++;
            }
            if(i>=k-1){
                if(i>=k){
                    mp[A[i-k]]--;
                    if(mp[A[i-k]]==0){
                        distinct--;
                        mp.erase(A[i-k]);
                    }
                }
                ans.push_back(distinct);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends