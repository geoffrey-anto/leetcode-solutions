template <typename T>
void print(T arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        // print(nums);
        
        int n = nums.size();
        
        int mid = n / 2;
        
        if(k == nums[mid]) {
            return 0;
        }
        
        long long ans = 0ll;
        
        if(k > nums[mid]) {
            long long prev = INT_MAX;
            for(int i=mid; i<n; i++) {
                if(nums[i] >= prev) {
                    break;
                }
                
                if(k <= nums[i]) {
                    break;
                }
                
                long long diff = k - nums[i];
                
                ans += diff;
                
                prev = k;
            }
        } else if(k < nums[mid]) {
            long long prev = INT_MIN;
            for(int i=mid; i>=0; i--) {
                if(nums[i] <= prev) {
                    break;
                }
                
                if(k >= nums[i]) {
                    break;
                }
                
                long long diff = nums[i] - k;
                
                ans += diff;
                
                prev = k;
            }
        } 
        
        return ans;
    }
};
