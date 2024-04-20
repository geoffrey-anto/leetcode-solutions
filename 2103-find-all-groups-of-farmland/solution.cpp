class Solution {
public:
    vector<int> coords = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
    vector<int> dirs = {-1, 0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<int>>& land) {
        land[i][j] = 0;
        coords[0] = min(coords[0], i);
        coords[1] = min(coords[1], j);
        coords[2] = max(coords[2], i);
        coords[3] = max(coords[3], j);

        for(int d=0; d<4; d++) {
            int dx = i + dirs[d];
            int dy = j + dirs[d+1];

            if(dx >= 0 and dx < land.size() and dy >= 0 and dy < land[0].size() and land[dx][dy] == 1) {
                dfs(dx, dy, land);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        for(int i=0; i<land.size(); i++) {
            for(int j=0; j<land[0].size(); j++) {
                if(land[i][j] == 1) {
                    coords = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
                    dfs(i, j, land);
                    ans.push_back(coords);
                }
            }
        }

        return ans;
    }
};
