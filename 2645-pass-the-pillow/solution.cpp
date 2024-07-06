class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = 1;

        while(true) {
            while(time > 0 and ans < n) {
                ans++;
                time--;
            } 

            while(time > 0 and ans > 1) {
                ans--;
                time--;
            }

            if(time == 0) {
                return ans;
            }
        }

        return ans;
    }
};
