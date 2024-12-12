class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(auto i: gifts) {
            pq.push(i);
        }

        long long ans = 0;

        while(k--) {
            long long t = pq.top();
            pq.pop();

            long long x = floor(sqrt(t));

            pq.push(x);
        }   

        while(!pq.empty()) {
            ans += (long long)pq.top();
            pq.pop();
        }

        return ans;
    }
};
