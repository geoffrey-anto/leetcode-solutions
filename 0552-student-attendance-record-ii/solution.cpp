class Solution {
public:
    int MOD = 1e9+7;
    long long f(int i, int l, int a, int n, vector<vector<vector<long long>>> &dp) {
        if(i == n) {
            return 1;
        }

        if(dp[i][l][a] != -1) {
            return dp[i][l][a];
        }

        long long ans = 0ll;

        ans = f(i+1, 0, a, n, dp);

        if(l < 2) {
            ans += f(i+1, l+1, a, n, dp);
        }
        
        if(a < 1) {
            ans += f(i+1, 0, a+1, n, dp);
        }

        return dp[i][l][a] = (ans % MOD);
    }

    int checkRecord(int n) {
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>> (4, vector<long long>(4, -1)));
        return f(0, 0, 0, n, dp);
    }
};
