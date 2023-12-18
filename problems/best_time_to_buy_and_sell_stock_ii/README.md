# Best Time To Buy And Sell Stock Ii

## Leetcode Link: [Best Time To Buy And Sell Stock Ii](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
### Language: C++

```cpp
// class Solution {
// public:
//     int f(int i, int p, int buy,int n, vector<int>& prices, vector<vector<int>> &dp) {

//         if(i==n) {
//             return 0;
//         }
        
//         if(dp[i][buy] != -1) return dp[i][buy];

//         int prof = 0;

//         if(buy) {
//             int buy = f(i+1, p, 0, n, prices, dp) - prices[i];
//             int notBuy = f(i+1, p, 1, n, prices, dp);
//             prof = max(buy, notBuy);
//         } else {
//             int sell = f(i+1, p, 1, n, prices, dp) + prices[i];
//             int notSell = f(i+1, p, 0, n, prices, dp);
//             prof = max(sell, notSell);
//         }

//         return dp[i][buy] = prof;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1, vector<int> (2, -1));
//         return f(0, 0, 1, n, prices, dp);
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));
        pair<int, int> prev, curr;
        prev = {0,0};
        curr = {0,0};
        
        for(int i=n-1; i>=0; i--) {
            for(int b=0; b<2; b++) {
                if(b) {
                    curr.second = max(prev.first - prices[i], prev.second);
                } else {
                    curr.first = max(prev.second + prices[i], prev.first);
                }
                prev = curr;
            }
        }

        return prev.second;
    }
};```



