class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;

        for(auto i: answers) {
            mp[i]++;
        }

        int ans = 0;

        for(auto &[k, v]: mp) {
            ans += ((ceil((double)v / (k + 1)) * (k + 1)));
        }

        return ans;
    }
};
