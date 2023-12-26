class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

        for(auto &flight: flights) {
            adj[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }   

        queue<pair<int, pair<int, int>>> pq;

        vector<int> dist(n, 1e9);

        dist[src] = 0;

        pq.push({0, {src, 0}});

        while(!pq.empty()) {
            auto top = pq.front();
            pq.pop();

            int sz = top.first;
            int node = top.second.first;
            int d = top.second.second;


            if(sz > k) {
                continue;
            }

            for(auto &n: adj[node]) {
                int i = n.first;
                int w = n.second;

                if(d + w < dist[i] && sz <= k) {
                    dist[i] = d + w;
                    pq.push({sz+1, {i, d + w}});
                }
            }
        }

        if(dist[dst] == 1e9) {
            return -1;
        }

        return dist[dst];
    }
};