class Solution {
public:
    void f(long long n, vector<bool> &prime) {
        for (long long p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (long long i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }

    int nonSpecialCount(long long l, long long r) {
        long long ans = 0;

        long long n = sqrt(r);
        
        vector<bool> prime(n+10, true);
        prime[0] = false;
        prime[1] = false;
        
        f(n+1, prime);

        for(long long i=ceil(sqrt(l)); i<=n; i++) {
            if(prime[i]) {
                ans++;
            }
        }

        return r - l + 1 - ans; 
    }
};
