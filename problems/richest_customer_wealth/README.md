# Richest Customer Wealth

## Leetcode Link: [Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/)
### Language: C++

```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx=0;
        int ans=0;
        int n=accounts.size();
        int m=accounts[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mx+=accounts[i][j];
        }
        ans=max(ans,mx);
        mx=0;
    }
            return ans;
    }
};```



