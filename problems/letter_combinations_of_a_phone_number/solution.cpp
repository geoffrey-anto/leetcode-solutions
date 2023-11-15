class Solution {
public:
    void solve(unordered_map<char, vector<char>> &mp, int idx, string &digits, int n, vector<string> &ans, string ds) {
        if(ds.size() == n) {
            ans.push_back(ds);
            return;
        }

        for(int i=idx; i<n; i++) {
            for(int j=0; j<mp[digits[i]].size(); j++){
                solve(mp, i+1, digits, n, ans, ds+mp[digits[i]][j]);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        unordered_map<char, vector<char>> mp = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}}
        };
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};


        vector<string> ans;
        string ds;


        solve(mp, 0, digits,digits.size(), ans, ds);

        return ans;
    }
};