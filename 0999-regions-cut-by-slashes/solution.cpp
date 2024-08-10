class Solution {
public:
    vector<pair<int, int>> dirs = {
        {-1, 0}, 
        { 0, -1}, 
        { 0, 1},
        { 1, 0},
    };

    void dfs(int i, int j, vector<vector<int>> &arr, vector<vector<bool>> &vis) {
        vis[i][j] = true;

        for(int d=0; d<dirs.size(); d++) {
            int xi = dirs[d].first + i;
            int xj = dirs[d].second + j;

            if(xi < arr.size() and xi >= 0 and xj < arr.size() and xj >= 0 and !vis[xi][xj] and !arr[xi][xj]) {
                dfs(xi, xj, arr, vis);
            }
        }
    }

    int countIslands(vector<vector<int>> &arr) {
        vector<vector<bool>> vis(arr.size(), vector<bool> (arr.size(), false));

        int cnt = 0;

        for(int i=0; i<arr.size(); i++) {
            for(int j=0; j<arr.size(); j++) {
                if(!vis[i][j] and !arr[i][j]) {
                    dfs(i, j, arr, vis);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }

    void updateForwardSlash(vector<vector<int>> &arr, int i, int j) {
        arr[i][j] = 0;
        arr[i][j+1] = 0;
        arr[i][j+2] = 1;

        arr[i+1][j] = 0;
        arr[i+1][j+1] = 1;
        arr[i+1][j+2] = 0;

        arr[i+2][j] = 1;
        arr[i+2][j+1] = 0;
        arr[i+2][j+2] = 0;
    }

    void updateBackwardSlash(vector<vector<int>> &arr, int i, int j) {
        arr[i][j] = 1;
        arr[i][j+1] = 0;
        arr[i][j+2] = 0;

        arr[i+1][j] = 0;
        arr[i+1][j+1] = 1;
        arr[i+1][j+2] = 0;

        arr[i+2][j] = 0;
        arr[i+2][j+1] = 0;
        arr[i+2][j+2] = 1;
    }

    int regionsBySlashes(vector<string>& grid) {
        // 1x1 -> 3x3 grid
        int n = grid.size();

        vector<vector<int>> arr(n * 3, vector<int> (n*3, 0));

        int curr = 0;

        for(auto &g: grid) {
            int x = 0;
            for(int i=0; i<g.size(); i++) {
                if(g[i] == ' ') {
                    x += 3;
                } else if(g[i] == '/') {
                    updateForwardSlash(arr, curr, x);
                    x+=3;
                } else {
                    updateBackwardSlash(arr, curr, x);
                    x+=3;
                }
            }
            curr+=3;
        }

        return countIslands(arr);
    }
};
