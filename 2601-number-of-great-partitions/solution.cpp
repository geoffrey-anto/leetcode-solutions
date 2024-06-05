class Solution {
public:
    int MOD = 1e9+7;

    long long  f(int i, long long s, vector<int> &nums, int k, long long sum, vector<vector<long long>> &dp) {
        if(s >= k) {
            return 0;
        }
        
        if(i == nums.size()) {
            return 1;
        } 

        if(dp[i][s] != -1) {
            return dp[i][s];
        } 

        long long t = f(i+1, s+nums[i], nums, k, sum, dp);
        long long nt = f(i+1, s, nums, k, sum, dp);


        return dp[i][s] = (nt + t) % MOD;
    }
    
    int countPartitions(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        if (sum < 2 * k) return 0;

        int n = nums.size();

        vector<vector<long long>> dp(n+1, vector<long long>(k+2, -1));

        long long ss = 1;

        for(int i=1; i<=n; i++) {
            ss = (ss * 2ll) % MOD;
        }

        return (ss - 2 * f(0, 0, nums, k, sum, dp) + MOD) % MOD;
    }
};
