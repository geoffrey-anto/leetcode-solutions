class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        for(int i = 0; i<n; i++) {
            queue<pair<int, int>> pq;

            dist[i][i] = 0;

            pq.push({0, i});

            while(!pq.empty()) {
                auto top = pq.front();
                pq.pop();
                int node = top.second;
                int d = top.first;


                for(auto &it: adj[node]) {
                    int next = it.first;
                    int w = it.second;

                    if(d + w < dist[i][next]) {
                        dist[i][next] = w + d;
                        pq.push({dist[i][next], next});
                    }
                }
            }
        }

        vector<int> res(n, 0);

        for(int i=0; i<n; i++) {
            bool isFound = false;
            for(int j=0; j<n; j++) {
                if(dist[i][j] == 1e9) {
                    dist[i][j] = 0;
                }
                if(dist[i][j] <= distanceThreshold) {
                    res[i]++;
                    isFound = true;
                }
            }
            cout << endl;
            cout << res[i] << endl;

            if(!isFound) {
                res[i] = INT_MAX;
            }
        }

        int currMin = INT_MAX;
        int curr = -1;

        for(int i=n-1; i>=0; i--) {
            if(res[i] < currMin) {
                currMin = res[i];
                curr = i;
            }
        }

        return curr;
    }
};