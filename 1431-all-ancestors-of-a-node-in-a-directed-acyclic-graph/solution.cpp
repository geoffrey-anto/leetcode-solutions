class Solution {
public:
    vector<int> topoSort(int N, vector<vector<int>> adj) {
        queue<int> q;
        vector<int> in(N, 0);

        for(int i = 0;i<N;i++) {
            for(auto &it: adj[i]) {
                in[it]++; 
            }
        }
        
        for(int i = 0;i<N;i++) {
            if(in[i] == 0) {
                q.push(i); 
            }
        }

        vector<int> topo;

        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            topo.push_back(node);
            for(auto &it : adj[node]) {
                in[it]--;
                if(in[it] == 0) {
                    q.push(it); 
                }
            }
        }

        return topo;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<set<int>> adjr(n);

        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adjr[i[1]].insert(i[0]);
        }

        auto topo = topoSort(n, adj);

        vector<set<int>> ans(n);

        for(auto &i: topo) {
            for(auto &j: adjr[i]) {
                ans[i].insert(j);
                ans[i].insert(begin(ans[j]), end(ans[j]));
            }
        }

        vector<vector<int>> a(n);

        for(int i=0; i<n; i++) {
            for(auto &j: ans[i]) {
                a[i].push_back(j);
            }
        }

        return a;
    }
};
