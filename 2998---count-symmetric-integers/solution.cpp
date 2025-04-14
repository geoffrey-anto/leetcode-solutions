class Solution {
private:
    int count(int n) {
        int c = 0;

        while(n != 0) {
            c ++;

            n /= 10;
        }

        return c;
    }

    bool isSymmetric(int x, int c) {
        if(c % 2 != 0) {
            return false;
        }

        int l = 0, r = 0;

        for(int i=0; i<c; i++) {
            if(i < c / 2) {
                l += x % 10;
            } else {
                r += (x % 10);
            }

            x /= 10;
        } 

        return l == r;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        while(low <= high) {
            ans += (int) (isSymmetric(low, count(low)));
            low++;
        }

        return ans;
    }
};
