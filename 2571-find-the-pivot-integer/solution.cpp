class Solution {
public:
    int sum(int n) {
        return (n * (n+1)/2);
    }
    int pivotInteger(int n) {
        for(int i=1; i<=n; i++) {
            int lsum = sum(i);

            int rsum = sum(n)-lsum + i;

            if(lsum == rsum) {
                return i;
            }
        }

        return -1;
    }
};
