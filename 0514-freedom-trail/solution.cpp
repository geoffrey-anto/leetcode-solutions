class Solution {
public:
    int f(int pos, int k, string &ring, string &key, int n, vector<vector<int>> &dp) {
        if(k == key.size()) {
            return 0;
        }

        if(dp[pos][k] != -1) return dp[pos][k];

        int res = INT_MAX;

        int i = pos;

        for(int lim = 0; lim < n; lim++) {
            int iC = i % n;

            if(ring[iC] == key[k]) {
                int cost = min(lim, n-lim);

                int ans = cost + 1 + f(iC, k+1, ring, key, n, dp);

                res = min(ans, res);
            }

            i++;
        }

        return dp[pos][k] = res;
    }

    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(ring.size()+1, vector<int>(key.size()+1, -1));
        return f(0, 0, ring, key, ring.size(), dp);
    }
};
