class Solution
{
public:
    vector<int> ans;
    void cal(int i,int sum,vector<int> &arr){
        if(i<0){
            ans.push_back(sum);
            return;
        }
        cal(i-1,sum+arr[i],arr);
        cal(i-1,sum,arr);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        cal(N-1,0,arr);
       sort(ans.begin(),ans.end());
        return ans;
    }
};