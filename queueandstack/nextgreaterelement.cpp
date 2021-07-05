class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<int> st;
        vector<long long> nextGreater(n,-1);
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }else{
                while(!st.empty() && arr[i]>arr[st.top()]){
                    nextGreater[st.top()]=arr[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return nextGreater;
    }
};
