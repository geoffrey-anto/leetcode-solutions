class Solution {
public:
    template <size_t N>
    std::bitset<N> increment ( std::bitset<N> in ) {
        for ( size_t i = 0; i < N; ++i ) {

            if ( in[i] == 0 ) { 
                in[i] = 1;
                break;
             }

            in[i] = 0;  
        }
        return in;
    }
    int numSteps(string s) {
        bitset<501> b(s);

        int cnt = 0;

        while(b != 1) {
            if(b.test(0) == 1) {
                b = increment(b);
            } else {
                b >>= 1;
            }
            cnt++;
        }

        return cnt;
    }
};
