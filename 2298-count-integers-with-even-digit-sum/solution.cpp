class Solution {
public:
    int sum(int n) {
        int s = 0;

        while(n) {
            s += n%10;
            n /= 10;
        }

        return s;
    }

    int countEven(int num) {
        int ans = 0;

        for(int i=1; i<=num; i++) {
            if(sum(i) % 2 == 0) {
                ans++;
            }
        }

        return ans;
    }
};
