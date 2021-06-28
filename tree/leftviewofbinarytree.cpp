vector<int> leftView(Node *root)
{
    if(root==NULL){
        return {};
    }
   queue<pair<Node*,int> > q;
   q.push({root,0});
   vector<pair<int,int> > v;
   while(!q.empty()){
       Node *parent=q.front().first;
       int level=q.front().second;
       q.pop();
       if((v.empty()) || (v.back().first!=level)){
           v.push_back({level,parent->data});
       }
       if(parent->left)
            q.push({parent->left,level+1});
       if(parent->right)
            q.push({parent->right,level+1});
   }
   vector<int> ans;
   for(auto it:v){
       ans.push_back(it.second);
   }
   return ans;
}
