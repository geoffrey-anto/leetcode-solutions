# Best Time To Buy And Sell Stock

## Leetcode Link: [Best Time To Buy And Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
### Language: C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mn = prices[0];
        int profit = 0;
        int currCost = 0;

        for(int i=1; i<n; i++) {
            auto p = prices[i];
            currCost = p - mn;
            profit = max(profit, currCost);
            mn = min(mn, p);
        }

        return profit;
    }
};```



