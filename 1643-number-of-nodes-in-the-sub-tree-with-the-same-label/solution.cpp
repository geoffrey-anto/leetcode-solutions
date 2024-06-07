class Solution {
public:
    vector<int> f(int n, vector<vector<int>> &adj, string &labels, vector<int> &ans, vector<bool> &vis) {
        vector<int> cnts(26, 0);

        cnts[labels[n] - 'a'] = 1;

       vis[n] = true;

        for(auto i: adj[n]) {
            if(vis[i]) {
                continue;
            }
            auto a = f(i, adj, labels, ans, vis);

            for(int i=0; i<26; i++) {
                cnts[i] += a[i];
            }
        }

        ans[n] = cnts[labels[n] - 'a'];

        return cnts;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);

        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> ans(n, 0);
        vector<int> cnt(26, 0);
        vector<bool> vis(n, false);

        cnt = f(0, adj, labels, ans, vis);

        return ans;
    }
};
