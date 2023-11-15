class Solution {
public:
    bool isPaindrome(string s) {
        string rev = "";
        for(auto i: s) {
            rev = i + rev;
        }

        return rev == s;
    }

    void solve(int idx, int n, string &s, vector<vector<string>> &ans, vector<string> &ds) {
        if(idx == n) {
            ans.push_back(ds);
            return;
        }

        for(int i=1; i<=n-idx; i++) {
            if(isPaindrome(s.substr(idx, i))) {
                ds.push_back(s.substr(idx, i));
                solve(idx+i, n, s, ans, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;

        solve(0, s.length(), s, ans, ds);

        return ans;
    }
};
