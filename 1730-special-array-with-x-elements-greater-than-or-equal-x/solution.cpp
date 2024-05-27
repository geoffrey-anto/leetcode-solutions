class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = 1000;

        sort(begin(nums), end(nums));

        while(l <= r) {
            int m = (l+r) / 2;

            int sz = (int)(lower_bound(begin(nums), end(nums), m) - nums.begin());
            // cout << sz << " " << m << endl;

            if((n - sz) == m) {
                return m;
            }

            if(m < n - sz) {
                l = m+1;
            } else {
                r = m-1;
            }            
        }

        return -1;
    }
};
