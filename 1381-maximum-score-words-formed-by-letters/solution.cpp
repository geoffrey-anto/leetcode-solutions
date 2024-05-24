class Solution {
public:
    int getCost(string &str, unordered_map<char, int> cnt, vector<int>& s) {
        int cost = 0;

        for(auto &i: str) {
            if(cnt[i] > 0) {
                cost += s[i - 'a'];
                cnt[i]--;
            } else {
                return -1;
            }
        }

        return cost;
    }

    int f(int i, vector<string>& words, unordered_map<char, int> &cnt, vector<int>& s, vector<int> dp) {
        if(i == words.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int nt = 0;
        int t = 0;

        nt = f(i+1, words, cnt, s, dp);

        int cost = getCost(words[i], cnt, s);

        if(cost != -1) {
            for(auto &j: words[i]) {
                cnt[j]--;
            }
            t = cost + f(i+1, words, cnt, s, dp);
            for(auto &j: words[i]) {
                cnt[j]++;
            }
        }

        return dp[i] = max(t, nt);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> cnt;

        for(auto i: letters) {
            cnt[i]++;
        }

        vector<int> dp(words.size()+1, -1);

        return f(0, words, cnt, score, dp);
    }
};
