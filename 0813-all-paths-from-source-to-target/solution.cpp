class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int &node, vector<vector<int>>& graph, vector<int> &ds, int &end) {
        if(node == end) {
            ans.push_back(ds);
            return;
        }

        for(auto &n: graph[node]) {
            ds.push_back(n);
            dfs(n, graph, ds, end);
            ds.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> ds = {0};
        int start = 0, end = graph.size() - 1;
        dfs(start, graph, ds, end);
        return ans;
    }
};
