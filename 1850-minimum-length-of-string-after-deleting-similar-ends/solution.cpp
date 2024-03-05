class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;

        while(l < r) {
            if(s[l] != s[r]) {
                return r - l + 1;
            }

            while(l < n-1 && s[l] == s[l+1]) l++;
            while(r > 0 && s[r] == s[r-1]) r--;


            l++;
            r--;
        }

        if(l == r) {
            return 1;
        }

        return 0;
    }
};
