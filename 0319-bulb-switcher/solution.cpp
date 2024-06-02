class Solution {
public:
    int bulbSwitch(int n) {
        // 0 3 2 1
        // 0 5 3 2 2 1
        // 0 10 5 no

        if(n == 0) {
            return 0;
        }

        return (sqrt(n));
    }
};
