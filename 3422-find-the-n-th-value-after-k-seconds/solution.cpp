class Solution {
public:
    int MOD = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<long long> prefix(n, 1);

        while(k--) {
            for(int i=1; i<n; i++) {
                prefix[i] = (prefix[i] + prefix[i-1]) % MOD;
            }
        }

        return prefix[n-1];
    }
};
