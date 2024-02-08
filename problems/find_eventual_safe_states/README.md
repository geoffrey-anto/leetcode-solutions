# Find Eventual Safe States

## Leetcode Link: [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> adj(v, vector<int>());
        vector<int> inDeg(v, 0);
        vector<int> ans;
        for(auto i=0; i<v; i++) {
            for(auto it: graph[i]) {
                adj[it].push_back(i);
                inDeg[i]++;
            }
        }

        graph.clear();

        queue<int> q;

        for(int i=0; i<v; i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int top = q.front();
            q.pop();

            ans.push_back(top);

            for(auto i: adj[top]) {
                inDeg[i]--;

                if(inDeg[i] == 0) {
                    q.push(i);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};```



