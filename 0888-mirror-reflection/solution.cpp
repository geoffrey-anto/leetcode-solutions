class Solution {
public:
    int mirrorReflection(int p, int q) {
        return (p & -p) > (q & -q) ? 2 : (p & -p) < (q & -q) ? 0:1;
        
        int p_odd = p % 2 != 0;
        int q_odd = q % 2 != 0;

        if(p / q == 2 && p != q and q != 1) {
            return 2;
        }

        if(p_odd == q_odd) {
            return 1;
        }

        if(q_odd) {
            return 2;
        }

        return -1;
    }
};
