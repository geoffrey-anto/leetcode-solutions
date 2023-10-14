class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        int mx = 0;
        
        vector<int> maxans;
        maxans.push_back(0);
        int prev = groups[0];
        
        for(int i=1; i<n; i++) {
            if(prev != groups[i]) {
                prev = groups[i];
                maxans.push_back(i);
            } else {
                prev = groups[i];
                continue;
            }
        }
        vector<string> ans;
        for(auto i: maxans) {
            ans.push_back(words[i]);
        }
        return ans;
    }
};
