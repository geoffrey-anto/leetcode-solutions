# Freedom Trail

## Leetcode Link: [Freedom Trail](https://leetcode.com/problems/freedom-trail/)
### Language: C++

```cpp
class Solution {
public:
    int dp[101][101];

    int f(int pos, int k, string &ring, string &key) {

        if(k == key.size()) {
            return 0;
        }

        int ans = 1e6;

        int n = ring.size();

        if(dp[pos][k] != -1 and dp[pos][k] != 0) return dp[pos][k];

        // if(ring[pos] == key[0]) {
        //     ans += 1 + f(pos, ring, key.substr(1));
        // } else {
            // take pos of key[0] from left ans right and recursively procced to take min of the 2

            // int l = pos; int r = pos;

            // int cnt1 = 0;
            // int cnt2 = 0;

            // while(true) {
            //     if(ring[l] == key[0]) {
            //         break;
            //     }
            //     cnt1++;

            //     l--;
            //     if(l < 0) {
            //         l = ring.size()-1;
            //     }
            // }

            // while(true) {
            //     if(ring[r] == key[0]) {
            //         break;
            //     }
            //     cnt2++;

            //     r++;
            //     if(r == ring.size()) {
            //         r = 0;
            //     }
            // }

            // ans += 1 + min((cnt1 + f(l, ring, key.substr(1))), (cnt2 + f(r, ring, key.substr(1))));

            // printf("in: %d, need %c, cnt1: %d, cnt2: %d  -> took: %d\n", pos, key[0], cnt1, cnt2, ans);

            int lim = 0;

            // try out all the possible values of the same character to get the best via dp
            for(int i=pos; lim < n; i++, lim++) {
                i %= n;

                if(ring[i] == key[k]) {
                    int cost = min(lim, n - lim) + 1;
                    int v = cost + f(i, k+1, ring, key);
                    ans = min(ans, v);
                }
            }
        // }

        return dp[pos][k] = ans;
    }
    int findRotateSteps(string ring, string key) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, ring, key);
    }
};```



