class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        int ans1 = 0;
        int ans2 = 1;

        // case 1 : they are not swapped

        for(int i=n-2; i>=0; i--) {
            // case 1.1 : both are less than the last element so no swap
            // case 1.2 : one of them is lesses and after swap both are lesser
            // case 1.3 : not possible

            if(nums1[i] <= nums1[n-1] and nums2[i] <= nums2[n-1]) {
                continue;
            } else if(nums2[i] <= nums1[n-1] and nums1[i] <= nums2[n-1]) {
                ans1++;
            } else {
                return -1;
            }
        }

        // case 2

        swap(nums1[n-1], nums2[n-1]);

        for(int i=n-2; i>=0; i--) {
            // case 1.1 : both are less than the last element so no swap
            // case 1.2 : one of them is lesses and after swap both are lesser
            // case 1.3 : not possible

            if(nums1[i] <= nums1[n-1] and nums2[i] <= nums2[n-1]) {
                continue;
            } else if(nums2[i] <= nums1[n-1] and nums1[i] <= nums2[n-1]) {
                ans2++;
            } else {
                return -1;
            }
        }

        return min(ans1, ans2);
    }
};
