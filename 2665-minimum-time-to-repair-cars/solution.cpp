class Solution {
public:
    bool f(vector<int>& ranks, int cars, long long m) {
        long long ans = 0;

        for(int i=0; i<ranks.size(); i++) {
            int rank = ranks[i];
            // r * n^2 <= m
            // n^2 <= m / r
            // n <= sqrt(m / r);

            long long n = sqrt(m / rank);

            ans += n;

            if(ans >= cars) {
                return true;
            }
        }

        return ans >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        sort(begin(ranks), end(ranks));
        long long l = 1;
        long long r = (long long)ranks[ranks.size() - 1] * (long long)(pow(cars, 2));
        long long ans = -1;
        while(l <= r) {
            long long m = (l + (r - l) / 2);

            if(f(ranks, cars, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        } 

        return ans;
    }
};
