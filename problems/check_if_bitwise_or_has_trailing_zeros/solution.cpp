class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int c1 = 0;
        
        for(auto i: nums) {
            if(i%2 == 0) {
                c1++;
            }
            
            if(c1 >= 2) {
                return true;
            }
        }
        
        return false;
    }
};