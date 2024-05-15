#define it(a) begin(a), end(a)
class Solution {
public:
    bool f(vector<int>& nums, int k,int mid) {
        int i=0;
        int n=nums.size();

        while(i<n) {
            if(nums[i]<=mid){
                k--, i+=2;
            } else {
                i++;
            }
            
            if(k == 0) return true;
        }

        return k == 0;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int l = *min_element(it(nums));
        int r = *max_element(it(nums));

        while(l < r) {
            int m = (l+r)/2;

            if(f(nums, k, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }

        return l;
    }
};
