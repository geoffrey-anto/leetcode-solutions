class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        
        int cpy = x;
        
        while(cpy) {
            s += cpy  % 10;
            cpy /= 10;
        }
        
        if(x % s == 0) {
            return s;
        } else {
            return -1;
        }
    }
};
