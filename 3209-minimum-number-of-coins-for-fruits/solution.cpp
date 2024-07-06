class Solution {
public:
    int f(int i, int prev, vector<int> prices) {
        if(i >= prices.size()) {
            return 0;
        }

        int nt = INT_MAX;

        if(i <= prev) {
            nt = f(i+1, prev, prices);
        }

        int t = prices[i] + f(i+1, i+i+1, prices);

        return min(t, nt);
    }

    int minimumCoins(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>((2*n)+2, 0));

        for(int i=n-1; i>=0; i--) {
            for(int prev=n-1; prev>=-1; prev--) {
                int nt = INT_MAX;

                if(i <= prev) {
                    nt = dp[i+1][prev+1];
                }
                
                int t = prices[i] + dp[i+1][i+i+1+1];

                dp[i][prev+1] = min(t, nt);
            }
        }

        return dp[0][0];
    }
};
