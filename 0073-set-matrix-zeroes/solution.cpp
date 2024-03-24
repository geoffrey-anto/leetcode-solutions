class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <int> c;
        vector <int> rows;

        int n = matrix.size();

        for(int i=0;i<n; i++){
            for(int j=0;j<matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    c.push_back(j);
                }
            }
        }

        for(int i=0;i<rows.size(); i++){
            for(int j=0; j<matrix[rows[i]].size(); j++){
                matrix[rows[i]][j] = 0;
            }
        }

        for(int i=0; i<n; i++){
            for(int j= 0; j<c.size(); j++){
                matrix[i][c[j]] = 0;
            }
        }
    }
};
