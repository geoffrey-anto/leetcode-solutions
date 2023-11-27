class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                for(int x=1; x<k+1; x++) {
                    if(j==1) {
                        curr[j][x] = max(prev[0][x] - prices[i], prev[1][x]);
                    } else {
                        curr[j][x] = max(prev[1][x-1] + prices[i], prev[0][x]);
                    }
                }
            }
            prev = curr;
        }

        return prev[1][k];
    }
};
