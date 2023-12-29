class Solution {
public:
    int f(int idx, int d, vector<int>& arr, int n, vector<vector<int>> &dp) {
        if(idx == n and d == 0) {
            return 0;
        }

        if((idx == n && d != 0) || (idx != n && d == 0)) {
            return INT_MAX;
        }

        if(dp[idx][d] != -1) {
            return dp[idx][d];
        } 

        int currMax = arr[idx];
        int ans = INT_MAX;

        for(int i=idx; i<n; i++) {
            int res = f(i+1, d-1, arr, n, dp);

            currMax = max(currMax, arr[i]);

            if(res == INT_MAX) {
                continue;
            }

            ans = min(ans, currMax + res);
        }

        return dp[idx][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        return f(0, d, jobDifficulty, n, dp);
    }
};