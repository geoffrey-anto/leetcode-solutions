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

    int isAConnectedComponent() {
        int ans = 0;
        set<int> s;
        
        for(int i=1; i<_n; i++) {
            s.insert(findUPar(parent[i]));
        }

        return s.size() == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice = DSU(n+1);
        DSU bob = DSU(n+1);

        sort(edges.begin(), edges.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        int ans = 0;

        for(auto &edge: edges) {
            if(edge[0] == 1)
                ans += !alice.unionBySize(edge[1], edge[2]);
            if(edge[0] == 2)
                ans += !bob.unionBySize(edge[1], edge[2]);
            if(edge[0] == 3) {
                ans += !bob.unionBySize(edge[1], edge[2]);
                alice.unionBySize(edge[1], edge[2]);
            }
        }

        if(!alice.isAConnectedComponent() or !bob.isAConnectedComponent()) {
            return -1;
        }

        return ans;
    }
};
