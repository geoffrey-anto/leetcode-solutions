class Solution {
public:
    void solve(int i, int n, int open, int closed, vector<string> &ans, string s) {
        if(i >= n*2) {
            return ans.push_back(s);
        }

        if(open < n) {
            solve(i+1, n, open+1, closed, ans, s+'(');
        } 
        if(closed < open) {
            solve(i+1, n, open, closed+1, ans, s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, n, 0, 0, ans, "");
        return ans;

    }
};
