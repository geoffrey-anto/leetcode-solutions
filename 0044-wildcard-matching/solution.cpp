class Solution {
public:
    bool f(int i, int j, int n, int m, string &s, string &p, vector<vector<int>> &dp) {
        if(j < 0 && i < 0) return true;
        if(j < 0 && i >= 0) return false;

        if(i < 0 and j >= 0) {
            for(int x = 0; x <= j; x++) {
                if(p[x] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '?' or s[i] == p[j]) {
            return dp[i][j] = f(i-1, j-1, n, m, s, p, dp);
        }

        if(p[j] == '*') {
            return dp[i][j] = f(i, j-1, n, m, s, p, dp) | f(i-1, j, n, m, s, p, dp);
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f(n-1, m-1, n, m, s, p, dp);
    }
};
