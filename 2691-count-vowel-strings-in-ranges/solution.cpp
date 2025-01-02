class Solution {
public:
    int check(string &s) {
        auto f = [](char c) {
            return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c =='u';
        };

        return f(s[0]) == true and f(s[s.size() - 1]) == true;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int> preSum(n+1, 0);

        for(int i=0; i<n; i++) {
            preSum[i + 1] = preSum[i] + check(words[i]);  
        }

        vector<int> ans;

        for(auto q: queries) {
            int curr = preSum[q[1] + 1] - preSum[q[0]];
            ans.push_back(curr);
        }

        return ans;
    }
};
