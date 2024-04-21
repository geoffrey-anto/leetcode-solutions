class Solution {
public:
    bool dfs(int n, vector<vector<int>> &adj, vector<int> &vis, int dest) {
        vis[n] = true;

        if(n == dest) {
            return true;
        }

        for(auto &i: adj[n]) {
            if(!vis[i]){
                auto res = dfs(i, adj, vis, dest);
                if(res) {
                    return true;
                }
            }
        }

        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n, 0);

        vector<vector<int>> adj(n);

        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        auto res = dfs(source, adj, vis, destination);

        return res;
    }
};
