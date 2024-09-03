class Solution {
public:
    int getSum(string s) {
        int ans = 0;
        for(auto i: s) {
            ans += sumDigits((i - 'a') + 1);
        }

        return ans;
    }

    int sumDigits(int n) {
        int ans = 0;

        while(n) {
            ans += (n % 10);
            n /= 10;
        }

        return ans;
    }

    int getLucky(string s, int k) {
        int curr = getSum(s);
        k--;

        while(k) {
            curr = sumDigits(curr);
            k--;
        }

        return curr;
    }
};
