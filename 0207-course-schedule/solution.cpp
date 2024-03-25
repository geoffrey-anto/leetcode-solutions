class Solution {
public:
    // bool dfs(int n, vector<vector<int>>& g, vector<int> &vis, vector<int> &path) {
    //     vis[n] = 1;
    //     path[n] = 1;

    //     for(auto &node: g[n]) {
    //         if(!vis[node]) {
    //             if(dfs(node, g, vis, path) == true) return true;
    //         } else if (path[node]) {
    //             return true;
    //         }
    //     }

    //     path[n] = 0;
    //     return false;
    // }

    bool canFinish(int n, vector<vector<int>>& p) {
        // vector<vector<int>> graph(n, vector<int>());

        // for(auto &edj: p) {
        //     graph[edj[0]].push_back(edj[1]);
        // }

        // vector<int> vis(n, 0);
        // vector<int> path(n, 0);

        // for(int i=0; i<n; i++) {
        //     if(!vis[i]) {
        //         if(dfs(i, graph, vis, path)) return false;
        //     }
        // }

        // return true;

        vector<vector<int>> adj(n, vector<int>());
        vector<int> in(n, 0);

        for(auto &edge: p) {
            adj[edge[0]].push_back(edge[1]);
            in[edge[1]]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++) {
            if(!in[i]) {
                q.push(i);
            }
        }

        int cnt = 0;

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            cnt++;

            for(auto i: adj[top]) {
                in[i]--;

                if(in[i] == 0) {
                    q.push(i);
                }
            }
        }

        return cnt == n;
    }
};
