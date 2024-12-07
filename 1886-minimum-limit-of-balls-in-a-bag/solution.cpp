class Solution {
public:
    int f(vector<int> &v, int maxOp, int m) {
        int ans = 0;

        for(auto i: v) {
            ans += (i - 1) / m;

            if(ans > maxOp) {
                break;
            }
        }

        return ans;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(begin(nums), end(nums));

        while(l < r) {
            int m = l + (r - l) / 2;

            int res = f(nums, maxOperations, m);

            if(res <= maxOperations) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return r;
    }
};
