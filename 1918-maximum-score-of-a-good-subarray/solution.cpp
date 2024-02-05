class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i <= n; ++i) {
            int h = i < n ? nums[i] : 0;
            int w = 0;

            while (!st.empty() && st.top().second >= h) {
                w += st.top().first;
                if (i - w <= k && i - 1 >= k) {
                    ans = max(ans, w * st.top().second);
                }
                st.pop();
            }
            st.push({w + 1, h});
        }

        return ans;
    }
};
