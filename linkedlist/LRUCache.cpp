struct Node{
    Node *next,*prev;
    int key,val;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
public:
    int cap,currCap;
    unordered_map<int,Node*> mp;
    Node *head,*tail;
    LRUCache(int capacity) {
        currCap=0;
        mp.clear();
        this->cap=capacity;
        head=new Node(INT_MAX,INT_MAX);
        tail=new Node(INT_MIN,INT_MAX);
        head->next=tail;
        head->prev=NULL;
        tail->prev=head;
        tail->next=NULL;
    }
    
    int get(int key) {
        if((mp.find(key)==mp.end()) || (cap==0))
            return -1;
        else{
            Node *target=mp[key];
            target->prev->next=target->next;
            target->next->prev=target->prev;
            Node *temp=head->next;
            temp->prev=target;
            target->next=temp;
            target->prev=head;
            head->next=target;
            return target->val;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->val=value;
            get(key);
            return;
        }
         if(currCap==cap){
            mp.erase(tail->prev->key);
            tail->prev->prev->next=tail;
            tail->prev=tail->prev->prev;
            currCap--;
        }
        currCap++;
        Node* temp=new Node(key,value);
        head->next->prev=temp;
        temp->next=head->next;
        temp->prev=head;
        head->next=temp;
        mp[key]=temp;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */