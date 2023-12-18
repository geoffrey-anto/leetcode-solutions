# Destination City

## Leetcode Link: [Destination City](https://leetcode.com/problems/destination-city/)
### Language: C++

```cpp
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> ans;
        for(int i=0;i<paths.size();i++){
            ans.push_back(paths[i][0]);
        }
        for(int i=0;i<paths.size();i++){
            if(count(ans.begin(),ans.end(),paths[i][1])==0){
                return paths[i][1];
            }
        }
        return "";
    }
};```



