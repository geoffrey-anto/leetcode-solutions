class Solution {
public:
    vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>> &adj, vector<int> &dis) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({
            0, src
        });
        
        vector<int> ans(n, -1);

        while(!q.empty()) {
            auto top = q.top();
            q.pop();
            
            int d = top.first;
            int node = top.second;
            
            if (ans[node] != -1) continue;
            
            ans[node] = d;

            for(auto &a: adj[node]) {
                int next = a.first;
                int w = a.second;

                if(d + w < dis[next]) {
                    q.push({
                        d + w, next
                    });
                }
            }
        }

        return ans;
    }
    
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        auto ans = dijkstra(0, n, adj, disappear);
        
        for(auto &i: ans) {
            if(i == 1e9) {
                i = -1;
            }
        }
        
        return ans;
    }
};
