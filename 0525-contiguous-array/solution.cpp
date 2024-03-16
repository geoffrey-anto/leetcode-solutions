class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> prev;

        for(int i=0; i<n; i++) {
            if(i == 0) {
                prev[i] = -1;
            }

            if(nums[i] == 0) {
                cnt--;
            } else {
                cnt++;
            }

            if(prev.count(cnt)) {
                int currDist = i - prev[cnt];

                if(currDist <= 0) {
                    continue;
                }

                if(currDist > ans) {
                    ans = currDist;
                }
                continue;
            }

            prev[cnt] = i;
        }

        return ans;
    }
};
