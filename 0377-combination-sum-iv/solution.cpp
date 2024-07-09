class Solution {
public:
    int f(int s, vector<int>& nums, int target, vector<int> &dp) {
        if(s == target) {
            return 1;
        }

        if(s > target) {
            return 0;
        }

        if(dp[s] != -1) {
            return dp[s];
        }

        int t = 0;

        for(int j=0; j<nums.size(); j++) {
            t += f(s+nums[j], nums, target, dp);
        }

        return dp[s] = t;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 2, -1);
        return f(0, nums, target, dp);    
    }
};
