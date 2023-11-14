// Stack Overflow TOO LARGE!
// class Solution {
// public:
//     int NO_OF_PRIME = 4*4;
//     int NO_OF_EVEN = 5;
//     int MOD = 1e9+7;
//     int countGoodNumbers(long long n) {
//         if(n==1) {
//             return 5;
//         }

//         return (n%2==0 ? (long long)(4l*(long long)countGoodNumbers(n-1))%MOD : (long long)(5l*(long long)countGoodNumbers(n-1))%MOD);
//     }
// };

class Solution {
public:
    int MOD = 1e9+7;

    long long pow (long long base, long long n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return base;
        int tmp = (base*base) % MOD;
        if (n%2 == 1)
        {
            return (base* pow (tmp, n/2)) %MOD;
        }
        else
        {
            return pow (tmp, n/2);
        }
    }

    int countGoodNumbers(long long n) {

        // for(int i=0; i<n; i++) {
        //     if(i%2 == 0) {
        //         ans = ((long long)ans * 5ll)%MOD;
        //     } else {
        //         ans = ((long long)ans * 4ll)%MOD;
        //     }
        // }

        long long c1 = n/2;
        long long c2 = n - c1;

        return (pow(4ll, c1) * pow(5ll, c2))%MOD;

    }
};