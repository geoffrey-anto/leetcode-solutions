class Solution {
public:
    int MOD = 1e9+7;

    bool isValid(int prev, int curr, vector<int> &nums) {
        return prev == -1 or (nums[prev] % nums[curr] == 0) or (nums[curr] % nums[prev] == 0);
    }

    int f(int prev, int mask, int i, vector<int> &nums, vector<vector<int>> &dp) {
        if(i == nums.size()) {
            return 1;
        }

        if(dp[prev+1][mask] != -1) {
            return dp[prev+1][mask];
        }

        int ans = 0;

        for(int j=0; j<nums.size(); j++) {
            if(((1 << j) & mask) != 0) {
                continue;
            }

            if(isValid(prev, j, nums)) {
                ans = (ans + f(j, mask | (1 << j), i+1, nums, dp)) % MOD;
            }
        }

        return dp[prev+1][mask] = ans;
    }

    int specialPerm(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>((1 << (2 * 9 + 1)), -1));
        return f(-1, 0, 0, nums, dp);
    }
};
