class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;

        for(auto i=0; i<k; i++) {
            pq.push(make_pair(nums[i], i));
        }

        vector<int> ans;

        for(auto i=k-1; i<n; i++) {
            pq.push(make_pair(nums[i], i));

            // now check if the topmost val lies in the window
            // if not remove top till not found

            while((i - pq.top().second) >= k) pq.pop();

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
