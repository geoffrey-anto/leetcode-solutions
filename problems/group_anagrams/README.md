# Group Anagrams

## Leetcode Link: [Group Anagrams](https://leetcode.com/problems/group-anagrams/)
### Language: C++

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> map;

        for(int i=0; i<n; i++) {
            auto s = strs[i];
            sort(s.begin(), s.end());

            map[s].push_back(strs[i]);
        }

        vector<vector<string>> v;

        for(auto i: map) {
            v.push_back(i.second);
        }
        return v;
    }
};```



