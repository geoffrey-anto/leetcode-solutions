class Solution {
public:
    int MOD = 1e9 + 7;

    int f(int n) {
        int ans = 0;

        ans = ((long long)(n) * ((long long)(n) + 1ll) / 2ll) % MOD;
        
        return ans;
    }

    int numSub(string s) {
        int curr = 0;
        int ans = 0;

        for(auto i: s) {
            if(i == '0') {
                if(curr != 0) {
                    ans += f(curr);
                }

                curr = 0;
            } else {
                curr++;
            }
        }

        if(curr != 0) {
            ans += f(curr);
        }

        return ans;
    }
};
