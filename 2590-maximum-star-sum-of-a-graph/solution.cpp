class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<priority_queue<int, vector<int>, greater<int>>> adj(vals.size(), priority_queue<int, vector<int>, greater<int>>());

        for(auto &edge: edges) {
            adj[edge[0]].push(vals[edge[1]]);
            adj[edge[1]].push(vals[edge[0]]);
        }

        int mn = INT_MIN;

        for(int i=0; i<vals.size(); i++) {
            while(adj[i].size() > k) {
                adj[i].pop();
            }

            int curr = 0;

            while(!adj[i].empty()) {
                if(adj[i].top() > 0) {
                    curr += adj[i].top();
                } 

                adj[i].pop();
            }

            mn = max(mn, curr + vals[i]);
        }

        return mn;
    }
};
