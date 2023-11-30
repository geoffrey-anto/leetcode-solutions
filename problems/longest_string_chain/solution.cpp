class Solution {
public:
    bool cmp(string &a, string &b) {
        if(a.size() != b.size()+1) {
            return false;
        }

        int i=0, j=0;

        while(i < a.size()) {
            if(a[i] == b[j]) {
                j++;
            }
            i++;
        }

        if(i == a.size() && j == b.size()) return true;

        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int mx = 1;
        sort(words.begin(), words.end(), [&](auto &a, auto &b) {
            return a.size() < b.size();
        });
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(cmp(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            mx = max(mx, dp[i]);
        }

        return mx;
    }
};