class Solution {
public:
    int SieveOfEratosthenes(int n)
    {
        int cnt = 0;
        bool prime[n];
        memset(prime, false, sizeof(prime));
    
        for (long long p = 2; p < n; p++) {
            if (prime[p] == false) {
                cnt++;
                for (long long i = p * p; i < n; i += p) {
                    prime[i] = true;
                }
            }
        }
    
        return cnt;
    }
    int countPrimes(int n) {
        if(n == 0) {
            return 0;
        }
        return SieveOfEratosthenes(n);
    }
};
