class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dungeon, int n, int m, vector<vector<int>> &dp) {
        if(i == n-1 && j == m-1) {
            if(dungeon[i][j] > 0) {
                return 1;
            } else {
                return abs(dungeon[i][j]) + 1;
            }
        }

        if(i >= n || j >= m) {
            return 1e9;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = - dungeon[i][j] + f(i, j+1, dungeon, n, m, dp);
        int down = - dungeon[i][j] + f(i+1, j, dungeon, n, m, dp);

        return dp[i][j] = (min(right, down) <= 0) ? 1 : min(right, down);
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));

        dp[n][m - 1] = 1;
        dp[n - 1][m] = 1;

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int right = - dungeon[i][j] + dp[i][j+1];
                int down = - dungeon[i][j] + dp[i+1][j];

                dp[i][j] = (min(right, down) <= 0) ? 1 : min(right, down);
            }
        }

        return dp[0][0];
    }
};
