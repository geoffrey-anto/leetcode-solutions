# Is Graph Bipartite?

## Leetcode Link: [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite?/)
### Language: C++

```cpp
class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &colors, int c) {
        colors[node] = c;

        for(auto n: graph[node]) {
            if(colors[n] == -1) {
                if(dfs(n, graph, colors, !c) == false) return false; 
            } else {
                if(colors[n] == colors[node]) {
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n+1, -1);

        for(int i=0; i<n; i++) {
            if(colors[i] == -1) {
                if(!dfs(i, graph, colors, 0)) return false;
            }
        }

        return true;
    }
};```



