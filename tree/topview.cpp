

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        if(root==NULL)
            return {};
        map<int,int> mp;
        queue<pair<Node*,int> > q;
        q.push({root,0});
        mp[0]=root->data;
        while(!q.empty()){
            Node *parent=q.front().first;
            int hd=q.front().second;
            q.pop();
            if(parent->left){
                if(mp.find(hd-1)==mp.end()){
                    mp[hd-1]=parent->left->data;
                }
                q.push({parent->left,hd-1});
            }
            if(parent->right){
                if(mp.find(hd+1)==mp.end()){
                    mp[hd+1]=parent->right->data;
                }
                q.push({parent->right,hd+1});
            }
        }
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }

};


