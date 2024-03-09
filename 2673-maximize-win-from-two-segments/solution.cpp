class Solution {
public:
    int f(int i, int seg, int &k, vector<int>& p, vector<vector<int>>& dp) {
        if(i == p.size() || seg == 0) {
            return 0;
        }

        if(dp[i][seg] != -1) return dp[i][seg];

        int nt = f(i+1, seg, k, p, dp);

        int t = INT_MIN;

        if(seg) {
            auto nextIdx = lower_bound(begin(p), end(p), p[i] + k + 1);

            t = ((nextIdx - begin(p)) - i) + f(nextIdx - begin(p), seg-1, k, p, dp);
        }

        return dp[i][seg] = max(t, nt);
    }
    int maximizeWin(vector<int>& p, int k) {
        vector<vector<int>> dp(p.size()+1, vector<int>(3, -1));

        int ans = f(0, 2, k, p, dp);

        return ans;
    }
};
