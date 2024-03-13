class Solution {
public:
    vector<int> topo(int N, vector<int> adj[]) {
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

        vector<int> topo;

        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            topo.push_back(node);
            for(auto it : adj[node]) {
                if(in[it] == 0) {
                    q.push(it); 
                }
            }
        }

        return topo;
    }
    
    int findChampion(int n, vector<vector<int>>& edges) {
        // find topo sort the ones in the stack are the champion candidates... if more than one or less than 0 return -1 else
        // return st.top();
        
        vector<int> adj[n];
        
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
        }
        
        auto st = topo(n, adj);
        
        if(st.size() == 0) {
            return -1;
        } else if(st.size() == 1) {
            return st[0]; 
        } else {
            return -1;
        }
        
    }
};
