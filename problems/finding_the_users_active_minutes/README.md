# Finding The Users Active Minutes

## Leetcode Link: [Finding The Users Active Minutes](https://leetcode.com/problems/finding-the-users-active-minutes/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>> mp;
        sort(logs.begin(),logs.end());
        int n=logs.size();
        vector<int> ans(k,0);
        for(auto log:logs){
            mp[log[0]].insert(log[1]);
        }
        for(auto i:mp){
            ans[i.second.size()-1]++;
        }
        return ans;
    }
};```



