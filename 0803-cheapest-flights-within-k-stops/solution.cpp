class Solution {
public:
    vector<int> dijkstraWithLimit(int src, int n, int lim, vector<vector<pair<int, int>>> &adj) {
        vector<int> dist(n, 1e9);

        //          sz       node d
        queue<pair<int, pair<int, int>>> q;

        dist[src] = 0;

        q.push({
            0, {
                src, 0
            }
        });

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            int sz = top.first;
            int node = top.second.first;
            int d = top.second.second;

            if(sz > lim) {
                continue;
            }

            for(auto a: adj[node]) {
                int next = a.first;
                int w = a.second;

                if(d + w < dist[next] && sz <= lim) {
                    dist[next] = d + w;

                    q.push({sz+1, {
                        next, d + w
                    }});
                }
            }
        }

        return dist;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &f: flights) {
            adj[f[0]].push_back({
                f[1], f[2]
            });
        }

        auto dist = dijkstraWithLimit(src, n, k, adj);

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
