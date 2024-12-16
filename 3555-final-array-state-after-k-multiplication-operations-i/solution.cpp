class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto i=0; i<nums.size(); i++) {
            pq.push({
                nums[i], i
            });
        }

        while(k--) {
            auto t = pq.top();
            pq.pop();
            t.first *= multiplier;
            pq.push(t);
        }

        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();

            nums[t.second] = t.first;
        }

        return nums;
    }
};
