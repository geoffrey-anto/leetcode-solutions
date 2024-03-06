class Solution {
public:
    void dfs(int node, vector<int> adj[], int &cnt, vector<bool> &vis, vector<int> &ans) {
        vis[node] = true;
        cnt++;

        for(auto i: adj[node]) {
            if(!vis[i]) {
                dfs(i, adj, cnt, vis, ans);
            }
        }

        ans[node] = cnt;
    }

    stack<int> topo(int N, vector<int> adj[], vector<bool> &vis) {
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

        stack<int> topo;

        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            topo.push(node);
            vis[node] = true;
            for(auto it : adj[node]) {
                in[it]--;
                if(in[it] == 0) {
                    q.push(it); 
                }
            }
        }

        return topo;
    }

    vector<int> countVisitedNodes(vector<int>& graph) {
        // maybe do a topo sort
        // so the top of stack wud have the furthest node
        // build the answer from the top of the stack 

        // So in case of example 1
        // 

        int n = graph.size();

        vector<int> adj[graph.size()];

        for(int i=0; i<n; i++) {
            adj[i].push_back(graph[i]);
        }
        vector<bool> vis(n, false);

        stack<int> st = topo(n, adj, vis);

        // while(!st.empty()) {
        //     cout << st.back() << endl;
        //     st.pop_back();
        // }

        vector<int> ans(n, 0);


        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                int cnt = 0;
                dfs(i, adj, cnt, vis, ans);
            }
        }

        // for(auto i=0; i<n; i++) {
        //     cout << ans[i] << endl;
        // }

        // now we have the distances
        // so in the topo sort we get the nodes w/o the cycle eg 3 in eg.1
        // so using this we can add the connecting cycles value to this node
        // ans[node] = ans[adj[node][0]] + ans[node]

        while(!st.empty()) {
            auto node = st.top();
            st.pop();

            ans[node] = ans[graph[node]] + 1;
        }

        return ans;
    }
};
