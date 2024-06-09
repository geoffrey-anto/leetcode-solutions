class Solution {
public:
    int numberOfChild(int n, int k) {
        
        int ans = 0;

        int i = 0;

        while(k > 0) {
            while(k > 0 and i < n-1) {
                i++;
                k--;

                if(k == 0) {
                    return i;
                }
            }

            while(k > 0 and i > 0) {
                i--;
                k--;

                if(k == 0) {
                    return i;
                }
            }
        }

        return 0;

    }
};
