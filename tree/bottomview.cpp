vector <int> bottomView(Node *root)
{
    if(root==NULL)
        return {};
   queue<pair<Node*,int> > q;
   q.push({root,0});
   map<int,int> mp;
   mp[0]=root->data;
   while(!q.empty()){
       Node *parent=q.front().first;
       int hd=q.front().second;
       q.pop();
       if(parent->left){
           mp[hd-1]=parent->left->data;
           q.push({parent->left,hd-1});
       }
       if(parent->right){
           mp[hd+1]=parent->right->data;
           q.push({parent->right,hd+1});
       }
   }
   vector<int> v;
   for(auto it:mp){
       v.push_back(it.second);
   }
   return v;
}

