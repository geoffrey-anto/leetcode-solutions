class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        int ans = 0;
        for(auto i: s) {
            long long curr = i;
            int c = 0;
            while(s.find(curr) != s.end()) {
                c++;
                if(curr * curr > 1e5) {
                    break;
                }
                curr = curr * curr;
            }

            ans = max(ans, c);
        }

        if(ans  < 2) {
            return -1;
        }

        return ans;
    }
};
