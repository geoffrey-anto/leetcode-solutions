class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int n, int m) {
        if(original.size() != n * m) {
            return {};
        }

        vector<vector<int>> ans(n, vector<int> (m, 0));

        int curr = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = original[curr];
                curr ++;
            }
        }

        return ans;
    }
};
