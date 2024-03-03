class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> countInY(3, 0);
        vector<int> countInOthers(3, 0);

        for(int i=0; i<n/2; i++) {
            countInY[grid[i][i]]++;
        }

        for(int i=0; i<n/2; i++) {
            countInY[grid[i][n-i-1]]++;
        }

        for(int i=n/2; i<n; i++) {
            countInY[grid[i][n/2]]++;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                countInOthers[grid[i][j]]++;
            }
        }

        countInOthers[0] -= countInY[0];
        countInOthers[1] -= countInY[1];
        countInOthers[2] -= countInY[2];

        int ans = 1e8;

        for(int i=0; i<=2; i++) {
            // i is the val for Y
            if(i == 0) {
                ans = min(ans, 
                    countInY[1] + countInY[2] + countInOthers[i] + min(countInOthers[1], countInOthers[2])
                );
            } if(i == 1) {
                ans = min(ans, 
                    countInY[2] + countInY[0] + countInOthers[i] + min(countInOthers[0], countInOthers[2])
                );
            } if(i == 2){
                ans = min(ans, 
                    countInY[1] + countInY[0] + countInOthers[i] + min(countInOthers[1], countInOthers[0])
                );
            }
        }

        return ans;
    }
};
