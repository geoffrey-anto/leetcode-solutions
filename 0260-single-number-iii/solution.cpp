class Solution {
public:
    unsigned countBits(unsigned int number) 
    {     
        return (int)log2(number)+1; 
    } 
    
    vector<int> singleNumber(vector<int>& nums) {
        int xo = 0;

        for(int i=0; i<nums.size(); i++) {
            xo = xo ^ nums[i];
        }   

        int no = countBits(xo);

        int can = 0;

        for(int i=0; i<no; i++) {
            if((xo & (1 << i)) != 0) {
                can = i;
            }
        }

        int x1 = 0;
        int x2 = 0;

        for(auto i: nums) {
            if((i & (1 << can)) != 0) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }

        return {min(x1, x2), max(x1, x2)};
    }
};
