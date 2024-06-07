class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        long long ans = 0ll;

        priority_queue<int> pq(nums.begin(),nums.end());

        while(k--) {
            auto t = pq.top();
            pq.pop();
            pq.push(ceil((double)t/3.0));
            ans += t;
        }

        return ans;
    }
};
