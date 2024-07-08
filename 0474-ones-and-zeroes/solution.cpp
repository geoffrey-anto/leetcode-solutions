class Solution {
public:
    int f(int i, unordered_map<int, array<int, 2>>& strs, int m, int n, vector<vector<vector<int>>> &dp) {
        if(i == strs.size()) {
            return 0;
        }

        if(dp[i][n][m] != -1) {
            return dp[i][n][m];
        }

        int nt = 0 + f(i+1, strs, m, n, dp);

        int t = 0;

        int zcnt = strs[i][0];
        int ocnt = strs[i][1];

        if(zcnt <= m and ocnt <= n) {
            t = 1 + f(i+1, strs, m - zcnt, n - ocnt, dp);
        }

        return dp[i][n][m] = max(nt, t);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<int, array<int, 2>> s;

        for(int i=0; i<strs.size(); i++) {
            for(auto j: strs[i]) {
                s[i][j - '0']++;
            }
        }

        vector<vector<vector<int>>> dp(strs.size() + 2, vector<vector<int>>(n+2, vector<int> (m+2, -1)));

        return f(0, s, m, n, dp);
    }
};
