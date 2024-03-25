// TLE
// class Solution {
// public:
//     int f(int x, int y, int m, int n) {
//         if(x == m-1 and y == n-1) {
//             return 1;
//         }

//         if(x >= m  or y >= n) {
//             return 0;
//         }

//         return f(x+1, y, m, n) + f(x, y+1, m, n);
//     }
//     int uniquePaths(int m, int n) {
//         return f(0, 0, m, n);
//     }
// };

// Memoization
class Solution {
public:
    int f(int x, int y, int m, int n, vector<vector<int>> &dp) {
        if(x == m-1 and y == n-1) {
            return 1;
        }

        if(x >= m  or y >= n) {
            return 0;
        }

        if(dp[x][y] != -1) return dp[x][y];

        return dp[x][y] = f(x+1, y, m, n, dp) + f(x, y+1, m, n, dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[0][0] = 1;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
