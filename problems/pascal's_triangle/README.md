# Pascal'S Triangle

## Leetcode Link: [Pascal'S Triangle](https://leetcode.com/problems/pascals-triangle/)
### Language: C++

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        if(n==1) {
            return {{1}};
        }

        if(n==2) {
            return {{1}, {1,1}};
        }

        vector<vector<int>> ans = {{1}, {1,1}};

        n = n -2;
        int i = 1;

        while(n) {
            vector<int> temp(ans[i].size()+1, 1);
            temp[0] = 1;
            temp[ans[i].size()] = 1;
            for(int j=1; j<ans[i].size(); j++) {
                temp[j] = ans[i][j-1] + ans[i][j];
            }
            ans.push_back(temp);
            n=n-1;
            i++;
        }

        return ans;
    }
};```



