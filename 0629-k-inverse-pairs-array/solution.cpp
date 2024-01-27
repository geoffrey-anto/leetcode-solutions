class Solution {
public:
    int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {1};

        for (int N = 1; N <= n; N++) {
            for (int K = 0; K <= k; K++) {
                int v = min(K, N - 1);
                for (int i = 0; i <= v; i++)  {
                    dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % MOD;
                }
            }
        }
            
        return dp[n][k];
    }
};
