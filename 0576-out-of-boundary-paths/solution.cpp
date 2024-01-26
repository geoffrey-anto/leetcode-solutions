class Solution {
    int dir[5] = {0, 1, 0, -1, 0};
    int dp[52][52][52];
    int MOD = 1e9 + 7;
public:
    int f(int i, int j, int k, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return 1;
        }

        if(k == 0) {
            return 0;
        }

        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int ans = 0;

        for(int d=0; d<4; d++) {
            ans = (ans + f(i+dir[d], j + dir[d+1], k-1, n, m))% MOD;
        }

        return dp[i][j][k] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return f(startRow, startColumn, maxMove, m, n);
    }
};
