
class Solution {
    long long MOD = 1e9 + 7;
public:
    int f(int z, int o, int p, int limit, vector<vector<vector<int>>> &dp) {
        if(z == 0 and o == 0) {
            return 1;
        }
        
        if(z < 0 or o < 0) {
            return 0;
        }

        if(dp[z][o][p] != -1) {
            return dp[z][o][p];
        }

        long long ans = 0;

        if(p == 0) {
            for(int i=1; i<=limit; i++) {
                ans = ans + f(z, o-i, 1, limit, dp);
            }
        } else {
            for(int i=1; i<=limit; i++) {
                ans = ans + f(z-i, o, 0, limit, dp);
            }
        }

        return dp[z][o][p] = ans % MOD;
    }
    
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>> (one+1, vector<int>(3, -1)));

        long long ans = 0;

        for (int i = 1; i <= limit; i++) ans = ans + f(zero, one - i, 1, limit, dp);
        for (int i = 1; i <= limit; i++) ans = ans + f(zero - i, one, 0, limit, dp);

        return ans % MOD;
    }
};
