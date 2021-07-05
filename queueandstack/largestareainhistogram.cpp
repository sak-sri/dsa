class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<pair<int,int> > st;
        int mx=0;
        for(int i=0;i<n;i++){
            if(st.empty() || (heights[i]>=heights[st.top().first])){
                st.push({i,heights[i]});
                mx=max(mx,st.top().second);
            }else if(heights[i]<=heights[st.top().first]){
                while(!st.empty() && heights[i]<=heights[st.top().first]){
                    mx=max(mx,((i-st.top().first-1)*heights[st.top().first])+st.top().second);
                    st.pop();
                }
                if(!st.empty())
                    st.push({i,(i-st.top().first)*heights[i]});
                else{
                    st.push({i,(i+1)*heights[i]});
                }
            }
        }
        while(!st.empty()){
            mx=max(mx,((n-st.top().first-1)*heights[st.top().first])+st.top().second);   
            st.pop();
        }
        return mx;
    }
};