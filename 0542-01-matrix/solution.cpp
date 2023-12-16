class Solution {
public:
    vector<int> d = {0, 1, 0, -1, 0};
    bool isValid(int i, int j, int n, int m) {
        return i>=0 && i<n && j>=0 && j < m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++) {
            for(int  j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push(make_pair(i, j));
                } else {
                    mat[i][j] = INT_MIN;
                }
            }
        }

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            int l = top.first;
            int r = top.second;

            for(int i=0; i<4; i++) {
                int dy = l + d[i];
                int dx = r + d[i+1];

                if(isValid(dy, dx, n, m) && mat[dy][dx] == INT_MIN) {
                    mat[dy][dx] = mat[l][r] + 1;
                    q.push(make_pair(dy, dx));
                }
            }
        }

        return mat;
    }
};

