#define graph vector<vector<int>>&
class Solution {
    bool isValidColor(int i, int j, graph grid, int color) {
        if(i>=0 && i<grid.size()) {
            if(j>=0 && j<grid[0].size()) {
                if(grid[i][j] != color) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int> dir = {-1,0,1,0,-1};

        int ans = 0;

        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;

        q.push(make_pair(sr, sc));


        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();

                for(int d=0; d<dir.size()-1; d++) {
                    int dy = dir[d]+top.first;
                    int dx = dir[d+1]+top.second;

                    if(
                        isValidColor(dy, dx, image, color) && 
                        image[top.first][top.second] == image[dy][dx]
                    ) {
                        q.push(make_pair(dy, dx));
                    }
                }

                image[top.first][top.second] = color;
            }
        }

        return image;
    }
};
