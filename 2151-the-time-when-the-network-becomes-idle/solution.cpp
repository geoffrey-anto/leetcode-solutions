class Solution {
public:
    vector<int> dij(int n, vector<vector<pair<int, int>>> & adj, int src) {
        vector<int> dist(n, 1e9);

        queue<pair<int, int>> q;

        q.push({src, 0});

        dist[src] = 0;

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            int node = top.first;
            int d = top.second;

            for(auto &i: adj[node]) {
                int next = i.first;
                int w = i.second;

                if(dist[next] > w + d) {
                    q.push({next, w+d});
                    dist[next] = w + d;
                }
            }
        }

        for(auto i: dist) {
            cout << i << " ";
        }
        cout << endl;

        return dist;
    }

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();

        vector<vector<pair<int, int>>> adj(n);

        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], 1});
            adj[i[1]].push_back({i[0], 1});
        }

        vector<int> dist = dij(n, adj, 0);

        int ans = 0;

        for(int i=1; i<n; i++) {
            int initialMessageRecvTime = dist[i] * 2;

            int noOfTimeNodeMessage = ceil((float)initialMessageRecvTime*1.0 / (float)patience[i]*1.0);

            ans = max(ans, (noOfTimeNodeMessage * patience[i]) + initialMessageRecvTime - patience[i]);
        }

        return ans + 1;
    }
};
