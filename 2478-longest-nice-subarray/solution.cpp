class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int curr = nums[0];

        int ans = 1;

        int l = 0; int r = 1;

        while(l <= r and r < nums.size()) {
            while(l != r and (nums[r] & curr) != 0) {
                curr -= nums[l];
                l++;
            }

            ans = max(ans, r - l + 1);

            curr += nums[r];
            r++;
        }

        return ans;
    }
};
