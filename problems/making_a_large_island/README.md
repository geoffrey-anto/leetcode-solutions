# Making A Large Island

## Leetcode Link: [Making A Large Island](https://leetcode.com/problems/making-a-large-island/)
### Language: C++

```cpp
class DSU {
    vector<int> rank, parent, size;
public:
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    int getSize(int node) {
        return size[findUPar(node)];
    }

    int getMaxSize() {
        int ans = 0;
        for(auto i: size) {
            ans = max(i, ans);
        }

        return ans;
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    bool isValid(int i, int j, int n, int m) {
        return i < n && i >= 0 && j < m && j >= 0;
    }
    int index(int i, int j, int n, int m) {
        return (i*m) + j;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU dsu = DSU(n * m);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    for(int d=0; d<4; d++) {
                        int nx = i + dir[d];
                        int ny = j + dir[d+1];

                        if(isValid(nx, ny, n, m) && grid[nx][ny] == 1) {
                            dsu.unionBySize(index(i, j, n, m), index(nx, ny, n, m));
                        }
                    }
                }
            }
        }

        int ans = dsu.getMaxSize();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    set<int> s;
                    for(int d=0; d<4; d++) {
                        int nx = i + dir[d];
                        int ny = j + dir[d+1];

                        if(isValid(nx, ny, n, m) && grid[nx][ny] == 1) {
                            s.insert(dsu.findUPar(index(nx, ny, n, m)));
                        }
                    }
                    int curr = 1;
                    for(auto e: s) {
                        curr += dsu.getSize(e);
                    }

                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};```



