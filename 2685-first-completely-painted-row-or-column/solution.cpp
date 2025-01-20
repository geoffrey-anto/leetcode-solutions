class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int s = arr.size();

        unordered_map<int, pair<int, int>> pos;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }

        unordered_map<int, int> row, col;

        for(int i=0; i<s; i++) {
            auto p = pos[arr[i]];

            row[p.first]++;
            col[p.second]++;

            if(row[p.first] == n) {
                return i;
            } 

            if(col[p.second] == m) {
                return i;
            }
        }

        return -1;
    }
};
