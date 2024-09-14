class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(begin(nums), end(nums));

        int n = nums.size();

        int ans = 0;

        if(nums[0] == mx) {
            ans++;
        }

        int res = 0;

        for(auto i=1; i<nums.size(); i++) {
            res = max(res, ans);

            if(nums[i] == mx) {
                ans ++;
            } else {
                ans = 0;
            }
        }

        res = max(res, ans);

        return res;
    }
};
