# Unique Paths Ii

## Leetcode Link: [Unique Paths Ii](https://leetcode.com/problems/unique-paths-ii/)
### Language: C++

```cpp
class Solution {
public:
    int f(int x, int y, int m, int n, vector<vector<int>>& nums,vector<vector<int>> &dp) {
        if(x == m-1 and y == n-1) {
            if (nums[x][y] == 1){
                return 0;
            }
            return 1;
        }

        if(x >= m  or y >= n) {
            return 0;
        }

        if(nums[x][y] == 1) return 0;
        
        if(dp[x][y] != -1) return dp[x][y];

        return dp[x][y] = f(x+1, y, m, n, nums,dp) + f(x, y+1, m, n, nums, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, obstacleGrid,dp);
    }
};```



