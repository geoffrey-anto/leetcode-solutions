class Solution {
public:
    unordered_map<char, vector<char>> v;
    int MOD = 1e9 + 7;

    int f(int i, char prev, int n, vector<vector<int>> &dp) {
        if(i == n) {
            return 1;
        }

        if(dp[i][prev == ' ' ? 0 : (prev-'a')+1] != -1) return dp[i][prev == ' ' ? 0 : (prev-'a')+1];

        long long ans = 0;

        for(auto next: v[prev]) {
            ans = (ans + f(i+1, next, n, dp)) % MOD;
        }

        return dp[i][prev == ' ' ? 0 : (prev-'a')+1] = ans;
    }

    int countVowelPermutation(int n) {
        v[' '].push_back('a');
        v[' '].push_back('e');
        v[' '].push_back('i');
        v[' '].push_back('o');
        v[' '].push_back('u');

        v['a'].push_back('e');
        v['e'].push_back('a');
        v['e'].push_back('i');
        v['i'].push_back('a');
        v['i'].push_back('e');
        v['i'].push_back('o');
        v['i'].push_back('u');
        v['o'].push_back('i');
        v['o'].push_back('u');
        v['u'].push_back('a');

        vector<vector<int>> dp(n+1, vector<int>(27, -1));

        return f(0, ' ', n, dp);
    }
};
