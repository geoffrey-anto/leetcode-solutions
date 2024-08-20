class Solution {
public:
    vector<int> s;
    vector<vector<int>> dp;
    int stoneGameII(vector<int>& piles) {
        if(piles.size() == 1) {
            return piles.back();
        }
        
        s = vector<int> (piles.size());

        int n = piles.size();

        dp = vector<vector<int>>(n+1, vector<int> (n+1, 0));

        s[n - 1] = piles[n - 1];

        for(int i=n-2; i>=0; i--) {
            s[i] = piles[i] + s[i+1]; 
        }

        for(int i=n-1; i>=0; i--) {
            for(int m=n-1; m>=0; m--) {
                if(i + 2 * m >= piles.size()) {
                    dp[i][m] = s[i];
                }
            }
        }

        for(int i=n-1; i>=0; i--) {
            for(int m=n-1; m>=0; m--) {
                int mn = 1e8;

                for(int x=1; x<=2*m; x++) {
                    if(i+x <= n)
                        mn = min(mn, dp[i+x][max(m, x)]);
                }

                dp[i][m] = (s[i] - mn);
            }
        }

        return dp[0][1];
    }
};
