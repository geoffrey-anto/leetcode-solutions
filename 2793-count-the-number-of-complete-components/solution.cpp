class DSU {
    public:
    vector<int> parent;
    vector<int> size;
    unordered_map<int, int> edgesCount;

    DSU(int n) {
        size = vector<int>(n, 1);
        for(int i=0; i<n; i++) {
            parent.push_back(i);
        }

        for(int i=0; i<n; i++) {
            edgesCount[i] = 1;
        }
    }

    int findUPar(int n) {
        if(n == parent[n]) {
            return n;
        }

        return parent[n] = findUPar(parent[n]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_v != ulp_u) {
            if(size[ulp_u] < size[ulp_v]) {
                swap(ulp_u, ulp_v);
            }

            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            edgesCount[ulp_u] += edgesCount[ulp_v];
            edgesCount.erase(ulp_v);
        } else {
            edgesCount[ulp_u]++;
        }
    }

    int getComponents() {
        int ans = 0;
        
        for(auto &[k, v]: edgesCount) {
            int s = size[k];

            int m = v - 1;

            if(m == ((int)(s*(s-1))/2)) {
                ans++;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu = DSU(n);

        for(auto &edge: edges) {
            dsu.unionBySize(edge[0], edge[1]);
        }

        return dsu.getComponents();
    }
};
