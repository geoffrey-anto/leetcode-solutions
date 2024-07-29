class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);

        int s = 0;

        for(auto i: nums) {
            if(i <= 9) {
                s += i;
            } 
        }

        if(s+s == sum) {
            return false;
        }

        return true;
    }
};
