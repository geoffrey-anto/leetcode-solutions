class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

        for(auto &t: times) {
            adj[t[0]-1].push_back({t[1]-1, t[2]});
        }

        priority_queue<pair<int, int>> pq;

        vector<int> dis(n, INT_MAX);

        dis[k-1] = 0;

        pq.push({0, k-1});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int node = top.second;

            for(auto &n: adj[node]) {
                int i = n.first;
                int w = n.second;

                if(d + w < dis[i]) {
                    dis[i] = d + w;
                    pq.push({dis[i], i});
                }
            }
        }

        int mx = 0;

        for(auto i: dis) {
            if(i == INT_MAX){
                return -1;
            }
            mx = max(mx, i);
        }

        return mx;
    }
};
