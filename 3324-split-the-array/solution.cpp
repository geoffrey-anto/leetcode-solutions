class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int count[101];
        
        for(auto i: nums) {
            count[i]++;
            if(count[i] > 2) {
                return false;
            }
        }
        
        return true;
    }
};
