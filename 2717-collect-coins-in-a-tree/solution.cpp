// class DSU {
// private:
//   vector<int> parent, rank, size;
//   int _n;

// public:
//   DSU(int n) {
//     this->_n = n;

//     parent.resize(n);
//     rank.resize(n);
//     size.resize(n);

//     for (int i = 0; i < n; i++) {
//       parent[i] = i;
//       rank[i] = size[i] = 1;
//     }
//   }

//   int findUPar(int n) {
//     if (parent[n] != n) {
//       parent[n] = findUPar(parent[n]);
//     }

//     return parent[n];
//   }

//   bool unionByRank(int u, int v) {
//     int ulp_u = findUPar(u);
//     int ulp_v = findUPar(v);

//     if (ulp_u == ulp_v) {
//       return false;
//     }

//     if (rank[ulp_u] > rank[ulp_v]) {
//       parent[ulp_v] = ulp_u;
//     } else if (rank[ulp_u] < rank[ulp_v]) {
//       parent[ulp_u] = ulp_v;
//     } else {
//       parent[ulp_v] = ulp_u;
//       rank[ulp_u]++;
//     }

//     return true;
//   }

//   bool unionBySize(int u, int v) {
//     int ulp_u = findUPar(u);
//     int ulp_v = findUPar(v);

//     if (ulp_u == ulp_v)
//       return false;
//     if (size[ulp_u] < size[ulp_v]) {
//       parent[ulp_u] = ulp_v;
//       size[ulp_v] += size[ulp_u];
//     } else {
//       parent[ulp_v] = ulp_u;
//       size[ulp_u] += size[ulp_v];
//     }

//     return true;
//   }

//   void reset(int node) {
//     parent[node] = node;
//     rank[node] = 1;
//   }

//   int getNoOfComponents() {
//     int ans = 0;

//     for (int i = 0; i < _n; i++) {
//       if (parent[i] == i) {
//         ans++;
//       }
//     }

//     return ans;
//   }
// };

// class Solution {
// public:
//     int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
//         if(accumulate(begin(coins), end(coins), 0) == 0) {
//             return 0;
//         }

//         if(edges.size() == 0) {
//             return 0;
//         }

//         vector<int> leaves;
//         int n = coins.size();

//         vector<vector<int>> adj(n);

//         DSU* dsu = new DSU(n);

//         vector<int> in(n, 0);

//         set<int> nodes;

//         for(int i=0; i<n; i++) {
//             nodes.insert(i);
//         }

//         for(auto &edge: edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//             in[edge[0]]++;
//             in[edge[1]]++;

//             dsu->unionByRank(edge[0], edge[1]);
//         }

//         for(int i=0; i<n; i++) {
//             if(in[i] == 1 and coins[i] == 0) {
//                 dsu->reset(i);
//                 nodes.erase(i);
//             }
//         }

//         for(int i=0; i<n; i++) {
//             for(auto j: adj[i]) {
//                 if(in[j] == 1 and coins[j] == 1) {
//                     dsu->reset(i);
//                     dsu->reset(j);
//                     nodes.erase(i);
//                     nodes.erase(j);
//                 }
//             }
//         }

//         return nodes.size();
//     }
// };

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        // Build graph
        int n = coins.size();
        int remaining_nodes = n;
        vector<unordered_set<int>> g(n);
        for (vector<int>& e: edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }

        // Step 1
        queue<int> empty_leaves;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1 && !coins[i]) {
                empty_leaves.push(i);
            }
        }
        while (empty_leaves.size()) {
            int i = empty_leaves.front();
            empty_leaves.pop();
            --remaining_nodes;

            for (int nb: vector<int>(g[i].begin(), g[i].end())) {
                g[i].erase(nb);
                g[nb].erase(i);
                if (g[nb].size() == 1 && !coins[nb]) {
                    empty_leaves.push(nb);
                }
            }
        }

        // Step 2
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) {
                leaves.push(i);
            }
        }
        for (int trim = 0; trim < 2; ++trim) {
            int size = leaves.size();
            for (int i = 0; i < size; ++i) {
                int cur = leaves.front();
                leaves.pop();
                --remaining_nodes;

                for (int nb: vector<int>(g[cur].begin(), g[cur].end())) {
                    g[cur].erase(nb);
                    g[nb].erase(cur);
                    if (g[nb].size() == 1) {
                        leaves.push(nb);
                    }
                }
            }
        }

        // Step 3
        return max(0, (remaining_nodes - 1) *2);
    }
};
