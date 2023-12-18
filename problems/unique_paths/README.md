# Unique Paths

## Leetcode Link: [Unique Paths](https://leetcode.com/problems/unique-paths/)
### Language: C++

```cpp
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
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, dp);
    }
};```



