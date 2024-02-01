class Solution {
public:
    int dfs(int n, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &q, vector<int> &ans){
        if(vis[n]) {
            return ans[n];
        }

        vis[n] = true;
        pair<int, int> x = {q[n], n};

        for(auto &node: adj[n]) {
            int nextLoudest = dfs(node, adj, vis, q, ans);

            if(q[nextLoudest] < x.first) {
                x.first = q[nextLoudest];
                x.second = nextLoudest;
            }
        }

        ans[n] = x.second;

        return ans[n];
    }
    vector<int> loudAndRich(vector<vector<int>>& arr, vector<int>& q) {
        int n = q.size();
        vector<vector<int>> adj(n, vector<int>());

        for(auto &i: arr) {
            adj[i[1]].push_back(i[0]);
        }


        vector<int> ans(n);
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, q, ans);
            }
        }

        return ans;
    }
};
