class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int c = 9;

        if(n == 0) {
            return 1;
        }

        if(n == 1) {
            return 10;
        }

        int x = 9;
        n--;
        int ans = 0;
        while(n--) {
            c = c * (x);
            ans += c;
            x--;
        }

        return ans + 10;
    }
};
