class Solution {
public:
    template <typename T> void print(T arr) {
        for (auto i : arr) {
            cout << i << ' ';
        }
        cout << endl;
    }

    vector<int> topoSort(vector<vector<int>>& arr, int n) {
        vector<int> topo;
        topo.reserve(n);

        vector<vector<int>> adj(n+1);
        vector<int> in(n+1, 0);

        for(auto &i: arr) {
            adj[i[0]].push_back(i[1]);
            in[i[1]]++;
        }

        queue<int> q;

        for(int i=1; i<=n; i++) {
            if(in[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            auto t = q.front();
            q.pop();

            topo.push_back(t);

            for(auto i: adj[t]) {
                in[i]--;
                if(in[i] == 0)
                    q.push(i);
            }
        }

        return topo.size() != n ? vector<int>() : topo;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<vector<int>> ans(k, vector<int> (k, 0));

        int n = row.size();
        int m = col.size();

        vector<vector<int>> mat;

        auto r_topo = topoSort(row, k);

        auto c_topo = topoSort(col, k);

        if(r_topo.size() == 0 or c_topo.size() == 0) {
            return {};
        }

        vector<int> pos_r(k+1, -1), pos_c(k+1, -1);

        for(int i=0; i<k; i++){
            pos_r[r_topo[i]]=i;
            pos_c[c_topo[i]]=i;
        }

        for(int i=1; i<=k; i++)
            ans[pos_r[i]][pos_c[i]]=i;
        
        return ans;
    }
};
