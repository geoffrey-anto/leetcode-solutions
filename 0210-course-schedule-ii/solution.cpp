class Solution {
public:
    bool dfs(int n, vector<vector<int>>& g, vector<int> &vis, vector<int> &path, vector<int> &ans) {
        vis[n] = 1;
        path[n] = 1;


        for(auto &node: g[n]) {
            if(!vis[node]) {
                if(dfs(node, g, vis, path, ans) == true) return true;
            } else if (path[node]) {
                return true;
            }
        }

        ans.push_back(n);
        
        path[n] = 0;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n, vector<int>());

        for(auto &edj: p) {
            graph[edj[0]].push_back(edj[1]);
        }

        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> path(n, 0);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(i, graph, vis, path, ans)) return {};
            }
        }

        return ans;
    }
};
