# Number Of Operations To Make Network Connected

## Leetcode Link: [Number Of Operations To Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)
### Language: C++

```cpp
class Solution {
public:
    void dfs(int node, vector<vector<int>> &g, vector<int> &vis) {
        vis[node] = 1;
        for(auto n: g[node]) {
            if(!vis[n]) {
                dfs(n, g, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();

        if(m < n-1) {
            return -1;
        }

        int noOfComponents = 0;
        vector<vector<int>> g(n, vector<int>());
        vector<int> vis(n, 0);

        for(auto i: connections) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        // connections.clear();

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, g, vis);
                noOfComponents++;
            }
        }

        return noOfComponents - 1;
    }
};```



