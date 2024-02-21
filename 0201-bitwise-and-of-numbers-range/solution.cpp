class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int diff = right - left;

        if(!diff) {
            return left;
        }

        bitset<32> l(left);
        bitset<32> r(right);

        bitset<32> res(0);
        int x = 31;

        for(int i=31; i>=0; i--) {
            if(l[i] == r[i]) {
                res[x] = l[i];
                x--;
            } else {
                break;
            }
        }

        return res.to_ulong();
    }
};
