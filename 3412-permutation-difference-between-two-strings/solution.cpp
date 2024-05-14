class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            ans += abs(i - (int)(find(begin(t), end(t), s[i]) - t.begin()));
        }

        return ans;
    }
};
