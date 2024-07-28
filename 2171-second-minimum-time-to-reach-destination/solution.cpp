// class Solution {
// public:
//     int dijkstra(int src, int n, vector<vector<pair<int, int>>> &adj, int time, int wait) {
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//         int cnt = 0;
//         vector<int> vis(n+1, 0);

//         q.push({0, src});

//         int dest = n;

//         int depth = 0;

//         while (!q.empty()) {
//             int sz = q.size();
//             depth++;

//             for(int i=0; i<sz; i++) {
//                 auto top = q.top();
//                 q.pop();

//                 int d = top.first;
//                 int node = top.second;
//                 cout << node << endl;
                
//                 vis[node]++;

//                 if(node == dest) {
//                     cnt++;
//                 }

//                 if(cnt == 2) {
//                     return d;
//                 }

//                 if(vis[node] > 2) {
//                     continue;
//                 }

//                 for (auto a : adj[node]) {
//                     int next = a.first;
//                     int w = a.second;

//                     q.push({d + w + ((next != dest and cnt != 1) ? wait : 0), next});
//                 }
//             }
//         }

//         return -1;
//     }

//     int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
//         vector<vector<pair<int, int>>> adj(n+1);

//         for(auto &i: edges) {
//             adj[i[0]].push_back({i[1], time});
//             adj[i[1]].push_back({i[0], time});
//         }

//         int ans = dijkstra(1, n, adj, time, change);

//         return ans;
//     }
// };

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, list<int>> g;
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});

        vector<int> uniqueVisit(n + 1, 0); 
        vector<int> dis(n + 1, -1);
        
        while (!q.empty()) {
            auto [t, node] = q.top();
            q.pop(); 
            
            if (dis[node] == t || uniqueVisit[node] >= 2) {
                continue;
            }
            
            uniqueVisit[node]++;
            dis[node] = t;
            
            if (node == n && uniqueVisit[node] == 2) {
                return dis[node];
            }
            
            if ((t / change) % 2 != 0) {
                t = (t / change + 1) * change;
            }
            
            for (int nei : g[node]) {
                q.push({t + time, nei});
            }
        }
        
        return -1;
    }
};
