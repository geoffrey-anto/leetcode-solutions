class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        pair<int, int> prev, curr;
        prev = {0,0};
        curr = {0,0};
        
        for(int i=n-1; i>=0; i--) {
            for(int b=0; b<2; b++) {
                if(b) {
                    curr.second = max(prev.first - prices[i], prev.second);
                } else {
                    curr.first = max(prev.second + prices[i] - fee, prev.first);
                }
                prev = curr;
            }
        }

        return prev.second;
    }
};