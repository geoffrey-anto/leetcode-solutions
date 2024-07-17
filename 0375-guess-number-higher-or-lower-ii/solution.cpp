class Solution {
public:
    // int f(int i, int j, int n) {
    //     if(i == j) {
    //         return 0;
    //     }

    //     int ans = INT_MAX;

    //     for(int curr=i; curr<=j; curr++) {
    //         int take = curr + max(f(i, curr-1, n), f(curr+1, j, n));

    //         ans = min(ans, curr);
    //     }

    //     return ans;
    // }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int i=n; i>=1; i--) {
            for(int j=i; j <= n; j++) {
                if(i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                
                int ans = INT_MAX;

                for(int curr=i; curr<=j; curr++) {
                    int take = curr + max(dp[i][curr-1], dp[curr+1][j]);

                    ans = min(ans, take);
                }

                dp[i][j] = ans;
            }
        }

        return dp[1][n];
    }
};
