# Find Center Of Star Graph

## Leetcode Link: [Find Center Of Star Graph](https://leetcode.com/problems/find-center-of-star-graph/)
### Language: C++

```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0]){
            return edges[0][0];
        }else if(edges[0][0] == edges[1][1]){
            return edges[0][0];
        }else if(edges[0][1] == edges[1][0]){
            return edges[0][1];
        }else if(edges[0][1] == edges[1][1]){
            return edges[0][1];
        }
        return 0;
    }
};```



