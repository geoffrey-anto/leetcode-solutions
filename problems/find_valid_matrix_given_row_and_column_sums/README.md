# Find Valid Matrix Given Row And Column Sums

## Leetcode Link: [Find Valid Matrix Given Row And Column Sums](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/)
### Language: C++

```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> result(rowSum.size(), vector<int>(colSum.size(),0));
        int r= rowSum.size(), c= colSum.size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(rowSum[i]==0||colSum[j]==0)
                    continue;
                result[i][j]=min(rowSum[i], colSum[j]);
                rowSum[i]-=result[i][j];
                colSum[j]-=result[i][j];
            }
        }
        return result;
    }
};```



