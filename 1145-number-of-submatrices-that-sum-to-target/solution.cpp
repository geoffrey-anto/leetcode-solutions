class Solution {
    bool DEBUG = false;
public:
    vector<vector<int>> getPrefixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> prefixSum(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                int top = prefixSum[i - 1][j];
                int left = prefixSum[i][j-1];

                int topLeft = prefixSum[i-1][j-1];

                prefixSum[i][j] = matrix[i-1][j-1] + top + left - topLeft;
            }
        }

        if(DEBUG) {
            for(auto i: prefixSum) {
                for(auto j: i) {
                    cout << j << " ";
                }

                cout << endl;
            }
        }

        return prefixSum;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> pre = getPrefixSum(matrix);
        int cnt = 0;
        int n = matrix.size(), m = matrix[0].size();

        for(int r1=1; r1<=n; r1++) {
            for(int r2=r1; r2 <= n; r2++) {
                for(int c1=1; c1<=m; c1++) {
                    for(int c2=c1; c2 <= m; c2++) {
                        int curr = pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1];

                        if(curr == target) {
                            cnt++;
                        }
                    }
                }
            }
        }

        return cnt;
    }
};
