#define graph vector<vector<int>>&

class Solution {
    bool isFresh(int i, int j, graph grid) {
        if(i>=0 && i<grid.size()) {
            if(j>=0 && j<grid[0].size()) {
                if(grid[i][j] == 1) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir = {-1,0,1,0,-1};
        int ans = 0;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int freshCount = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }

                if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        while(!q.empty()) {
            int size = q.size();

            for(int i=0; i<size; i++) {
                auto top = q.front();
                q.pop();

                for(int d=0; d<(dir.size()-1); d++) {
                    int dy = dir[d]+top.first;
                    int dx = dir[d+1]+top.second;
                    if(isFresh(dy, dx, grid)) {
                        grid[dy][dx] = 2;
                        q.push(make_pair(dy, dx));
                        freshCount--;
                    }
                }
            }

            ans++;
        }

        if(freshCount > 0) return -1;

        return ans == 0 ? 0 : ans - 1;
    }
};