class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int l = 0; int r = 0;

        int n = nums.size();

        int ans = 1;

        for(int i=0; i<n; i++) {
            int lim = nums[i] + 2 * k;

            auto it = nums.begin();

            int j = (int)((it = upper_bound(begin(nums) + i, end(nums), lim)) == nums.end() ? n : it - begin(nums));

            ans = max(ans, j - i);
        }

        return ans;
    }
};
