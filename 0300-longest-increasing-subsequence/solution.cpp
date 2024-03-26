class Solution {
public:
    int f(int curr, int prev, int n, vector<int> &nums, vector<vector<int>> &dp) {
        if(curr == n) {
            return 0;
        }

        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        int notTake = 0 + f(curr+1, prev, n, nums, dp);

        int take = 0;
        if(prev == -1 or nums[curr] > nums[prev]) {
            take = 1 + f(curr+1, curr, n, nums, dp);
        }

        return dp[curr][prev+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));

        return f(0, -1, n, nums, dp);
    }
};
