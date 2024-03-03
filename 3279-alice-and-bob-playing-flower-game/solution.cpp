class Solution {
public:
    long long flowerGame(int n, int m) {
        // long long cnt = 0;

        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=m; j++) {
        //         if((j & 1) or (i & i)) {
        //             cnt++;
        //         }
        //     }
        // }

        return ((long long)(n) * (long long)(m))/2ll;
    }
};
