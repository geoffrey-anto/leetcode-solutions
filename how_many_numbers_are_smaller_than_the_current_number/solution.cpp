class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      unordered_map<int, int> m;
      vector<int> new_nums(nums);
      int n = nums.size();
      
      sort(new_nums.begin(), new_nums.end());
      
      for (int i = n - 1; i >= 0; --i) {
        m[new_nums[i]] = i;
      }
      
      for (int i = 0; i < n; ++i) {
        nums[i] = m[nums[i]];
      }
      return nums;
    }
};

