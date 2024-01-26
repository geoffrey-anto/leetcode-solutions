class Solution {
public:
    bool check(int mid,vector<int> &nums,int k){
        int total=0;
        int j=0,n=nums.size();
        for(int i=0;i<n;i++){
            while(j<n && nums[j]-nums[i]<=mid)j++;
            j--;
            total+=(j-i);
        }
        return total>=k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int mx = *max_element(begin(nums), end(nums));
        int mn = *min_element(begin(nums), end(nums));
        sort(nums.begin(), nums.end());

        int maxDiff = mx - mn;

        int l = 0;
        int r = maxDiff;
        int ans = 0;

        while(l < r) {
            int m = l + (r-l)/2;

            if(check(m, nums, k)) {
                r = m;
            } else {
                l = m+1;
            }
        }

        return l;
    }
};
