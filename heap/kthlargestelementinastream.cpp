class KthLargest {
public:
    int sz_mx=0,sz_mn=0,sz=0;
    priority_queue<int,vector<int>,greater<int> > pq_mn;
    priority_queue<int> pq_mx;
    KthLargest(int k, vector<int>& nums) {
        sz=k;
        for(auto it:nums){
            if(sz_mn<k){
                pq_mn.push(it);
                sz_mn++;
            }else{
                if(it<=pq_mn.top()){
                    pq_mx.push(it);
                    sz_mx++;
                }else{
                    pq_mx.push(pq_mn.top());
                    sz_mx++;
                    pq_mn.pop();
                    pq_mn.push(it);
                }
            }
        }
    }
    
    int add(int val) {
        if(sz_mn<sz){
            pq_mn.push(val);
            sz_mn++;
            return pq_mn.top();
        }
       if(pq_mn.top()>=val){
           pq_mx.push(val);
           sz_mx++;
       }else{
           pq_mx.push(pq_mn.top());
           sz_mx++;
           pq_mn.pop();
           pq_mn.push(val);
       }
        return pq_mn.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */