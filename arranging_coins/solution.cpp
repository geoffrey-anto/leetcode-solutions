class Solution {
public:
    int arrangeCoins(int n) {
        long ans = n;
        return (sqrt(2*ans+0.25)-0.5);
    }
};