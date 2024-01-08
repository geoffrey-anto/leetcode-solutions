class Solution {
public:
    void dijktras(int i, vector<vector<pair<int, int>>> &adj, vector<vector<long long>> &dist) {
        queue<pair<long long, long long>> pq;

        pq.push({0, i});

        dist[i][i] = 0;

        while(!pq.empty()) {
            auto top = pq.front();
            pq.pop();

            long long d = top.first;
            long long node = top.second;

            for(auto n: adj[node]) {
                int u = n.first;
                int w = n.second;

                if(dist[i][u] > (d + w)) {
                    dist[i][u] = (d + w);
                    pq.push({dist[i][u], u});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();

        vector<vector<pair<int, int>>> adj(27, vector<pair<int, int>>());

        for(int i=0; i<original.size(); i++) {
            adj[original[i] - 'a'].push_back(make_pair(
                changed[i] - 'a',
                cost[i]
            ));
        }

        vector<vector<long long>> dist(27, vector<long long>(27, LLONG_MAX));

        for(auto i: original) {
            int v = i - 'a';
            dijktras(v, adj, dist);
        }

        long long ans = 0ll;

        for(int i=0; i<n; i++) {
            if(source[i] - 'a' == target[i] - 'a') {
                continue;
            }

            if(dist[ source[i] - 'a' ][ target[i] - 'a' ] == LLONG_MAX) {
                return -1;
            } else {
                ans += dist[ source[i] - 'a' ][ target[i] - 'a' ];
            }
        } 

        return ans;
    }
};
