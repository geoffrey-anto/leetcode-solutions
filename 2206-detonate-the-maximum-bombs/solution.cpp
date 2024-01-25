#define ll long long

class Solution {
public:
    bool isInRange(vector<int> &a, vector<int> &b) {
        if ((((ll)b[0] - (ll)a[0]) * ((ll)b[0] - (ll)a[0]) +((ll)b[1] - (ll)a[1]) * ((ll)b[1] - (ll)a[1]) <= (ll)a[2] * (ll)a[2])) 
            return true;
        else
            return false;
    }

    void dfs(int n, vector<vector<int>> &adj, vector<int> &vis) {
        if(vis[n]) return;
        vis[n] = 1;
        for(auto node: adj[n]) {
            if(!vis[node]) {
                dfs(node, adj, vis);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>> adj(n+1, vector<int>());

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(isInRange(bombs[i], bombs[j])) {
                    adj[i].push_back(j);
                }
                if(isInRange(bombs[j], bombs[i])) {
                    adj[j].push_back(i);
                }
            }
        }

        int currMax = 0;

        for(int i=0; i<n; i++) {
            vector<int> vis(n, 0);
            
            dfs(i, adj, vis);
            
            int cnt = 0;
            for(auto i: vis) {
                if(i) {
                    cnt++;
                }
            }
            currMax = max(currMax, cnt);
        }

        return currMax;
    }
};
