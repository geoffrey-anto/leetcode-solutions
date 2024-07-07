class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while(numBottles >= numExchange) {
            int d = numBottles / numExchange;
            int m  = numBottles % numExchange;

            numBottles = d + m;
            ans += (d);
        }

        return ans;
    }
};
