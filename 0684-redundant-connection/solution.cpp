class DSU {
    private:
    vector<int> parent, rank, size;
    int _n;

    public:
    DSU(int n) {
        this->_n = n;

        parent.resize(n);
        rank.resize(n);
        size.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = size[i] = 1;
        }
    }

    int findUPar(int n) {
        if(n == parent[n]) {
            return n;
        }

        return parent[n] = findUPar(parent[n]);
    } 

    bool unionByRank(int u, int v) {
        int ulp_u = parent[u];
        int ulp_v = parent[v];

        if(ulp_u == ulp_v) {
            return false;
        }

        if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if(rank[ulp_v] == rank[ulp_u]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

        return true;
    }

    bool unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return false;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

        return true;
    }

    int getNoOfComponents() {
        int ans = 0;
        
        for(int i=0; i<_n; i++) {
            if(parent[i] == i) {
                ans++;
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2, 0);

        DSU dsu = DSU(edges.size()+1);

        for(auto &edge: edges) {
            if(!dsu.unionBySize(edge[0], edge[1])) {
                ans = edge;
            }
        }

        return ans;
    }
};
