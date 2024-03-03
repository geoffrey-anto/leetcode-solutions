class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(auto i: nums) {
            pq.push(i);
        }
         
        long long cnt = 0;
        
        while(!pq.empty()) {
            if(pq.top() >= k) return cnt;
            
            if(pq.size() > 1) {
                int x = pq.top(); pq.pop();
                int y = pq.top(); pq.pop();
                
                pq.push(min(x, y) * 2ll + max(x, y));
                cnt++;
            } else {
                return pq.top() >= k ? cnt : cnt;
            }
        }
        
        return cnt;
    }
};
