class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto i: nums) {
            map[i]++;
        }

        int mx = 0;
        int mxF = 0;

        for(auto &[k, v]: map) {
            if(v > mx) {
                mx = v;
                mxF = v;
            } else if(v == mx) {
                mxF += v;
            } else {
                continue;
            }
        }

        return mxF;
    }
};
