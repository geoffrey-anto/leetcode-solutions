class Solution {
public:
    int subtractProductAndSum(int n) {
        int sm=0;
        int pr=1;
        while(n){
            int r=n%10;
            sm+=r;
            pr*=r;
            n=n/10;
        }
        return pr-sm;
    }
};