class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0ll;

        priority_queue<int> pq;

        for(auto i: nums) {
            pq.push(i);
        }

        while(k--) {
            ans += pq.top();
            int curr = pq.top();

            pq.pop();

            pq.push(ceil((double)curr / 3.0));
        }

        return ans;
    }
};
