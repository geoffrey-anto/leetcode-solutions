class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        vector<int> cpy(begin(nums), end(nums));

        cpy.insert(end(cpy), begin(nums), end(nums));

        long long sum = accumulate(begin(nums), end(nums), 0ll);

        long long l = 0, r = 0;

        long long curr = 0ll;

        long long additional = (target / sum) * nums.size();
        long long ans = LLONG_MAX;

        target = target % sum;

        while(r < (long long)(2 * nums.size())) {
            curr += cpy[r];

            while(curr > target) {
                curr -= cpy[l];
                l++;
            }

            if(target == curr) {
                ans = min(ans, (long long)(r - l + 1));
            }

            r++;    
        }

        if(ans == LLONG_MAX) return -1;

        return ans + additional;
    }
};
