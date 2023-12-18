# Height Checker

## Leetcode Link: [Height Checker](https://leetcode.com/problems/height-checker/)
### Language: C++

```cpp
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ans=heights;
        sort(ans.begin(),ans.end());
        int cnt=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};```



