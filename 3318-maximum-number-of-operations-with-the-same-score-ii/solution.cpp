class Solution {
public:   
    int f(int l, int r, int sum, vector<int>& nums, vector<vector<int>> &dp) {
        if(l >= r) {
            return 0;
        }
        
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        
        // there can be 3 ways 
        int ans = 0;
        
        if(sum == (nums[l] + nums[l+1])) {
            ans = max(ans, 1 + f(l+2, r, sum , nums, dp));
        } 
        if(sum == (nums[r] + nums[r-1])) {
            ans = max(ans, 1 + f(l, r-2, sum, nums, dp));
        }
        if(sum == (nums[l] + nums[r])) {
            ans = max(ans, 1 + f(l+1, r-1, sum, nums, dp));
        }   

        
        return dp[l][r] = ans;
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        
        int ans = 0;
        
        ans = max(ans, 1+f(1, n-2, nums[0] + nums[n-1], nums, dp));
        ans = max(ans, 1+f(0, n-3, nums[n-1] + nums[n-2], nums, dp));
        ans = max(ans, 1+f(2, n-1, nums[0] + nums[1], nums, dp));
        
        
        return ans;
    }
};
