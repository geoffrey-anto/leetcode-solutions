class Solution {
public:
    int m, n;

    int dp[100][5000];

    int solve(vector<vector<int>>& mat, int idx, int s, int& target)
    {
        if(idx == m)
        {
            return abs(s - target);
        }
        
        if(dp[idx][s] != -1) return dp[idx][s];
        
        int mn = INT_MAX;

        for(int i=0; i<n; i++)
        {
            mn = min(mn, solve(mat, idx+1, s+mat[idx][i], target));
        }
        return dp[idx][s] = mn;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.size();
        n = mat[0].size();

        memset(dp, -1, sizeof(dp));
        return solve(mat, 0, 0, target);;
    }
};
