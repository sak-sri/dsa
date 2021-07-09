int getGreater(stack<Node*> &ascending){
    Node* nextGreater=ascending.top();
    ascending.pop();
    Node* element=nextGreater->right;
    while(element){
        ascending.push(element);
        element=element->left;
    }
    return nextGreater->data;
}
int getSmaller(stack<Node*> &descending){
    Node* nextSmaller=descending.top();
    descending.pop();
    Node* element=nextSmaller->left;
    while(element){
        descending.push(element);
        element=element->right;
    }
    return nextSmaller->data;
}
class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        stack<Node*> ascending,descending;
        Node *ascendingPointer=root,*descendingPointer=root;
        while(ascendingPointer){
            ascending.push(ascendingPointer);
            ascendingPointer=ascendingPointer->left;
        }
        while(descendingPointer){
            descending.push(descendingPointer);
            descendingPointer=descendingPointer->right;
        }
        int low=getGreater(ascending);
        int high=getSmaller(descending);
        while(low<high){
            if(low+high==target){
                return 1;
            }else if(low+high<target){
                low=getGreater(ascending);
            }else{
                high=getSmaller(descending);
            }
        }
        return 0;
    }
};
