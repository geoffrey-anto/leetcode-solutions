class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int f(int i, int fuel, int end, vector<int>& locations, int n) {
        if(fuel < 0) {
            return 0;
        }

        if(dp[i][fuel] != -1) return dp[i][fuel];

        long long ans = 0;

        for(int idx=0; idx<n; idx++) {
            if(i != idx) {
                ans = (ans + f(idx, fuel - abs(locations[i] - locations[idx]), end, locations, n)) % MOD;
            }
        }

        return dp[i][fuel] = (i == end ? 1 : 0) + ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp = vector<vector<int>>(locations.size()+1, vector<int>(fuel+1, -1));
        return f(start, fuel, finish, locations, locations.size());
    }
};
