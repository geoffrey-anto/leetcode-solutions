class Solution {
public:
    int VIS = -101;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        vector<vector<int>> dirs = {
            {1, 0},
            {0, -1},
            {-1, 0},
            {0, 1}
        };

        if (matrix.empty()) {
            return ans;
        }
        
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return ans;
    }
};
