class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int mx = 0;

        for(auto i: nums) {
            if(i > 0) {
                int flg = false;

                for(auto j: nums) {
                    if(j < 0 and i == (j * -1)) {
                        flg = true;
                        break;
                    }
                }

                if(flg) {
                    mx = max(mx, i);
                }
            }
        }

        if(mx == 0) {
            return -1;
        }

        return mx;
    }
};
