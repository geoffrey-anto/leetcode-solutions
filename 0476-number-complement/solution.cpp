class Solution {
public:
    int findComplement(int num) {
        // bool f = false;

        // int ans = 0;

        // for(int i=31; i>=0; i--) {
        //     if(num & (1 << i)) {
        //         f = true;
        //     }

        //     if(f) {
        //         ans |= ((num & (1 << i)) ? 0 : 1);
        //     }
        // }

        // return ans;

        unsigned mask = ~0;
        while( mask & num ) mask = mask << 1;
        return ~num ^ mask;
    }
};
