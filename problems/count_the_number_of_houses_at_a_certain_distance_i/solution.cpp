class Solution {
public:
    void bfs(int start, vector<vector<int>> &adj, vector<int> &ans, int n) {
        queue<int> q;
        q.push(start);

        int cnt = 0;

        vector<bool> vis(n+1, false);

        vis[start] = 1;

        while(!q.empty()) {
            int s = q.size();
            while(s) {
                int t = q.front();
                q.pop();
                for(auto node: adj[t]) {
                    if(!vis[node]) {
                        q.push(node);
                        vis[node] = true;
                        ans[cnt]++;
                    }
                }
                s--;
            }
            cnt++;
        }
    }

    void buildGraph(int n, int x, int y, vector<vector<int>>& adj) {
        for(int i=1; i<n; i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }

        if(x != y) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        } 
    }

    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n+1, vector<int>());

        buildGraph(n, x, y, adj);
        
        vector<int> ans(n, 0);

        for(int i=1; i<=n; i++) {
            bfs(i, adj, ans, n);
        }

        return ans;
    }
};