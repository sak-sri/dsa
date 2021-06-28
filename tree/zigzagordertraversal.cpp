/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        int cnt=1;
        int level=0;
        vector<vector<int> > ans;
        while(!q.empty()){
            vector<int> nodesateachlevel;
            int noofnodes=0;
            for(int i=0;i<cnt;i++){
                TreeNode *parent=q.front();
                nodesateachlevel.push_back(parent->val);
                
                q.pop();
                if(parent->left){
                    q.push(parent->left);
                    noofnodes++;
                }
                if(parent->right){
                    q.push(parent->right);
                    noofnodes++;
                }
            }
             cnt=noofnodes;
            if(level%2){
                reverse(nodesateachlevel.begin(),nodesateachlevel.end());
            }
            ans.push_back(nodesateachlevel);
            level++;
        }
        return ans;
    }
};