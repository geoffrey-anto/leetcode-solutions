class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int lastRep = 0;
        int n = s.size();
        int r = 1;
        int l = 0;
        char prevCh = s[0];

        if(n == 1) {
            return 1;
        }

        int ans = 0;

        while(r < n) {
            if(s[r] == prevCh) {
                l = lastRep;
                lastRep=r;
            }

            prevCh = s[r];
            r++;
            ans = max(ans, r - l);
        }

        return ans;
    }
};
