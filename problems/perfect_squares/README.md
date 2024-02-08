# Perfect Squares

## Leetcode Link: [Perfect Squares](https://leetcode.com/problems/perfect-squares/)
### Language: C++

```cpp
class Solution {
public:
    int f(int i, int n, int sum, vector<int> &v, vector<vector<int>> &dp) {
        if(sum == n) {
            return 0;
        }

        if(sum > n) {
            return 1e6;
        }

        if(i == v.size()) {
            return 1e6;
        }

        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        int take = 1 + f(i, n, sum + v[i], v, dp);
        int nt =  0 + f(i+1, n, sum, v, dp);

        return dp[i][sum] = min(take, nt);
    }
    
    int numSquares(int n) {
        int i = 1;
        vector<int> v;
        vector<vector<int>> dp(317, vector<int> (n+1, -1));

        while(pow(i, 2) <= 10e4) {
            v.push_back(pow(i, 2));
            i++;
        }

        return f(0, n, 0, v, dp);
    }
};```



