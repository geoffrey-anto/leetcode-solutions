class Solution {
public:
    int f(int i, vector<int> &arr, int k, vector<int> &dp, int n) {
        if(i == n) {
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int currMax = INT_MIN;
        int ans = INT_MIN;

        for(int j=i; j<i+k; j++) {
            if(j>=n) continue;
            currMax = max(currMax, arr[j]);
            int res = ((j-i+1) * currMax) + f(j+1, arr, k, dp, n);
            ans = max(ans, res);
        }

        return dp[i] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return f(0, arr, k, dp, n);
    }
};
