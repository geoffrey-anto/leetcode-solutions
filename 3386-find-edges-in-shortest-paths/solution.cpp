class Solution {
public:
    vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>> &adj) {
        vector<int> dist(n, 1e9);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        dist[src] = 0;

        q.push({
            0, src
        });

        vector<bool> vis(n, false);

        while(!q.empty()) {
            auto top = q.top();
            q.pop();

            if(vis[top.second]) {
                continue;
            }

            int d = top.first;
            int node = top.second;

            for(auto &a: adj[node]) {
                int next = a.first;
                int w = a.second;

                if(d + w < dist[next]) {
                    dist[next] = d + w;

                    q.push({
                        d + w, next
                    });
                }
            }

            vis[node] = true;
        }

        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        vector<int> dist = dijkstra(0, n, adj);
        vector<int> dist2 = dijkstra(n-1, n, adj);

        vector<bool> ans(edges.size(), false);
        int j = 0;

        for(auto &i: edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];

            if(dist[u] + dist2[v] + w == dist[n-1]) {
                ans[j] = true;
            }

            if(dist[v] + dist2[u] + w == dist[n-1]) {
                ans[j] = true;
            }

            j++;
        }

        return ans;
    }
};
