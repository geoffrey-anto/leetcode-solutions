#define vii vector<vector<int>>

class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};

    bool dfs(int r, int c, bool& flag, vii& grid1, vii& grid2, vector<vector<bool>>& vis, int n, int m){
        if(grid1[r][c] != grid2[r][c]){
            flag = false;
        }
        
        vis[r][c] = true;

        for(int d=0; d<4; d++) {
            int ni = r + dir[d];
            int nj = c + dir[d+1];

            if(ni >= 0 && ni < n && nj >=0 && nj < m) {
                if(grid2[ni][nj] == 1 && !vis[ni][nj]) {
                    dfs(ni, nj, flag, grid1, grid2, vis, n, m);
                }
            }
        }
        return flag;  
    }

    int countSubIslands(vii& grid1, vii& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();


        vector<vector<bool>> vis(n, vector<bool> (m, false));

        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid2[i][j] == 1 && vis[i][j] == false) {

                    // TLE :( -> BFS

                    // queue<pair<int, int>> q;
                    // q.push({i, j});
                    // bool flag = true;

                    // while(!q.empty()) {
                    //     auto top = q.front();
                    //     int x = top.first;
                    //     int y = top.second;
                    //     vis[x][y] = true;

                    //     // printf("(%d, %d)\n", x, y);

                    //     q.pop();

                    //     if(grid1[x][y] != grid2[x][y]) {
                    //         flag = false;
                    //     }

                    //     for(int d=0; d<4; d++) {
                    //         int ni = x + dir[d];
                    //         int nj = y + dir[d+1];

                    //         if(ni >= 0 && ni < n && nj >=0 && nj < m) {
                    //             if(grid2[ni][nj] == 1 && !vis[ni][nj]) {
                    //                 q.push({ni, nj});
                    //             }
                    //         }
                    //     }
                    // }

                    // if(flag) {
                    //     ans++;
                    // }

                    bool flag = true;

                    if(dfs(i, j, flag, grid1, grid2, vis, n, m)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
