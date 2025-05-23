// class Solution {
// public:
//     pair<int, int> depth(int node, vector<vector<int>>& adj, vector<bool>& vis) {
//         vis[node] = true;

//         pair<int, int> d = {0, 0};

//         for(auto n: adj[node]) {
//             if(!vis[n]) {
//                 auto x = depth(n, adj, vis);
//                 x.first += 1;
//                 d = max(make_pair(d.first, x.second), x);
//             }
//         }

//         return d;
//     }

//     int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
//         int n = edges1.size(); int m = edges2.size();

//         vector<vector<int>> adj1(n+1), adj2(m+1);

//         for(auto edge: edges1) {
//             adj1[edge[0]].push_back(edge[1]);
//             adj1[edge[1]].push_back(edge[0]);
//         }

//         for(auto edge: edges2) {
//             adj2[edge[0]].push_back(edge[1]);
//             adj2[edge[1]].push_back(edge[0]);
//         }

//         if(n == 0 && m == 0) {
//             return 1;
//         } else if(n == 0 or m == 0) {
//             return 2;
//         }

//         vector<bool> vis1(n), vis2(m);

//         auto d1 = depth(0, adj1, vis1);
//         auto d2 = depth(0, adj2, vis2);

//         cout << d1.first << " " << d1.first << endl;
//         cout << d2.first << " " << d2.first << endl;

//         // return (d1 / 2) + d2 / 2 + 1;
//         return 0;
//     }
// };

class Solution {
private:
    void build(vector<vector<int>>& adj, vector<vector<int>>& edges, int n){
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    }
    void get(pair<int, int>& p, vector<vector<int>>& adj, int node, int dis, vector<int>& vis){
        int d = p.second;
        vis[node] = 1;
        if(dis>d){
            p.second = dis;
            p.first = node;
        }
        for(auto it: adj[node]){
            if(!vis[it]){
                get(p, adj, it, dis+1, vis);
            }
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adj1(n), adj2(m);

        build(adj1, edges1, n);
        build(adj2, edges2, m);

        vector<int>vis(n);
        pair<int, int> p1 = {-1, INT_MIN};
        get(p1, adj1, 0, 0, vis);

        vis = vector<int>(n, 0);
        pair<int, int> p2 = {-1, INT_MIN};
        get(p2, adj1, p1.first, 0, vis);

        int d1 = p2.second;

        p1 = {-1, INT_MIN};
        vis = vector<int>(m, 0);
        get(p1, adj2, 0, 0, vis);
        p2 = {-1, INT_MIN};
        vis = vector<int>(m, 0);
        get(p2, adj2, p1.first, 0, vis);

        int d2 = p2.second;
        if(edges1.empty()) d1 = 0;
        if(edges2.empty()) d2 = 0;

        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};
