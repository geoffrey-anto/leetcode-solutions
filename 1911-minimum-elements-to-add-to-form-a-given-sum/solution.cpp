class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = accumulate(begin(nums), end(nums), 0ll);
        return (abs((long long)goal-(long long)sum)+(long long)limit-1ll) / (long long)limit;
    }
};
