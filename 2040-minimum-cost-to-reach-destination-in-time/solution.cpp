class Solution {
public:
    int dp[1002][1002];
    int f(int i, int t, vector<vector<pair<int, int>>>& adj, vector<int>& passingFees, int maxT) {
        if(i == adj.size() - 1) {
            return 0;
        }

        if(dp[i][t] != -1) {
            return dp[i][t];
        }

        int ans = 1e8;


        for(auto n: adj[i]) {
            if(t + n.second <= maxT) {
                ans = min(ans, passingFees[n.first] + f(n.first, t + n.second, adj, passingFees, maxT));
            }
        }

        return dp[i][t] = ans;
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        vector<vector<pair<int, int>>> adj(passingFees.size());

        for(auto &edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }    

        memset(dp, -1, sizeof(dp));

        int res = f(0, 0, adj, passingFees, maxTime);

        if(res == 1e8) {
            return -1;
        }

        return passingFees[0] + res;
    }
};
