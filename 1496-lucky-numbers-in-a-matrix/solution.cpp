class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;
        
        vector<int> rows(n, INT_MAX), cols(m, INT_MAX);

        for(int i=0; i<n; i++) {
            int mn = INT_MAX;
            for(int j=0; j<m; j++) {
                mn = min(mn, matrix[i][j]);
            }
            rows[i] = mn;
        }

        for(int j=0; j<m; j++) {
            int mx = INT_MIN;
            for(int i=0; i<n; i++) {
                mx = max(mx, matrix[i][j]);
            }
            cols[j] = mx;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int val = matrix[i][j];

                int mn = cols[j]; int mx = rows[i];

                if(val == mn and val == mx) {
                    ans.push_back(val);
                }
            }
        }

        return ans;
    }
};
