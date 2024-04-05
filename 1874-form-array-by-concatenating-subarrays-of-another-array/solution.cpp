class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size();
        int m = groups[0].size();

        auto start = begin(nums);

        for(int g = 0; g < n; g++) {
            // for(; it != nums.end(); it++) {
            //     if()
            // }

            auto curr = search(start, nums.end(), groups[g].begin(), groups[g].end());

            if(curr == nums.end()) {
                return false;
            } else {
                int sz = groups[g].size();

                start = curr + sz;
            }
        }

        return true;
    }
};
