class Solution {
public:
    int timer = 1;
    vector<vector<int>> bridges;

    void dfs(int node, int parent, vector<vector<int>> &adj, int* vis, int* low, int* tin) {
        vis[node] = 1;
        low[node] = timer;
        tin[node] = timer;

        timer++;

        for(auto n: adj[node]) {
            if(n == parent) {
                continue;
            }

            if(!vis[n]) {
                dfs(n, node, adj, vis, low, tin);
                low[node] = min(low[node], low[n]);

                if(low[n] > tin[node]) {
                    bridges.push_back({n, node});
                }
            } else {
                low[node] = min(low[node], low[n]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto &conn: connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        int vis[n];
        memset(vis, 0, sizeof(vis));
        int low[n];
        int tin[n];

        dfs(0, -1, adj, vis, low, tin);

        return bridges;
    }
};
