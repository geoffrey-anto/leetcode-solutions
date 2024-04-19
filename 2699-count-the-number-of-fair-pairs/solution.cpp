class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));

        int n = nums.size();

        long long ans = 0;

        deque<int> nums_c;

        for(auto i: nums) {
            nums_c.push_back(i);
        }

        for(int i=0; i<n; i++) {
            nums_c.pop_front();
            int l = lower - nums[i];
            int r = upper - nums[i];

            long long sz = (upper_bound(nums_c.begin(), nums_c.end(), r)) - (lower_bound(nums_c.begin(), nums_c.end(), l));

            ans += sz;
        }

        return ans;
    }
};
