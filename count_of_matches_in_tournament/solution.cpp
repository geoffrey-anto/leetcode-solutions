class Solution {
public:
    int numberOfMatches(int n) {
        int i=0;
        while(n>1){
            if(n%2==0){
                i+=n/2;
                n/=2;
            } else {
                i+=(n-1)/2;
                n = (n-1)/2 + 1;
            }
        }
        return i;
    }
};