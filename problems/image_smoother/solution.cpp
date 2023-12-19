class Solution {
public:
    public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = smoothen(img, i, j, m, n);
            }
        }

        return ans;
    }
    
    int smoothen(const vector<vector<int>>& img, int x, int y, int m, int n) {
        int sum = 0;
        int cnt = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int dx = x + i;
                int dy = y + j;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                    sum += img[dx][dy];
                    ++cnt;
                }
            }
        }

        return sum / cnt;
    }
};