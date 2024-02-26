class Solution {
public:
    map<pair<int, int>, bool> dp;
    bool f(int i, int k, vector<int>& stones, int n) {
        if(i == n-1) {
            return true;
        }

        if(i >= n) {
            return false;
        }

        if(dp.count({i, k}) > 0) return dp[{i, k}];

        bool ans = false;

        for(int idx=i+1; idx<n; idx++) {
            if((stones[idx] - stones[i]) == (k)) {
                ans = ans or f(idx, k, stones, n);
            } else if((stones[idx] - stones[i]) == (k+1)) {
                ans = ans or f(idx, k+1, stones, n);
            } else if((stones[idx] - stones[i]) == (k-1)) {
                ans = ans or f(idx, k-1, stones, n);
            }
        }

        return dp[{i, k}] = ans;
    }
    bool canCross(vector<int>& stones) {
        return f(0, 0, stones, stones.size());
    }
};
