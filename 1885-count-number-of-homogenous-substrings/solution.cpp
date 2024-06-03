class Solution {
public:
    int MOD = 1e9 + 7;

    int sum(int n) {
        return ((((long long)n * (long long)(n+1))) / 2) % MOD;
    }

    int countHomogenous(string s) {
        int ans = 0;

        int n = s.size();

        int prev = s[0];
        int curr = 1;

        s+="X";

        for(int i=1; i<n+1; i++) {
            if(prev != s[i]) {
                ans += sum(curr);
                prev = s[i];
                curr = 1;
            } else {
                curr++;
            }
        }

        return ans;
    }
};
