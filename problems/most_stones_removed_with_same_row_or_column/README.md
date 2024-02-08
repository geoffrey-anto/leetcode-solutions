# Most Stones Removed With Same Row Or Column

## Leetcode Link: [Most Stones Removed With Same Row Or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)
### Language: C++

```cpp
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
        for(int i=0; i<n; i++) {
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

    int getNoOfComponents() {
        int ans = 0; 

        for(int i=0; i<parent.size(); i++) {
            cout << parent[i] << " " << rank[i] << endl;
            if(parent[i] == i && rank[i] != 0)  {
                ans++;
            }
        }

        return ans;
    }
};


class Solution {
public:
    bool isValid(vector<int>&a, vector<int>& b) {
        return a[0] == b[0] || a[1] == b[1];
    }
    int dfs(int node, vector<vector<int>>& stones, int &n, vector<int> &vis) {
        vis[node] = 1;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            if(!vis[i] && isValid(stones[i], stones[node])) {
                ans += dfs(i, stones, n, vis) + 1;
            }
        }

        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        // int n = stones.size();
        // DSU dsu = DSU(n);

        // for(auto &st: stones) {
        //     dsu.unionAdd(st[0], st[1]);
        // }

        // return n - dsu.getNoOfComponents();

        int n = stones.size();

        int conn = 0;
        vector<int> vis(n, 0);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                conn += dfs(i, stones, n, vis);
            }
        }

        return conn;
    }
};```



