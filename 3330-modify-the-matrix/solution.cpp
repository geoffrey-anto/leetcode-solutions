class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j=0; j<m; j++) {
            vector<int> m1;
            int mx = 0;
            for(int i=0; i<n; i++) {
                if(matrix[i][j] == -1) {
                    m1.push_back(i);
                }
                
                mx = max(mx, matrix[i][j]);
            }
            
            for(auto &x: m1) {
                matrix[x][j] = mx;
            }

        }
        
        return matrix;
    }
};
