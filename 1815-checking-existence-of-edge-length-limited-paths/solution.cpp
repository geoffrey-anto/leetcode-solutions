class DSU {
    public:
    vector<int> rank;
    vector<int> parent;

    DSU(int n) {
        rank = vector<int>(n, 0);
        parent = vector<int>(n, 0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int n) {
        if(parent[n] == n) {
            return n;
        }

        return parent[n] = findUPar(parent[n]);
    }

    bool isSameParent(int u, int v) {
        return findUPar(u) == findUPar(v); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_v == ulp_u) {
            return;
        } else if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        int x = 0;
        for(auto &i: q) {
            i.push_back(x++);
        }
        sort(begin(e), end(e), [&](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        sort(begin(q), end(q), [&](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        DSU dsu = DSU(n);

        vector<bool> ans(q.size(), false);

        int c = 0;

        for(auto &i: q) {
            while(c < e.size() && e[c][2] < i[2]) {
                dsu.unionByRank(e[c][0], e[c][1]);
                c++;
            }

            ans[i[3]] = dsu.isSameParent(i[0], i[1]);
        }

        return ans;
    }
};
