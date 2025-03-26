class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                temp.push_back(grid[i][j]);
        }

        sort(temp.begin(), temp.end());

        int med = temp[temp.size() / 2];
        int rem = temp[0] % x, ope = 0;

        for (int num : temp) {

            if (num % x != rem)
                return -1;
            ope += abs(num - med) / x;
        }

        return ope;
    }
};;
