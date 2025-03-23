class Solution {
    bool DEBUG = true;
    int MOD = (int)(1e9 + 7);
public:
    void dfs(int i, vector<vector<int>>& g, int &ans) {
        cout << i << endl;
        for(auto &node: g[i]) {
            dfs(node, g, ans);
        }
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> adj(n, vector<pair<long long, long long>>());

        for(auto &i: roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<
            pair<long long, long long>, 
            vector<pair<long long, long long>>, 
            greater<pair<long long, long long>>
        > pq;

        vector<long long> dis(n, LLONG_MAX);

        vector<long long> ways(n, 0);

        ways[0] = 1;

        dis[0] = 0;

        pq.push({0, 0});

        while(!pq.empty()) {
            auto top = pq.top();
            long long d = top.first;
            long long node = top.second;

            pq.pop();

            for(auto &n: adj[node]) {
                long long i = n.first;
                long long w = n.second;

                if(d + w < dis[i]) {
                    dis[i] = d + w;
                    ways[i] = ways[node]; 
                    pq.push({d+w, i});
                } else if(d + w == dis[i]) {
                    ways[i] = (ways[i] + ways[node]) % MOD;
                }
            }
        }

        // vector<vector<long long>> g(n);

        // for(auto &i: roads) {
        //     if(dis[i[0]] + i[2] == dis[i[1]] || dis[i[1]] + i[2] == dis[i[0]]) {
        //         g[i[0]].push_back(i[1]);
        //     }
        // }

        // if(DEBUG) {
        //     for(auto i: dis) {
        //         cout << i << endl;
        //     }
        //     for(auto i=0; i<n; i++) {
        //         cout << i << "->>";
        //         for(auto n: g[i]) {
        //             cout << n << ',';
        //         }

        //         cout << endl;
        //     }
        // }


        // long long ans = 0;

        // queue<int> q;

        // q.push(0);

        // while(!q.empty()) {
        //     auto t = q.front();
        //     q.pop();

        //     if(t == n-1) {
        //         ans++;
        //     }

        //     for(auto i: g[t]) {
        //         q.push(i);
        //     }
        // }

        return ways[n-1] % MOD;
    }
};
