class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // int pos = 0;
        // int neg = 0;

        // for(auto i: nums) {
        //     if(i < 0) {
        //         neg++;
        //     } else if(i > 0) {
        //         pos++;
        //     }
        // }

        // return max(neg, pos);

        return max((int)(lower_bound(begin(nums), end(nums), 0)-begin(nums)),(int)(nums.size() - (int)(upper_bound(begin(nums), end(nums), 0) - nums.begin())));
    }
};

