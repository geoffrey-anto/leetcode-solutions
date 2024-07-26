class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;

        for(int i=0; i<32; i++) {
            bool a = (n & (1 << i)) != 0;
            bool b = (k & (1 << i)) != 0;

            if(a == b) {
                continue;
            }

            if(a == 1 and b == 0) {
                ans++;
            }

            if(a == 0 and b == 1) {
                return -1;
            }
        }

        return ans;
    }
};
