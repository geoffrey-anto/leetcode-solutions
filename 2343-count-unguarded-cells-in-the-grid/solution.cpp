// class Solution {
// public:
//     void dfs(int i, int j, vector<vector<int>> &v, int d1, int d2) {
//         if(i < 0 or j < 0 or i >= v.size() or j >= v[0].size()) {
//             return;
//         }

//         if(v[i][j] == -1) {
//             return;
//         }

//         int x = i + d1;
//         int y = j + d2;

//         if(v[i][j] != 1)
//             v[i][j] = 2;

//         dfs(x, y, v, d1, d2);
//     }
//     int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         vector<vector<int>> v(m, vector<int> (n, 0));

//         for(auto &i: walls) {
//             v[i[0]][i[1]] = -1;
//         }

//         for(auto &i: guards) {
//             v[i[0]][i[1]] = 1;
//         }

//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 if(v[i][j] != 1) continue;
//                 dfs(i, j, v, 0, 1);
//                 dfs(i, j, v, 1, 0);
//                 dfs(i, j, v, 0, -1);
//                 dfs(i, j, v, -1, 0);
//             }
//         }

//         int cnt = 0;

//         for(auto i: v) {
//             for(auto j: i) {
//                 cnt += (j == 0);
//             }
//         }

//         return cnt;
//     }
// };

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for (auto val : w) {
            vis[val[0]][val[1]] = 2;
        }

        for (auto val : g) {
            vis[val[0]][val[1]] = 3;
        }

        for (auto val : g) {
            int row = val[0], col = val[1];

            for (int i = row + 1; i < m; i++) {
                if (vis[i][col] == 2 || vis[i][col] == 3) break;
                vis[i][col] = 1;
            }

            for (int i = row - 1; i >= 0; i--) {
                if (vis[i][col] == 2 || vis[i][col] == 3) break;
                vis[i][col] = 1;
            }

            for (int i = col + 1; i < n; i++) {
                if (vis[row][i] == 2 || vis[row][i] == 3) break;
                vis[row][i] = 1;
            }

            for (int i = col - 1; i >= 0; i--) {
                if (vis[row][i] == 2 || vis[row][i] == 3) break;
                vis[row][i] = 1;
            }
        }

        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) unguarded++;
            }
        }

        return unguarded;
    }
};
