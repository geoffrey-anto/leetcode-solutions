class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = accumulate(begin(nums1), end(nums1), 0ll);

        long long s2 = accumulate(begin(nums2), end(nums2), 0ll);

        long long cnt1 = 0;
        long long cnt2 = 0;

        for(auto i: nums1) {
            if(i == 0) {
                cnt1++;
            }
        }

        for(auto i: nums2) {
            if(i == 0) {
                cnt2++;
            }
        }

        long long sn1 = cnt1 + s1;
        long long sn2 = cnt2 + s2;

        if(sn1 > sn2 and cnt2 == 0) {
            return -1ll;
        }

        if(sn2 > sn1 and cnt1 == 0) {
            return -1ll;
        }

        return max(sn1, sn2);
    }
};
