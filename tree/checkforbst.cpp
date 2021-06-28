
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    int next(stack<Node*> &st){
        Node* temp=st.top();
        int curr=temp->data;
        st.pop();
        if(temp->right){
            temp=temp->right;
            st.push(temp);
            temp=temp->left;
            while(temp){
                st.push(temp);
                temp=temp->left;
            }
        }
        return curr;
    }
    bool isBST(Node* root) 
    {
        if(root==NULL)
            return true;
        stack<Node*> st;
        Node* curr=root;
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        if(!st.empty()){
            int prev=INT_MIN;
            int curr=next(st);
            while((!st.empty()) && (curr>prev)){
                prev=curr;
                curr=next(st);
            }
        }
        return st.empty();
    }
};
