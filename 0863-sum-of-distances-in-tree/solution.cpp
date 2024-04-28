class Solution {
public:
    void dfs(int i, int parent, vector<int> &sum, vector<int> &cnt, vector<vector<int>> &adj) {
        for(auto j: adj[i]) {
            if(j == parent) {
                continue;
            }
            dfs(j, i, sum, cnt, adj);
            cnt[i] += cnt[j];
            sum[i] += sum[j] + cnt[j];
        }
    }
    
    void reroot(int i, int parent, vector<int> &sum, vector<int> &cnt, vector<vector<int>> &adj) {
        for(auto j: adj[i]) {
            if(j == parent) {
                continue;
            }

            sum[j] = sum[i] + adj.size() - 2 * cnt[j];
            reroot(j, i, sum, cnt, adj);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> sum(n, 0), cnt(n, 1);

        dfs(0, -1, sum, cnt, adj);
        reroot(0, -1, sum, cnt, adj);

        return sum;
    }
};
