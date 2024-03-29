class Solution {
public:
    int integerBreak(int n) {
        if(n == 1) {
            return 1;
        }

        if(n == 2 || n == 3) {
            return n-1;
        }



        int sum = n;

        long long p = 1;

        while(sum > 4) {
            sum -= 3;
            p *= 3;
        }

        return sum * p;
    }
};
