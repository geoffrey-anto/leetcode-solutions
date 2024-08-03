class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long incr = 0, decr = 0, ops = 0;

        vector<int> diffs(n, 0);

        for(auto i=0; i<n; i++) {
            diffs[i] = target[i] - nums[i];
        }

        for (int i = 0; i < n; i++) {

            if (diffs[i] > 0) {
                if (incr < diffs[i])
                    ops += diffs[i] - incr;
                incr = diffs[i];
                decr = 0;
            } else if (diffs[i] < 0) {
                if (diffs[i] < decr)
                    ops += decr - diffs[i];
                decr = diffs[i];
                incr = 0;
            } else {
                incr = decr = 0;
            }
        }

        return ops;
    }
};
