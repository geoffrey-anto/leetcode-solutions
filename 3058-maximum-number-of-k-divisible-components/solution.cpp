class Solution {
public:
    int ans = 0;
    vector<vector<int>> build(vector<vector<int>>& edges, int n) {
        vector<vector<int>> graph(n);

        for(auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    int f(int node, vector<vector<int>>& graph, vector<int>& value, vector<bool>& visited, int k, int n) {
        visited[node] = true;

        int curr = value[node];

        for(auto nextNode: graph[node]) {
            if(visited[nextNode]) {
                continue;
            }

            curr += f(nextNode, graph, value, visited, k, n);

            curr = curr % k;
        } 

        if(curr % k == 0) {
            ans++;
            return 0;
        }

        return curr;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        sort(begin(edges), end(edges));

        auto graph = build(edges, n);

        ans = 0;

        vector<bool> visited(n, false);

        f(0, graph, values, visited, k, n);

        return ans;
    }
};
