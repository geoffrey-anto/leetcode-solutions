# Best Time To Buy And Sell Stock Iii

## Leetcode Link: [Best Time To Buy And Sell Stock Iii](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
### Language: C++

```cpp
class Solution {
public:
    int f(int i, int p, int buy,int n, vector<int>& prices, vector<vector<vector<int>>> &dp, int x) {

        if(i==n || x == 2) {
            return 0;
        }
        
        if(dp[i][buy][x] != -1) return dp[i][buy][x];

        int prof = 0;

        if(buy) {
            int buy = f(i+1, p, 0, n, prices, dp, x) - prices[i];
            int notBuy = f(i+1, p, 1, n, prices, dp, x);
            prof = max(buy, notBuy);
        } else {
            int sell = f(i+1, p, 1, n, prices, dp, x+1) + prices[i];
            int notSell = f(i+1, p, 0, n, prices, dp, x);
            prof = max(sell, notSell);
        }

        return dp[i][buy][x] = prof;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                for(int x=1; x<3; x++) {
                    if(j==1) {
                        curr[j][x] = max(prev[0][x] - prices[i], prev[1][x]);
                    } else {
                        curr[j][x] = max(prev[1][x-1] + prices[i], prev[0][x]);
                    }
                }
            }
            prev = curr;
        }

        return prev[1][2];
    }
};```



