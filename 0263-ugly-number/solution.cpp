class Solution {
public:
    bool isUgly(int n) {
        // if(n <= 0) {
        //     return false;
        // }

        // if(n == 1) {
        //     return true;
        // }

        // vector<bool> primes(n, false);

        // for(int i=2; i<n; i++) {
        //     if(primes[i] == false) {
        //         for(int j=i*i; j<n; j += i) {
        //             primes[j] = true;
        //         }
        //     }
        // }


        // for(auto i=6; i<n; i++) {
        //     if(primes[i] == false && n % i == 0) {
        //         return false;
        //     }
        // }

        // return true;

        if(n <= 0) return false;

        while(n>1) {
            if(n%2 == 0) {
                n /= 2;
            } else if(n%3 == 0) {
                n /= 3;
            } else if(n%5 == 0) {
                n /= 5;
            } else {
                break;
            }
        }

        return n == 1;
    }
};
