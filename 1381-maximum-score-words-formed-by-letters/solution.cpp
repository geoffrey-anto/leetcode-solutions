class Solution {
public:
    int getScore(string s, unordered_map<char, int> letters, vector<int>& score) {
        int ans = 0;

        for(auto &i: s) {
            if(letters[i] == 0) {
                return -1;
            }

            letters[i]--;

            ans += score[i-'a'];
        }

        return ans;
    }

    int f(int i, vector<string>& words, unordered_map<char, int> letters, vector<int>& score, int n) {
        if(i == n) {
            return 0;
        }

        int take = -1e8;

        int notTake = f(i+1, words, letters, score, n);

        int s = getScore(words[i], letters, score);

        if(s != -1) {
            for(auto &i: words[i]) {
                letters[i]--;
            }

            take = s + f(i+1, words, letters, score, n);
        }

        return max(notTake, take);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> mp;

        for(auto &i: letters) {
            mp[i]++;
        }

        return f(0, words, mp, score, words.size());
    }
};
