class Solution {
public:
    long long ans = 0;
    void dfs(int n, int s,vector<vector<pair<int, int>>> &graph) {
        for(auto &i: graph[n]) {
            dfs(i.first, s+i.second,graph);
            ans = max(ans, (long long)(s+i.second));
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<pair<int, int>>> graph(n);

        for(int i=0; i<n; i++) {
            if(manager[i] != -1) {
                graph[manager[i]].push_back({i, informTime[manager[i]]});
            }
        }

        dfs(headID, 0, graph);

        return ans;
        
    }
};
