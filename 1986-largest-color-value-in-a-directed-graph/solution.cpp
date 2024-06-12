class Solution {
public:
    vector<int> topo(int N, vector<vector<int>> &adj) {
        queue<int> q;
        vector<int> in(N, 0);

        for (int i = 0; i < N; i++) {
            for (auto it : adj[i]) {
                in[it]++;
            }
        }

        for (int i = 0; i < N; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                in[it]--;
                if (in[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(colors.size());
        int n = colors.size();

        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        vector<int> in(n, 0);
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                in[it]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        vector<vector<int>> dp(colors.size()+1, vector<int> (26, 0));

        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        vector<int> topo;


        while (!q.empty()) {
            int node = q.front();

            vis[node]++;

            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                for(int i=0; i<26; i++) {
                    dp[it][i] = max((dp[node][i] + (int)(colors[it] == (i + 'a'))) , dp[it][i]);
                }

                in[it]--;

                if (in[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(topo.size() != colors.size()) {
            return -1;
        }

        if(accumulate(begin(vis), end(vis), 0) != n) {
            return -1;
        }

        int ans = 0;

        for(auto &i: dp) {
            ans = max(ans, *max_element(begin(i), end(i)));
        }

        return ans;
    }
};
