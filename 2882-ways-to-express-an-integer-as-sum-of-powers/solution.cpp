class Solution {
public:
    int MOD = 1e9+7;
    vector<long long> pows;
    
    // i -> min num we can take
    // k -> num to be powered
    // n -> sum left

    int f(int i, int k, int n, vector<vector<int>> &dp) {
        if(n == 0) {
            return 1;
        }

        if(dp[i][n] != -1) {
            return dp[i][n];
        }

        int r = 0;
        
        for(int j=i+1; pows[j]<=n; j++) {
            r = (r + f(j, k, n - pows[j], dp)) % MOD;
        }

        return dp[i][n] = r;
    }

    int numberOfWays(int n, int x) {
        pows = vector<long long> (n+2, 0ll);
        for(int i=0; i<=n+1; i++) {
            pows[i] = pow(i, x);
        }
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return f(0, x, n, dp);
    }
};
