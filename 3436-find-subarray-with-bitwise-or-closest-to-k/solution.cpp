#define ll long long

class Solution {
public:
    long long getValue(vector<int> &v) {
        long long ans = 0;

        for(int i=0; i<32; i++) {
            if(v[i] == 0) {
                ans += pow(2, i);
            }
        }

        return ans;
    }

    int minimumDifference(vector<int>& nums, int k) {
        // the more we AND the more the value decreases
        // maybe sliding window approach

        // try to find 

        // int n = nums.size();
        // vector<int> pre(n, 0);
        // pre[0] = nums[0];

        // for(int i=1; i<nums.size(); i++) {
        //     pre[i] = (pre[i-1] & nums[i]);
        // }

        // for(auto i: pre) {
        //     cout << i << endl;
        // }

        // cout << endl;

        int high = *max_element(nums.begin(), nums.end());
        
        if(k >= high)
            return k - high;
        
        vector<int> fr(32, 0);


        vector<int> v(32, 0);

        int n = nums.size();

        int l = 0;
        int r = 1;

        long long ans = LLONG_MAX;


        for(int i=0; i<32; ++i) {
            if( !((nums[0]>>i) & 1) )
                v[i]++;
        }  

        long long curr = nums[0];

        if(n == 1) {
            return abs(k - curr);
        }

        while(r < n) {
            ans = min(ans, abs(curr - k));

            if(curr == k) {
                return 0;
            }

            while(curr > k and r < n) {
                for(int i=0; i<32; ++i) {
                    if( !((nums[r]>>i) & 1) )
                        v[i]++;
                } 

                curr = getValue(v);

                ans = min(ans, abs(curr - k));
                r++;
            }

            while(curr < k and l < r) {
                for(int i=0; i<32; ++i) {
                    if( !((nums[l]>>i) & 1) )
                        v[i]--;
                } 

                curr = getValue(v);

                ans = min(ans, abs(curr - k));
                l++;
            }
        } 


        return ans;
    }
};
