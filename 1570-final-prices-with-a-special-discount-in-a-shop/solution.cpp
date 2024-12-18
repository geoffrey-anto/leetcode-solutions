class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        vector<int> ans(n, 0);

        for(int i=0; i<n; i++) {
            int curr = prices[i];
            int sum = curr + 0;

            for(int j=i+1; j<n; j++) {
                if(prices[j] <= curr) {
                    sum = sum - prices[j];
                    break;
                }
            }

            ans[i] = sum;
        }

        return ans;
    }
};
