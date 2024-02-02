class DSU {
    public:
    vector<int> rank;
    vector<int> parent;

    DSU(int n) {
        rank.resize(n);
        parent.resize(n);

        for(int i=0; i<n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int findUParent(int n) {
        if(parent[n] == n) {
            return n;
        }

        return parent[n] = findUParent(parent[n]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_v == ulp_u) {
            return;
        } else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
};


class Solution {
public:
    int kuskals(vector<pair<int, pair<pair<int, int>, int>>>& edges, int n, int ignoreEdge, int addEdge) {
        int sum = 0;

        DSU dsu = DSU(n);

        if(addEdge != -1) {
            sum += edges[addEdge].first;
            dsu.unionByRank(edges[addEdge].second.first.first, edges[addEdge].second.first.second);
        }

        for(int i=0; i<edges.size(); i++) {
            if(i == ignoreEdge) {
                continue;
            }
            int u = edges[i].second.first.first;
            int v = edges[i].second.first.second;
            int w = edges[i].first;

            if(dsu.findUParent(u) != dsu.findUParent(v)) {
                sum += w;
                dsu.unionByRank(u, v);
            }
        }

        for (int i = 0; i < n; i++) {
            if (dsu.findUParent(i) != dsu.findUParent(0)) return 1e9+7;
        }

        return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<pair<int, pair<pair<int, int>, int>>> e;
        int cnt = 0;
        for(auto &i: edges) {
            e.push_back(
                {i[2], {
                    {i[0], i[1]},
                    cnt
                }}
            );
            cnt++;
        }

        sort(e.begin(), e.end()); 

        pair<int, pair<pair<int, int>, int>> temp;

        int mstVal = kuskals(e, n, -1, -1);

        vector<vector<int>> ans(2, vector<int>());

        for(int i=0; i<e.size(); i++) {
            int id = e[i].second.second;
            if(kuskals(e, n, i, -1) > mstVal) {
                ans[0].push_back(id);
                continue;
            }

            int incl = kuskals(e, n, -1, i);
            
            if(incl == mstVal) {
                ans[1].push_back(id);
            }
        }

        return ans;
    }
};
