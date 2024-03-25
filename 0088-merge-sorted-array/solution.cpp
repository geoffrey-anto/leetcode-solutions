class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int> v;

        // int i=0, j=0;

        // while(i < m && j < n) {
        //     if(nums1[i] <= nums2[j]) {
        //         v.push_back(nums1[i]);
        //         i++;
        //     } else {
        //         v.push_back(nums2[j]);
        //         j++;
        //     }
        // }

        // while(i < m) {
        //     v.push_back(nums1[i++]);
        // }

        // while(j < n) {
        //     v.push_back(nums2[j++]);
        // }

        // for(int i=0; i<m; i++) {
        //     cout << v[i] << endl;
        //     nums1[i] = v[i];
        // }

        // return;

        int last = nums1.size() - 1;
        n--;
        m--;
        while(n >= 0) {
            if(m >= 0 && nums1[m] > nums2[n]) {
                nums1[last] = nums1[m];
                m--;
                last--;
            } else {
                nums1[last] = nums2[n];
                n--;
                last--;
            }
        }

    }
};
