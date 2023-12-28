class DSU {
    vector<int> rank, parent;
    int findUParent(int node) {
        if(parent[node] == node) {
            return node;
        }

        return parent[node] = findUParent(parent[node]);
    }

public:
    DSU(int n) {
        for(int i=0; i<n+1; i++) {
            rank.push_back(0);
            parent.push_back(i);
        }
    }

    bool isSameComponent(int u, int v) {
        return findUParent(u) == findUParent(v);
    }

    void unionAdd(int u, int v) {
        int parentU = findUParent(u);
        int parentV = findUParent(v);

        if(parentU == parentV) {
            return;
        }

        if(rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        } else if(rank[parentV] < rank[parentU]) {
            parent[parentV] = parentU;
        } else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu = DSU(n);
        vector<bool> ans;
        for(int i=1; i<=n; i++) {
            int mul = 2;
            while(i * mul <= n) {
                if(i*mul > threshold && i > threshold) {
                    int u = i;
                    int v = i*mul;

                    dsu.unionAdd(u,v);
                }
                mul++;
            }
        }

        for(auto &q: queries) {
            ans.push_back(dsu.isSameComponent(q[0], q[1]));
        }

        return ans;
    }
};