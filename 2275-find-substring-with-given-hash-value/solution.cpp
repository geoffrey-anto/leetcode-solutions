class Solution {
public:
    int val(char a) {
        return (a - 'a') + 1;
    }
    string subStrHash(string s, int p, int mod, int k, int target) {
        long long curr = 0;
        long long n = s.size();
        long long x = 1; 

        vector<long long> hash(n);

        string r = s;

        reverse(begin(r), end(r));

        for (int i = 0; i < n; ++i) {
            if (i < k) x = x * p % mod;

            curr = (curr * p + (val(r[i]))) % mod; 

            if (i - k >= 0) {
                curr = (curr - (((val(r[i-k]))) * x) % mod + mod) % mod;
            }

            if (i >= k - 1) hash[i] = curr;
        }

        reverse(hash.begin(), hash.end());

        for (int i = 0; i < n; ++i) {
            if (hash[i] == target) {
                return s.substr(i, k);
            }
        }
        return "";
    }
};
