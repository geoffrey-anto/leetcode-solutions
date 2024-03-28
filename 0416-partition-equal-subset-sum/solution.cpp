class Solution {
public:
    bool f(int i, int sum, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(sum == target) {
            return true;
        }

        if(sum > target) {
            return false;
        }

        if(i == nums.size()) {
            return false;
        }

        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        int nt = f(i+1, sum, target, nums, dp);

        int t = f(i+1, sum + nums[i], target, nums, dp);

        return dp[i][sum] = nt or t;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size()+1, vector<int> (sum / 2, -1));
        if(sum % 2 != 0) {
            return false;
        }

        return f(0, 0, sum / 2, nums, dp);
    }
};
