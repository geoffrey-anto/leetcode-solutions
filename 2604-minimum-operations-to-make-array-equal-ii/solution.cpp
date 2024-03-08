class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long ans = 0ll;
        
        long long decs = 0, incs = 0;
        
        for(int i=0; i<n; i++) {
            int diff = (nums1[i] - nums2[i]);
            if(k == 0 && diff != 0) {
                return -1;
            }
            
            if(diff == 0) {
                continue;
            }
            
            if(abs(diff) % k != 0) {
                return -1;
            }
            
            if(diff < 0) {
                incs += abs(diff)/k;
            } else {
                decs += diff/k;
            }
        }
        
        return incs != decs ? -1 : incs;
    }
};
