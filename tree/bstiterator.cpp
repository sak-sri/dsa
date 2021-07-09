class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* pointer=st.top();
        st.pop();
        TreeNode* element=pointer;
        element=element->right;
        while(element){
            st.push(element);
            element=element->left;
        }
        return pointer->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
