class Solution {
public:
    int f(int i, int j, string s, string t, vector<vector<int>> &dp) {
        if(j == 0) return 1;

        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) {
            // char are the same at si  and  tj

            int pick = f(i-1, j-1, s, t, dp);
            int notPick = f(i-1, j, s, t, dp);

            return dp[i][j] = pick + notPick;
        } 
        return dp[i][j] = f(i-1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<double> curr(m+1, 0);
        vector<double> prev(m+1, 0);

        prev[0] = 1;
        curr[0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    double pick = prev[j-1];
                    double notPick = prev[j];

                    curr[j] = pick + notPick;
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        // return f(n, m, s, t, dp);
        return prev[m];
    }
};