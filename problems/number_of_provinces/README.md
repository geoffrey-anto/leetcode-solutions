# Number Of Provinces

## Leetcode Link: [Number Of Provinces](https://leetcode.com/problems/number-of-provinces/)
### Language: C++

```cpp
#define graph vector<vector<int>>
class Solution {
public:
    void dfs(int n, graph G, vector<bool> &vis) {
        vis[n] = true;

        for(auto node: G[n]) {
            if(!vis[node]) {
                dfs(node, G, vis);
            } 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        graph adj(n+1, vector<int>());
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] && i!=j) {
                    adj[i].push_back(j);
                }
            }
        }

        // free isConnected
        isConnected.clear();

        vector<bool> vis(n+1, false);

        int ans = 0;

        for(auto i=0; i<n; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i, adj, vis);
            }
        }

        return ans;
    }
};```



