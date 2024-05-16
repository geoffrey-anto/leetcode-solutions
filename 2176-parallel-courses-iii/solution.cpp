vector<int> topo(int &N, vector<vector<int>> adj, vector<int> &time) {
    queue<int> q;
    vector<int> in(N, 0);

    for(int i = 0;i<N;i++) {
        for(auto it: adj[i]) {
            in[it]++; 
        }
    }
    
    for(int i = 0;i<N;i++) {
        if(in[i] == 0) {
            q.push(i); 
        }
    }

    vector<int> ans(N, 0);

    for(int i = 0;i<N;i++) {
        if(in[i] == 0) {
            ans[i] = time[i];
        }
    }

    while(!q.empty()) {
        int node = q.front(); 
        q.pop(); 
        for(auto it : adj[node]) {
            in[it]--;
            ans[it] = max(ans[node]+time[it], ans[it]);
            if(in[it] == 0) {
                q.push(it); 
            }
        }
    }

    return ans;
}

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);

        for(auto &r: relations) {
            adj[r[0]-1].push_back(r[1]-1);
        }

        auto res = topo(n, adj, time);

        return *max_element(res.begin(), res.end());
    }
};
