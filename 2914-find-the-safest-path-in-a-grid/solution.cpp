// Hard fr
class Solution {
public:
    int isValid(int i, int j, int n) {
        return i >= 0 and i < n and j >= 0 and j < n;
    }

    vector<int> dirs = {0, -1, 0, 1, 0};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1) {
            return 0;
        }

        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        vector<vector<int>> vis(n, vector<int> (n, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        while(!q.empty()) {
            auto t = q.front();
            q.pop();

            int x = t.first.first, y = t.first.second;
            int dis = t.second;
            dist[x][y] = min(dis, dist[x][y]);
            
            for(int d=0; d<4; d++) {
                int dx = x + dirs[d];
                int dy = y + dirs[d+1];
                if(isValid(dx, dy, n) and grid[dx][dy] == 0 and vis[dx][dy] == 0) {
                    vis[dx][dy] = 1;
                    q.push({{dx, dy}, dis+1});
                }
            }
        }

        // for(auto &i: dist) {
        //     for(auto &j: i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
         
        vis = vector<vector<int>>(n, vector<int> (n, 0));
        priority_queue<pair<int, pair<int, int>>> pq;

        pq.push({dist[0][0], {0, 0}});

        int mx = INT_MAX;
        vis[0][0] = 1;

        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();

            int x = t.second.first, y = t.second.second;
            int dis = t.first;

            mx = min(mx, dis);
            if(x == n-1 and y == n-1) {
                break;
            }
            
            for(int d=0; d<4; d++) {
                int dx = x + dirs[d];
                int dy = y + dirs[d+1];
                if(isValid(dx, dy, n) and vis[dx][dy] == 0) {
                    vis[dx][dy] = 1;
                    pq.push({dist[dx][dy], {dx, dy}});
                }
            }
        }

        return mx;
    }
};
