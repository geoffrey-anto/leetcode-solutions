class Solution {
public:
    bool prime(int n)
    {
        if (n <= 1)
            return false;
        for(int i = 2; i * i <= n; i++)
            if(n % i == 0)
                return false; 
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n-1;

        while(l < n) {
            if(prime(nums[l])) {
                break;
            }
            l++;
        }

        while(r >= 0) {
            if(prime(nums[r])) {
                break;
            }
            r--;
        }

        return r - l;
    }
};
