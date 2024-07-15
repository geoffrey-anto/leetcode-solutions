class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        sort(begin(nums), end(nums));
        
        do {
            ans.insert(nums);
        } while(next_permutation(begin(nums), end(nums)));

        return vector<vector<int>>(begin(ans), end(ans));
    }
};
