class Solution {
public:
    int solve(vector<int> &nums, int i, vector<int> &dp) {
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int a = solve(nums, i-1, dp);
        int b = solve(nums, i-2, dp) + nums[i];

        return dp[i] = max(a, b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);

        return solve(nums, n-1, dp);
    }
};