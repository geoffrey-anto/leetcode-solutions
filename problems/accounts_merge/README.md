# Accounts Merge

## Leetcode Link: [Accounts Merge](https://leetcode.com/problems/accounts-merge/)
### Language: C++

```cpp
class Solution {
public:
    string find(string s, map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        }
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++) {
                parents[find(acts[i][j], parents)] = p;
            }
        }

        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                unions[find(acts[i][j], parents)].insert(acts[i][j]);
            }
        }

        vector<vector<string>> res;

        for (auto &p : unions) {
            vector<string> temp(p.second.begin(), p.second.end());
            temp.insert(temp.begin(), owner[p.first]);
            res.push_back(temp);
        }
        return res;
    }
};```



