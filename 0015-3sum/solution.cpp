class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(begin(nums), end(nums));
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int l = i+1;
            int h = n-1;

            int sum = 0;

            while(l < h) {
                sum = nums[i] + nums[l] + nums[h];

                if(sum == 0) {
                    ans.insert({nums[i], nums[l], nums[h]});
                    l++;
                    h--;
                } else if(sum < 0) {
                    l++;
                } else {
                    h--;
                }
            }
        }

        vector<vector<int>> v;

        for(auto i:ans) {
            v.push_back(i);
        }

        return v;
    }
};
