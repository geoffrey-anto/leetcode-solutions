class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        for (int i = 0, cons = 1; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1] + 1)
                ++cons;
            else
                cons = 1;
            if (i + 1 >= k)
                res.push_back(cons >= k ? nums[i] : -1);
        }
        return res;
    }
};
