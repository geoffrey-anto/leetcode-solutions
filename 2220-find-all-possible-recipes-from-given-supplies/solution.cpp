// class Solution {
// public:
//     template <typename T>
//     void print(T arr, unordered_map<int, string> &n2s)
//     {
//         for (auto i : arr)
//         {
//             cout << n2s[i] << ' ';
//         }
//         cout << endl;
//     }

//     vector<int> topoSort(int N, vector<vector<int>> adj) {
//         queue<int> q;
//         vector<int> in(N, 0);

//         for(int i = 0;i<N;i++) {
//             for(auto it: adj[i]) {
//                 in[it]++; 
//             }
//         }
        
//         for(int i = 0;i<N;i++) {
//             if(in[i] == 0) {
//                 q.push(i); 
//             }
//         }

//         vector<int> topo;

//         while(!q.empty()) {
//             int node = q.front(); 
//             q.pop(); 
//             topo.push_back(node);
//             for(auto it : adj[node]) {
//                 in[it]--;
//                 if(in[it] == 0) {
//                     q.push(it); 
//                 }
//             }
//         }

//         return topo;
//     }

//     vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
//         // Basically maybe a DAG

//         // BUILD A GRAPH MAYBE AND PREFORM A TOPO SORT

//         unordered_map<string, int> s2n;
//         unordered_map<int, string> n2s;

//         int idx = 0;

//         set<int> st;

//         for(auto &i: supplies) {
//             s2n[i] = idx;
//             n2s[idx] = i;
//             idx++;
//         }

//         for(auto &i: recipes) {
//             st.insert(idx);
//             s2n[i] = idx;
//             n2s[idx] = i;
//             idx++;
//         }

//         int n = supplies.size() + recipes.size();

//         cout << n << endl;

//         vector<vector<int>> adj(n);

//         for(int i=0; i<recipes.size(); i++) {
//             for(auto &in: ingredients[i]) {
//                 if(find(supplies.begin(), supplies.end(), in) != supplies.end())
//                     adj[s2n[in]].push_back(s2n[recipes[i]]);
//             }
//         }

//         auto topo = topoSort(n, adj);

//         vector<string> ans;

//         for(int i=topo.size()-1; i>=0; i--) {
//             if(st.find(i) != st.end()) 
//                 ans.push_back(n2s[topo[i]]);
//         }    

//         return ans;
//     }
// };

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& in, vector<string>& sup) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        unordered_map<string, int> ind;

        unordered_map<string, vector<string>> adj;

        for(int i=0; i<r.size(); i++) {
            for(auto &j: in[i]) {
                adj[j].push_back(r[i]);
                ind[r[i]]++;
            }
        }

        queue<string> q;
        vector<string> ans;

        for(auto &i: sup) {
            if(ind[i] == 0) {
                q.push(i);
            }
        }

        while(q.size() > 0) {
            string t = q.front();
            q.pop();

            for(auto &i: adj[t]) {
                --ind[i];
                if(ind[i] == 0) {
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};
