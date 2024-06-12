class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& w, vector<vector<int>>& f, int id, int l) {
        int n = w.size();

        map<string, int> mp;

        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++) {
            for(auto j: f[i]) {
                adj[i].push_back(j);
            }
        }

        vector<bool> vis(n, false);
        vis[id] = true;

        queue<int> q;
        q.push(id);

        int k = 0;

        while(!q.empty()) {
            int sz = q.size();

            if(k == l) {
                while(!q.empty()) {
                    auto t = q.front();
                    q.pop();

                    for(auto i: w[t]) {
                        mp[i]++;
                    }
                }
                break;
            }

            k++;

            for(int i=0; i<sz; i++) {
                auto t = q.front();
                q.pop();

                for(auto j: adj[t]) {
                    if(!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
        }

        vector<string> ans;

        vector<pair<int, string>> temp;
        for(auto &[k, v]: mp) {
            temp.push_back({v, k});
        }

        sort(begin(temp), end(temp));

        for(auto &i: temp) {
            ans.push_back(i.second);
        }

        return ans;
    }
};
