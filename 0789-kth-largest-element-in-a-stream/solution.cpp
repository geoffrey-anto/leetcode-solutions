class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto &i:nums){
            this->pq.push(i);
        }
        while(this->pq.size()>this->k){
            this->pq.pop();
        }
    }
    
    int add(int val) {
        this->pq.push(val);
        if(this->pq.size()>this->k){
            this->pq.pop();
        }
        return this->pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
