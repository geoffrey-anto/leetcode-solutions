class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int l = 0;
                int k = 0;
                int prevDiff = INT_MAX;
                
                bool flg = false;
                
                while(l < n or k < nums2.size()) {
                    if(l == i or l == j) {
                        l++;
                    } else {
                        if(prevDiff == INT_MAX){
                            prevDiff = nums2[k] - nums1[l];
                        } else {
                            if(nums2[k] - nums1[l] != prevDiff) {
                                flg = true;
                                break;
                            }
                        }
                        l++;
                        k++;
                    }
                }
                
                if(!flg) {
                    return prevDiff;
                }
            }
        }
        
        return 0;
    }
};
