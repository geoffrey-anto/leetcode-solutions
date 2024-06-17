class Solution {
public:
    bool judgeSquareSum(double c) {
        if(c == 0) {
            return true;
        }
        
        auto f = [&c](double b) {
            return sqrt(c - (pow(b, 2)));
        };

        for(double i=0; i<sqrt(c); i++) {
            auto a = f(i);

            if(ceil(a) == a) {
                return true;
            }
        }

        return false;
    }
};
