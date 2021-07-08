class MedianFinder {
public:
    /** initialize your data structure here. */
    int sz_mn=0,sz_mx=0;
    priority_queue<int> pq_mx;
    priority_queue<int,vector<int>,greater<int> > pq_mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if((sz_mn+sz_mx)%2){
            if(pq_mx.top()>=num){
                pq_mn.push(pq_mx.top());
                sz_mn++;
                pq_mx.pop();
                pq_mx.push(num);
            }else{
                pq_mn.push(num);
                sz_mn++;
            }
        }else{
            if((pq_mx.empty()) || (pq_mx.top()>=num)){
                pq_mx.push(num);
                sz_mx++;
            }else{
                if(num>=pq_mx.top() && num<=pq_mn.top()){
                    pq_mx.push(num);
                    sz_mx++;
                }else{
                    pq_mx.push(pq_mn.top());
                    sz_mx++;
                    pq_mn.pop();
                    pq_mn.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if((sz_mx+sz_mn)%2){
            return pq_mx.top();
        }else{
            return (pq_mx.top()+pq_mn.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */