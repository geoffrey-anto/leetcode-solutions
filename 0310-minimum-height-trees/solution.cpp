// class Solution {
// public:
//     int mx = 0;
//     void dfs(int n, vector<int> adj[], vector<int> &vis, int h) {
//         vis[n] = 1;

//         mx = max(mx, h);

//         for(auto &node: adj[n]) {
//             if(!vis[node]) {
//                 dfs(node, adj, vis, h+1);
//             }
//         }
//     }



//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<int> adj[n];
//         for(auto &edge: edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }

//         vector<int> mem(n, 0);
//         int mn = INT_MAX;
//         for(auto i=0; i<n; i++) {
//             vector<int> vis(n, 0);
//             mx = 0;
//             dfs(i, adj, vis, 0);
//             mn = min(mn, mx);
//             mem[i] = mx;
//         }

//         vector<int> ans;

//         for(auto i = 0; i<n; i++) {
//             if(mem[i] == mn) {
//                 ans.push_back(i);
//             }
//         }


//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int> ans;
        vector<int> deg(n,0);
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]); 
            adj[edges[i][1]].push_back(edges[i][0]);
            deg[edges[i][1]]++; 
            deg[edges[i][0]]++;
        }

        queue<int>queue;

        for(int i=0;i<n;i++)
        {
            if(deg[i]==1) 
                queue.push(i);
        }

        while(!queue.empty())
        {
            ans.clear(); 
            int size=queue.size();

            for(int i=0;i<size;i++)
            {
                int cur=queue.front();
                queue.pop();
                ans.push_back(cur); 

                for(auto &neighbor:adj[cur])
                {
                    deg[neighbor]--; 
                    if(deg[neighbor]==1) 
                        queue.push(neighbor);
                }
            }
        }
        
        return ans;
    }
};
