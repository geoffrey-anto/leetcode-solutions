class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        vector<int> nums(n+1, 0);
        vector<int> ans(q.size(), 0);
        int j = 0;
        int a = 0;

        for(auto &i: q) {
            int &idx = i[0];
            int &color = i[1];

            if(nums[idx] != 0 && idx-1 >= 0 && nums[idx-1] == nums[idx]) {
                a--;
            }

            if(nums[idx] != 0 && idx+1 < n && nums[idx+1] == nums[idx]) {
                a--;
            }

            nums[idx] = color;
            
            if (idx-1 >= 0 && nums[idx-1] == color) {
                a++;
            }

            if (idx+1 < n && nums[idx+1] == color) {
                a++;
            }

            ans[j] = a;

            j++;
        }

        return ans;
    }
};
