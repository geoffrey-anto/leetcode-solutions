# Minimum Number Of Vertices To Reach All Nodes

## Leetcode Link: [Minimum Number Of Vertices To Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vec(n, 0);
        
        for(auto &i: edges) {
            vec[i[1]] = 1;
        }

        vector<int> ans;

        for(auto i=0; i<n; i++) {
            if(vec[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};```



