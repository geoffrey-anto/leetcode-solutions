class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        const int n = (int)nums.size();
        // bitset<(const int)(1e5+1)> b;

        // for(int i=0; i<n; i++) {
        //     if(nums[i]) b.set(i);
        // }

        // int ans = 0;
        // int flipped = 0;

        // for(int i=0; i<n-k+1; i++) {
        //     if(flipped > 0) {
        //         flipped--;
        //     }

        //     if(!b.test(i) and flipped <= 0 or b.test(i) and flipped > 0) {
        //         flipped = k - 1;
        //         ans++;
        //         b.set(i);
        //     }
        // }

        // return b.count() == n ? ans : -1;

        vector<int> f(n, 0);
        int ans = 0;
        int flip = 0;

        for(int i=0; i<n; i++) {
            if(i >= k) {
                flip -= f[i - k];
            }

            if((nums[i] == 1 and flip%2 == 1) or (nums[i] == 0 and flip%2 == 0)) {
                if(i + k > n) return -1;
                ans++;
                flip++;
                f[i]=1;
            } 
        }

        return ans;
    }
};
